#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE* my_file = fopen("my_file.txt", "r");
    if (!my_file)
    {
        perror("File opening failed");
        return EXIT_FAILURE;
    }
    char pnext;
    while ((pnext = fgetc(my_file)) != EOF)
    {
        putchar(pnext);
    }

    if (ferror(my_file))
    {
        puts("\nI/O error when reading");
    }
    else if (feof(my_file))
    {
        puts("\nEnd of file reached successfully");
    }

    fclose(my_file);
    return EXIT_SUCCESS;
}