#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int userInput;
    do
    {
        printf("Enter a number: ");
        scanf("%d", &userInput);
        if (userInput > 0)
        {
            int power = 0;
            int result = 1;
            while ((result = (1 << power++)) < userInput);
            printf("Smallest power of 2 is %d\n", result);
        }
    } while (userInput != -1);
    

    return EXIT_SUCCESS;
}