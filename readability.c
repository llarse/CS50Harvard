#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_sentences(string text);
int count_words(string text);

int main(void)
{
    string text = get_string("Text: ");
    float L = count_letters(text);
    float S = count_sentences(text);
    float W = count_words(text);
    L = (L / W)*100; // creates avg letters/100 words
    S = (S / W)*100;
    float g = (0.0588 * L) - (0.296 * S) - 15.8;
    int grade = (g < 0 ? (g - 0.5) : (g + 0.5));
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char c = text[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) // check for letter
        {
            ++letters;
        }
    }
    printf("%i\n", letters);
    return letters;
}

int count_sentences(string text)
{
    int sentences = 0;
    bool inside = false;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char c = text[i];
        if (c == '"')
        {
            if(inside)
            {
                inside = false;
            }
            else
            {
                inside = true;
            }
        }
        if (c == '!' || c == '.' || c == '?') // check for sentence ending
        {
            if(!inside)
            {
                ++sentences;
            }
        }
    }
    //if(!sentences) //makes it so there is always at least 1 sentence
    //{
    //    ++sentences;
    //}
    printf("%i\n", sentences);
    return sentences;
}

int count_words(string text)
{
    int words = 1; //there will always be 1 word at the end not followed by a space
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char c = text[i];
        if (c == ' ') // check for word ending
        {
            ++words;
        }
    }
    printf("%i\n", words);
    return words;
}