#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *pa = malloc(10 * sizeof *pa); // allocate an array of 10 ints
    if (pa)
    {
        printf("%zu bytes allocated. Storing ints: ", 10 * sizeof(int));
        for (int n = 0; n < 10; ++n)
        {
            printf("%d ", pa[n] = n);
        }
    }

    int *pb = realloc(pa, 1000000 * sizeof *pb);
    // check if the pointer reallocated, else free the original pointer
    if (pb)
    {
        printf("\n%zu bytes allocated, first 10 ints are: ", 1000000 * sizeof *pb);
        for (int n = 0; n < 10; ++n)
            printf("%d", pb[n]);
        free(pb);
    }
    else
    {
        free(pa);
    }

    return EXIT_SUCCESS;
}