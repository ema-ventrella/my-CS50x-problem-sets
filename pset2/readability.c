#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Prototypes
int count_letters(char l);
int count_words(char l);
int count_sentences(char l);
int grade(int l, int w, int s);

// Main
int main(void)
{
    // Initialize variables
    int letters = 0;
    int words = 1;
    int sentences = 0;

    // Ask text from the user
    string text = get_string("Text: ");

    // Count letters, words and sentences
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        letters += count_letters(text[i]);
        words += count_words(text[i]);
        sentences += count_sentences(text[i]);
    }

    // Using Coleman-Liau index
    int level = grade(letters, words, sentences);

    // Output
    if (level < 1)
        printf("Before Grade 1\n");
    else if (level >= 16)
        printf("Grade 16+\n");
    else
        printf("Grade %i\n", level);
}

int count_letters(char l)
{
    if (isalpha(l) != 0)
        return 1;
    else
        return 0;
}

int count_words(char l)
{
    if (isblank(l) != 0)
        return 1;
    else
        return 0;
}

int count_sentences(char l)
{
    if (l == '.' || l == '?' || l == '!')
        return 1;
    else
        return 0;
}

// Coleman-Liau index
int grade(int l, int w, int s)
{
    double index = 0.0588 * (((float) l * 100) / (float) w) - 0.296 * (((float) s * 100) / (float) w) - 15.8;
    printf("%f\n", index);
    return round(index);
}