#include <stdio.h>
#include <stdlib.h>

typedef enum 
{
    TEA,
    COFFEE,
    JUICE = 100,
    BEER,
} Menu;

int main(void)
{
    Menu mario = COFFEE;
    Menu andrea = BEER;

    printf("Mario ordered:  %d\n", mario);
    printf("Andrea ordered: %d\n", andrea);

    return EXIT_SUCCESS;
}