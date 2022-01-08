#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int letters = 0, i = 0, words = 0, sentences = 0;
    float avg_letters = 0, avg_sentences = 0, grade = 0;

    string input = get_string("Text:");

    while (input[i] != '\0')
    {
        if ((input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122)) //checking for alphanumeric
        {
            letters++;
        }
        i++;
        if (input[i] == 32)
        {
            words++;
        }
        if (input[i] == 33 || input[i] == 46 || input[i] == 63)
        {
            sentences++;
        }
    }
    words = words + 1;
    avg_letters = 100 / (float) words;
    avg_letters *= letters;

    avg_sentences = 100 / (float) words;
    avg_sentences *= sentences;

    grade = ((0.0588) * avg_letters) - ((0.296) * avg_sentences) - (15.8);
    grade = round(grade);
    int grade_val = grade;
    //printf("letters:%i\n",letters);
    //printf("words:%i\n",words+1);
    //printf("sentences:%i\n",sentences);
    //printf("grade : %f\n",grade);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade_val);
    }


}
