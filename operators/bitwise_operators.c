#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    uint8_t a = 12;
    uint8_t b = 5;

    printf("%u & %u = %u\n", a, b, a & b);
    printf("%u | %u = %u\n", a, b, a | b);
    printf("%u ^ %u = %u\n", a, b, a ^ b);
    printf("%u << 1 = %u\n", a, a << 1U);
    printf("%u >> 1 = %u\n", a, a >> 1U);

    return EXIT_SUCCESS;
}