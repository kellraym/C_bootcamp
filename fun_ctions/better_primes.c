#include <stdlib.h>
#include <stdio.h>

void findAllPrimes(int num);
void findNextPrime(int num, int max);
unsigned checkPrime(int num);

int main(void){
    const unsigned MAX = 1000;
    unsigned upperLimit, lowerLimit;
    printf("Enter the upper limit: ");
    scanf("%u", &upperLimit);
    if (upperLimit < 2 || upperLimit > MAX) goto cleanup;
    findAllPrimes(upperLimit);

    printf("Enter the lower limit: ");
    scanf("%u", &lowerLimit);

    if (lowerLimit < 2 || lowerLimit > MAX) goto cleanup;
    findNextPrime(lowerLimit, MAX);

    cleanup:
    return EXIT_SUCCESS;
}

unsigned checkPrime(int num) {
    for (unsigned i = 2U; i < num; i++) {
        if (!(num % i) && num != 2) {
            return 0;
        }
    }
    return 1;
}

void findAllPrimes(int num) {
    for (unsigned i = 2U; i < num; i++) {
        if (checkPrime(i)) {
            printf("%u is prime\n", i);
        }
    }
}

void findNextPrime(int num, int max) {
    for (unsigned i = num; i < max; i++) {
        if (checkPrime(i)) {
            printf("%u is prime\n", i);
            break;
        }
    }
}