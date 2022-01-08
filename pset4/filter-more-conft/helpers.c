#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round(((float)image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    int iteration = 0;
    for (int i = 0; i < height; i++)
    {
        //fread(image[i], sizeof(RGBTRIPLE), width, inptr);  its already done in filter.c
        if (width % 2 == 0)
        {
            iteration = width / 2;
        }
        else
        {
            iteration = (width + 1) / 2;
        }
        for (int j = 0; j < iteration ; j++)
        {
            temp.rgbtBlue = image[i][j].rgbtBlue;
            temp.rgbtGreen = image[i][j].rgbtGreen;
            temp.rgbtRed = image[i][j].rgbtRed;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][width - j - 1].rgbtBlue = temp.rgbtBlue;
            image[i][width - j - 1].rgbtGreen = temp.rgbtGreen;
            image[i][width - j - 1].rgbtRed = temp.rgbtRed;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int average_red = 0, average_blue = 0, average_green = 0, operation_count = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = -1; k < 2; k++)
            {
                if (((i + k) >= 0) && (height - 1 >= (i + k))) // gotta think about touching memory.
                {
                    for (int m = -1; m < 2; m++)
                    {
                        if (((j + m) >= 0) && (width - 1 >= (j + m)))
                        {
                            average_red += image[i + k][j + m].rgbtRed;
                            average_blue += image[i + k][j + m].rgbtBlue;
                            average_green += image[i + k][j + m].rgbtGreen;
                            operation_count++;
                        }
                    }
                }

            }
            average_red = round(average_red / (float)operation_count);
            average_blue = round(average_blue / (float)operation_count);
            average_green = round(average_green / (float)operation_count);
            temp[i][j].rgbtRed = average_red;
            temp[i][j].rgbtBlue = average_blue;
            temp[i][j].rgbtGreen = average_green;
            operation_count = 0;
            average_red = 0;
            average_blue = 0;
            average_green = 0;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx_array[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}}, Gy_array[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    RGBTRIPLE temp[height][width];
    int Gx_Red = 0, Gy_Red = 0, Gx_Blue = 0, Gy_Blue = 0, Gx_Green = 0, Gy_Green = 0;
    long int sobel_red = 0, sobel_green = 0, sobel_blue = 0;
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = -1; k < 2; k++)
            {
                if (((i + k) >= 0) && (height - 1 >= (i + k))) // gotta think about touching memory.
                {
                    for (int m = -1; m < 2; m++)
                    {
                        if (((j + m) >= 0) && (width - 1 >= (j + m)))
                        {
                            Gx_Red = Gx_Red + ((Gx_array[k + 1][m + 1] * image[i + k][j + m].rgbtRed));
                            Gy_Red = Gy_Red + ((Gy_array[k + 1][m + 1] * image[i + k][j + m].rgbtRed));
                            Gx_Green = Gx_Green + ((Gx_array[k + 1][m + 1] * image[i + k][j + m].rgbtGreen));
                            Gy_Green = Gy_Green + ((Gy_array[k + 1][m + 1] * image[i + k][j + m].rgbtGreen));
                            Gx_Blue = Gx_Blue + ((Gx_array[k + 1][m + 1] * image[i + k][j + m].rgbtBlue));
                            Gy_Blue = Gy_Blue + ((Gy_array[k + 1][m + 1] * image[i + k][j + m].rgbtBlue));
                        }
                    }
                }

            }
            double s1_red = sqrt(((double)Gx_Red * Gx_Red) + ((double)Gy_Red * Gy_Red));
            double s1_green = sqrt((((double)Gx_Green * Gx_Green) + ((double)Gy_Green * Gy_Green)));
            double s1_blue = sqrt(((double)Gx_Blue * Gx_Blue) + ((double)Gy_Blue * Gy_Blue));
            sobel_red = round(s1_red);
            sobel_green = round(s1_green);
            sobel_blue = round(s1_blue);
            
            if (sobel_red > 255)
            {
                sobel_red = 255;
            }
            if (sobel_green > 255)
            {
                sobel_green = 255;
            }
            if (sobel_blue > 255)
            {
                sobel_blue = 255;
            }
            
            
        
            
            
            
            
            
            
            temp[i][j].rgbtRed = sobel_red;
            temp[i][j].rgbtBlue = sobel_blue;
            temp[i][j].rgbtGreen = sobel_green;
            Gx_Red = 0;
            Gy_Red = 0;
            Gx_Blue = 0;
            Gy_Blue = 0;
            Gx_Green = 0;
            Gy_Green = 0;
            sobel_red = 0;
            sobel_green = 0;
            sobel_blue = 0;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        }
    }
    return;
}
