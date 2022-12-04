#include <math.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>

int count_sentences(string text);
int count_letters(string text);
int count_words(string text);

int main(void)
{
    float letters, words, sentences, L, S, Grade;

    // get text
    string text = get_string("text: ");

    letters = count_letters(text);
    words = count_words(text);
    sentences = count_sentences(text);

    // is the average number of letters per 100 words
    L = (letters / words) * 100;
    // is the average number of sentences per 100 words
    S = (sentences / words) * 100;

    // Coleman-Liau index
    Grade = 0.0588 * L - 0.296 * S - 15.8;

    if (Grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (Grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(Grade));
    }
}


// function for count number of sentences
int count_sentences(string text)
{
    int counter = 0;

    // take length of the word for use index
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // if character in text is equal of '.' sum 1
        if (text[i] == '.')
        {
            counter += 1;
        }
        if (text[i] == '!')
        {
            counter += 1;
        }
        if (text[i] == '?')
        {
            counter += 1;
        }
    }
    return counter;
}

// function for count number of words
int count_words(string text)
{
    int counter = 1;

    // take length of the word for use index
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // if character in text equal empty space, sum 1
        if (text[i] == ' ')
        {
            counter += 1;
        }
    }
    return counter;
}

int count_letters(string text)
{
    int counter = 0;

    // take length of the word for use index
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // if character sum 1
        if (isalpha(text[i]))
        {
            counter += 1;
        }
    }
    return counter;
}
