#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[] = "This, is a. sample-string";
    char str_cpy[sizeof(str)];
    char tokens[sizeof(str)][sizeof(str)];
    char delimiters[] = " ,.-";
    char *token = strtok(str, delimiters);
    int i = 0;
    
    while (token = strtok(NULL, delimiters))
    {
        strncpy(tokens[i++], token, sizeof(str));
    }

    for (int j = 0; j < i; j++)
    {
        printf("%s\n", tokens[j]);
    }

    return EXIT_SUCCESS;
}