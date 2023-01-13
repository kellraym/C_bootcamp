#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void find_all_occurrences(char *input_string, char string_size, char target_char)
// {
//     char res_string[string_size];

//     for (int i = 0; i < string_size - 1; i++) 
//     {
//         if (input_string[i] == target_char) 
//         {
//             res_string[i] = '^';
//         }
//         else
//         {
//             res_string[i] = ' ';
//         }
//     }

//     printf("%s\n", input_string);
//     printf("%s\n", res_string);
// }

int find_all_occurrences(char str[], char c, int indexes[])
{
    int found = 0;
    char *pstr = str;

    do
    {
        pstr = strchr(pstr, c);

        if (pstr)
        {
            indexes[found++] = pstr++ - str;
        }
    } while (pstr != NULL);
    return found;
}

void print_occurrences(char str[], int occurrences_indexes[], int found)
{
    char pattern[strlen(str + 1)];
    memset(pattern, ' ', sizeof(pattern));

    for (int i = 0; i < found; i++)
    {
        pattern[occurrences_indexes[i]] = '^';
    }

    pattern[sizeof(pattern) - 1] = '\0';
    printf("%s\n", str);
    printf("%s\n", pattern);
}

void find_substring(char str[], char substring[])
{
    char *index = strstr(str, substring);
    char result_string[strlen(str)];

    memset(result_string, ' ', strlen(str));
    result_string[strlen(result_string) - 1] = '\0';
    int range[2];
    if (index)
    {
        range[0] = index - str;
        range[1] = range[0] + strlen(substring);
    }

    for (int i = range[0]; i < range[1]; i++)
    {
        result_string[i] = '-';
    }
    printf("%s\n", str);
    printf("%s\n", result_string);

}

// return number of tokens found in the string
int tokenize_string(char str[], const char delimiters[], int tok_max_len, char tokens[][tok_max_len])
{
    int i;
    char *ptok = str;

    for (i = 0; ptok; i++)
    {
        ptok = strtok(i == 0 ? ptok : NULL, delimiters);
        strncpy(tokens[i], ptok, ptok ? tok_max_len : 0);
    }
    return i - 1;
}

void print_tokens(int n_tokens, int tok_max_len, char tokens[][tok_max_len], char str[], const char delimiters[])
{
    printf("\n\nTokenization with delimiters \"%s\":\n", delimiters);
    printf("%s\n", str);
    for (int i = 0; i < n_tokens; i++)
    {
        printf("[%d] %s\n", i, tokens[i]);
    }
}

int main()
{
    char str[] = "This, is a. sample-string";
    const char delimiters[] = " ,.-";
    int tok_max_len = sizeof(str);
    char tokens[tok_max_len][tok_max_len], str_cpy[tok_max_len];
    strncpy(str_cpy, str, tok_max_len);
    int n_tokens = tokenize_string(str_cpy, delimiters, tok_max_len, tokens);
    print_tokens(n_tokens, tok_max_len, tokens, str, delimiters);
    return EXIT_SUCCESS;
}