#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototypes
bool check(string key, int argc);
string convert(string plaintext, string key);

// Main
int main(int argc, string argv[])
{
    // How many command-line arguments are there?
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Is key acceptable?
    if (check(argv[1], argc) == true)
        return 1;

    // Convert the plaintext
    string ciphertext = convert(get_string("plaintext: "), argv[1]);

    // Print the result
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

// Check the key
bool check(string key, int argc)
{
    int length = strlen(key);

    // How long is the key?
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return true;
    }

    // Is the key composed only of alphabetical characters?
    for (int i = 0; i < length; i++)
    {
        if (isalpha(key[i]) == 0)
        {
            printf("Key must only contain alphabetical characters.\n");
            return true;
        }
    }

    // Are there repetition in the key?
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (key[i] == key[j])
            {
                printf("Key must only contain repeated characters.\n");
                return true;
            }
        }
    }
    // If the key is valid, return true.
    return false;
}

// Generate the ciphertext
string convert(string plaintext, string key)
{
    int len = strlen(plaintext);
    string ciphertext = malloc(len + 1);

    for (int i = 0; i < len; i++)
    {
        if (isupper(plaintext[i]) != 0)
        {
            ciphertext[i] = toupper(key[plaintext[i] - 'A']);
        }
        else if (islower(plaintext[i]) != 0)
        {
            ciphertext[i] = tolower(key[plaintext[i] - 'a']);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    return ciphertext;
}