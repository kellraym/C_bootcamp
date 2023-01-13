#include <stdio.h>
#include <stdlib.h>

// enum menu
// {
//     TEA,
//     COFFEE,
//     JUICE = 100,
//     BEER,
// };

enum months
{
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC,
};

int main(void)
{
    // enum menu mario = COFFEE;
    // enum menu andrea = BEER;

    enum months bestMonth = JUL;
    enum months worstMonth = NOV;

    printf("Andrea's farorite month: %d\n", bestMonth);
    printf("Andrea's worst month: %d\n", worstMonth);


    // printf("Mario ordered:  %d\n", mario);
    // printf("Andrea ordered: %d\n", andrea);

    return EXIT_SUCCESS;
}