#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 5

void clear_stdin()
{
    int c = ' ';
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int get_line(char dst[], int size)
{
    int i;
    for (i = 0; i < size - 1; i++)
    {
        int c = getchar();
        if (c == '\n' || c == EOF)
        {
            break;
        }

        dst[i] = (char) c;
    }

    if (i == size - 1)
    {
        clear_stdin();
    }

    dst[i] = '\0';
    return i;
}

int main()
{
    char buffer[BUF_SIZE];
    do
    {
        printf("Enter a line:\n");
        int n = get_line(buffer, BUF_SIZE);
        printf("[%d] %s\n", n, buffer);
    } while (strcmp(buffer, "END"));

    return EXIT_SUCCESS;
}