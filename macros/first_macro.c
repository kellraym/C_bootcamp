#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN 100
#define CALC_ARRAY_LEN(x) (sizeof((x)) / sizeof((x)[0]))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main()
{
    double array[ARRAY_LEN];

    printf("Array length: %d\n", ARRAY_LEN);

#undef ARRAY_LEN
#define ARRAY_LEN 999

    printf("New Array len: %d\n", ARRAY_LEN);

    printf("Source file: \"%s\", %d\n", __FILE__, __LINE__);
    printf("Compilation time: %s\n", __TIME__);

    int array_len = CALC_ARRAY_LEN(array);
    printf("Calculated array len: %d\n", array_len);

    int a = -1, b = 5;
    printf("MAX(%d, %d): %d\n", a, b, MAX(a, b));
    int b_before = b;
    printf("MAX(%d, %d): %d\n", a, b, MAX(a, b++));
    printf("%d", b);
    return EXIT_SUCCESS;
}