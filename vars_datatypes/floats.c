#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    // 1.23456789
    double decimalDigits = 1.23456789;

    // 7.801 x 10 ^ 9
    double worldPopulation = 7.801E9;

    // 6.626 x 10 ^ -34
    double plankConstant = 6.626E-34;

    printf("%12.1f | 1 decimal digit\n", decimalDigits);
    printf("%12.3f | 3 decimal digits\n", decimalDigits);
    printf("%12.1f | world pop, decimal, 1 digit\n", worldPopulation);
    printf("%12.1e | world pop, scientific, 3 digits\n", worldPopulation);
    printf("%12.3E | plank's constant 1 digit\n", plankConstant);
    printf("%12.3E | plank's constant 3 digits\n", plankConstant);

    return EXIT_SUCCESS;
}