#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *p1 = calloc(4, sizeof(int));
    int *p2 = calloc(1, sizeof(int[4]));
    int *p3 = calloc(4, sizeof *p3);

    if (p2)
    {
        for (int n = 0; n < 4; ++n)
        {
            printf("p2[%d] == %d\n", n, p2[n]);
        }
    }

    free(p1);
    free(p2);
    free(p3);
    
    return EXIT_SUCCESS;
}