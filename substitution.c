#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool checkKey(string key);
string formatKey(string key);
string cypher(string key, string text);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error\n");
        return 1;
    }
    string key = argv[1];

    key = formatKey(key);
    printf("%s\n", key);
    if (checkKey(key))
    {
        printf("Invalid Key\n");
        return 1;
    }
    string plaintext = get_string("plaintext: ");
    string cyphertext = cypher(key, plaintext);
    printf("ciphertext: %s\n", cyphertext);
}

bool checkKey(string key)
{
    if (strlen(key) != 26) // check length
    {
        //return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        char c = key[i];
        if ((c >= 'A' && c <= 'Z')) // check for letter
        {
            for (int j = i+1; j < 26; j++)
            {
                if(c == key[j])
                {
                    return 1;
                }
            }
        }
        else
        {
            return 1; //toss error
        }
    }
    return 0;
}

string formatKey(string key)
{
    string newKey = key;
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        char c = key[i];
        if(islower(c))
        {
            newKey[i] = toupper(c);
        }
    }
    return newKey;
}

string cypher(string key, string text)
{
    string cyphertext = text;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char c = text[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            char upper = c;
            if(islower(c)) // convert char to key format
            {
                upper = toupper(c);
            }
            int pos = upper - 'A'; // get pos in key
            upper = key[pos];
            if(islower(c))
            {
                c = tolower(upper);
            }
            else
            {
                c = upper;
            }
            cyphertext[i] = c;
        }
    }
    return cyphertext;
}