#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    const int MAX = 1000;
    int upperLimit;
    printf("Enter a number: ");
    scanf("%d", &upperLimit);
    if (upperLimit > MAX) {
        goto cleanup;
    }

    bool isPrime = true;
    for (unsigned int i = 2U; i < upperLimit; i++) {
        bool isPrime = true;
        for (unsigned int j = 2; j < i; j++) {
            if (!(i % j) && i != 2) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            printf("%d is prime\n", i);
        }
    }

    cleanup:
    return EXIT_SUCCESS;
}