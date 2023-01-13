#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    int x[] = {1, 2, 3, 4, 5};

    printf("sizeof(x): %llu\n", sizeof(x));
    printf("sizeof(x[0]): %llu\n", sizeof(x[0]));
    printf("length of x: %llu\n", sizeof(x) / sizeof(x[0]));

    int8_t y[] = {1, 2, 3, 4, 5};
    printf("sizeof(y): %llu\n", sizeof(y));
    printf("sizeof(y[0]): %llu\n", sizeof(y[0]));
    printf("length of y: %llu\n", sizeof(y) / sizeof(y[0]));

    return EXIT_SUCCESS;
}