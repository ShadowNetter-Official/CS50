#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// pseudo code
//
// take command line input
//  check if sufficient arguments are present - done
//  check if are letters, and that they don't repeat - done
//  convert all chars to uppercase - done
//
// take normal input
//
// encrypt input to cypher
//  use ASCII codes
//
// output encrypted version

string check_cla(int argc, string argv[]);
void help(bool usage);
void encrypt(char key[]);

int main(int argc, string argv[])
{
    string temp_key = check_cla(argc, argv);
    // check if there were any errors
    if (strcmp(temp_key, "1") == 0)
    {
        return 1;
    }
    // convert key to upper
    char key[26];
    for (int i = 0; i < 26; i++)
    {
        key[i] = toupper(temp_key[i]);
    }
    encrypt(key);
}

string check_cla(int argc, string argv[])
{
    // check if enough input provided
    if (argc != 2)
    {
        help(true);
        return "1";
    }
    for (int input = 0, len = strlen(argv[1]); input < len; input++)
    {
        // check if key is a letter
        if (!isalpha(argv[1][input]))
        {
            help(true);
            return "1";
        }
        // check if key contains 26 letters
        if (len != 26)
        {
            help(false);
            return "1";
        }
        // check if there are any reacurring chars
        for (int i = 0; i < len; i++)
        {
            if (input != i)
            {
                if (toupper(argv[1][input]) == toupper(argv[1][i]))
                {
                    help(true);
                    return "1";
                }
            }
        }
    }
    return argv[1];
}

void help(bool usage)
{
    if (usage)
    {
        printf("Usage: ./substitution key\n");
    }
    else
    {
        printf("Key must contain 26 characters.\n");
    }
}

void encrypt(char key[])
{
    // take user text input
    string input = get_string("plaintext: ");
    int length = strlen(input);
    char result[length];
    for (int letter = 0; letter < length; letter++)
    {
        // if input is letter, start encryption
        if (isalpha(input[letter]))
        {
            bool lower = false;
            // check if letter is lower
            if (islower(input[letter]))
            {
                lower = true;
            }
            // get index of letter in cipher key
            int result_index = toupper(input[letter]) - 'A';
            if (lower)
            {
                result[letter] = tolower(key[result_index]);
            }
            else
            {
                result[letter] = key[result_index];
            }
        }
        else
        {
            result[letter] = input[letter];
        }
    }
    printf("ciphertext: ");
    for (int chars = 0; chars < length; chars++)
    {
        printf("%c", result[chars]);
    }
    printf("\n");
}
