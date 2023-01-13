#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    uint8_t data = 0b11101001;

    // select bits [3:5] (11[101]001)
    uint8_t result = (data >> 3) & 0b111;
    printf("(data >> 3) & 0b111 = %d\n", result);
    // clear 5th bit of data (res = 10101001)
    result = ~(1 << 6) & data;
    printf("~(1 << 6) & data = %d\n", result);

    return EXIT_SUCCESS;
}