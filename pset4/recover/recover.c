#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
int current_index = 0;
int current_status = 0;

int main(int argc, char *argv[])
{
    if (argc != 2) //chekcs for cmd-line arguments
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    FILE *image = fopen(argv[1], "r"); //creates file pointer named by argv[1]
    if (image == NULL)
    {
        printf("Couldn't open the %s file.\n", argv[1]);
        return 1;
    }

    BYTE buffer[512]; //buffer for fread
    char outname[8];
    sprintf(outname, "%03i.jpg", current_index);

    FILE *output = fopen(outname, "w");
    if (output == NULL)
    {
        printf("Couldn't create output %s file.\n", outname);
        return 1;
    }

    while ((fread(buffer, sizeof(BYTE), 512, image)) == 512)
    {
        if (((current_index == 0) && (current_status == 0)) && ((buffer[0] == 0xFF) && (buffer[1] == 0xD8) && (buffer[2] == 0xFF)
                && ((buffer[3] & 0xE0) == 0xE0)))
        {
            fwrite(buffer, sizeof(BYTE), 512, output);
            current_status = 1;
            continue;
        }
        if (current_status == 1 && ((buffer[0] == 0xFF) && (buffer[1] == 0xD8) && (buffer[2] == 0xFF) && ((buffer[3] & 0xE0) == 0xE0)))
        {
            fclose(output);
            current_status = 0;
            current_index++;
            sprintf(outname, "%03i.jpg", current_index);
            output = fopen(outname, "w");
            if (output == NULL)
            {
                printf("Couldn't open %s file.", outname);
                return 1;
            }
            fwrite(buffer, sizeof(BYTE), 512, output);
            current_status = 1;
            continue;
        }
        if (current_status == 1 && (!((buffer[0] == 0xFF) && (buffer[1] == 0xD8) && (buffer[2] == 0xFF) && ((buffer[3] & 0xE0) == 0xE0))))
        {
            fwrite(buffer, sizeof(BYTE), 512, output);
            continue;
        }

    }
    if (current_status == 1)
    {
        fclose(output);
        current_status = 0;
    }

    fclose(image);
}