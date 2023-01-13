#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void clear_stdin()
{
    int c = ' ';
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

char *get_line_alloc(int *plen)
{
    if (!plen)
    {
        plen = malloc(sizeof(*plen));
        if (!plen)
        {
            return NULL;
        }
    }

    *plen = 0;
    char *line = NULL;
    int buffer_size = 0, input;
    // block size will fit five characters
    const int alloc_block_size = 5;

    while (true)
    {
        input = getchar();

        if (buffer_size <= *plen)
        {
            // resize the memory block
            buffer_size += alloc_block_size;
            char *realloc_line = realloc(line, buffer_size);
            if (!realloc_line)
            {
                // line will not be freed by realloc
                free(line);
                return NULL;
            }
            
            line = realloc_line;
        }

        if (input != '\n' && input != EOF)
        {
            line[(*plen)++] = (char) input;
        }
        else
        {
            break;
        }
    }
    line[*plen] = '\0';
    return line;
}

int main()
{
    char *line = NULL;
    int *len;

    do
    {
        printf("Enter a line (END to quit):\n");

        free(line);
        line = get_line_alloc(len);

        if (line)
        {
            printf("%s (len=%d)", line, *len);
        }
        else
        {
            printf("Cannot allocate memory\n");
        }
    } while (line && strcmp(line, "END"));
    
    return EXIT_SUCCESS;
}