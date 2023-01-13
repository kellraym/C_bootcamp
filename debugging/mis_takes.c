#include <stdio.h>
#include <stdlib.h>

int main() {
    int num = 2;

    if (num < 0) {
        printf("Num is < 0\n");
    }

    if (num == 5) {
        printf("num is equal to 5\n");
    }

    for (int i = 0; i < 10; printf("%d\n", i++));

    return EXIT_SUCCESS;
}