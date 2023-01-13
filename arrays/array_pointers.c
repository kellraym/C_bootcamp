#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    int x[] = {9, 8, 7, 6, 5};

    for (int i = 0; i < sizeof(x) / sizeof(x[0]); i++) {
        printf("x[i]: %d\n", x[i]);
    }

    // printf("%d", *(x + 1));

    int *p = &x[2];
    printf("%d | %d\n", x[2], *p);
    *p = 0;
    printf("%d | %d\n", x[2], *p);

    printf("array address:\n");
    // addresses are 64 bits
    printf("&x[0]: %llX\n", (uint64_t) &x[0]);
    printf("x:     %llX\n", (uint64_t) x);

    // int *alias = x;
    // same as int *alias = x[0]
    p = x;

    printf("Display x through the pointer:\n");
    for (int i = 0; i < sizeof(x) / sizeof(x[0]); i++) {
        printf("x[i]: %d, p[i]: %d\n", x[i], p[i]);
    }

    for (int i = 0; i < sizeof(x) / sizeof(x[0]); i++) {
        p[i] = i;
        printf("x[i]: %d, p[i]: %d\n", x[i], p[i]);
    }
    return EXIT_SUCCESS;
}