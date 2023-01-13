#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int data = 0xABCD;

    // 0111 1000 1001 1010
    unsigned N = 0;
    unsigned M = 3;

    printf("Bits [0:3] 0x%04X\n", (data & (2 << M) - 1) >> N);

    N = 4;
    M = 7;
    printf("Bits [4:7] 0x%04X\n", (data & (2 << M) - 1) >> N);

    N = 8;
    M = 11;
    printf("Bits [8:11] 0x%04X\n", (data & (2 << M) - 1) >> N);

    N = 12;
    M = 15;
    printf("Bits [12:15] 0x%04X\n", (data & (2 << M) - 1) >> N);

    return EXIT_SUCCESS;
}