#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// strtol sets errno macro ERANGE during operation, can be checked for success/failure
#include <errno.h>
#include <stdbool.h>

int main()
{
    // char str[] = "-100000000000000000000000000000000000000";
    char str[] = "12.4 300.53";
    char *pend, *pstart = str;

    while (true)
    {
        // pend set to the address of the end of the converted sequence

        // using zero as base, prefix value of number will be used
        // long num = strtol(pstart, &pend, 0);
        float num = strtof(pstart, &pend);
        printf("\nConverting: %s\n", pstart);
        printf("errno: %d %s\n",errno, errno == ERANGE ? "(ERANGE)" : "");
        printf("%s", pend == str ? "pend == str (ERR)\n" : "pend != str (ok)\n");

        if (errno || pend == str)
        {
            printf("Conversion error\n");
        }
        else
        {
            printf("Conversion: %f\n", num);
        }

        if (pend == pstart)
        {
            break;
        }

        // pstart set to pend after conversion
        pstart = pend;
    }


    return EXIT_SUCCESS;
}