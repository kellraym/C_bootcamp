#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    int a;
    printf("Enter a positve integer: \n");
    scanf("%d", &a);

    if (a < 0)
    {
        printf("%d is negative, goodbye.", a);
        return EXIT_FAILURE;
    }

    // lol
    bool isEven = a % 2 == 0 ? 1 : 0;    
    
    if (isEven)
    {
        printf("number is even");
    }
    else
    {
        printf("number is odd");
    }
    

    return EXIT_SUCCESS;
}