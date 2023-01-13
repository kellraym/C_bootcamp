#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    float a, b, c;
    printf("Enter A operand (float): ");
    scanf("%f", &a);
    printf("Enter B operand (float): ");
    scanf("%f", &b);
    c = a + b;
    printf("\nc = a + b --> %9.3f", c);

    c = a - b;
    printf("\nc = a - b --> %9.3f", c);

    c = a * b;
    printf("\nc = a * b --> %9.3f", c);

    c = a / b;
    printf("\nc = a / b --> %9.3f", c);

    c = fmod(a, b);
    printf("\nc = a %% b --> %9.3f", c);

    return EXIT_SUCCESS;
}