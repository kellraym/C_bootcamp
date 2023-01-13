#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int a, b, c;

    printf("Enter A operand (int): ");
    scanf("%d", &a);
    printf("Enter B operand (int): ");
    scanf("%d", &b);
    c = a + b;
    printf("\nc = a + b --> %d", c);

    c = a - b;
    printf("\nc = a - b --> %d", c);

    c = a * b;
    printf("\nc = a * b --> %d", c);

    c = a / b;
    printf("\nc = a / b --> %d", c);

    c = a % b;
    printf("\nc = a %% b --> %d", c);

    return EXIT_SUCCESS;
}