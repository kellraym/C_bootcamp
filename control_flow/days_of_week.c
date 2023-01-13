#include <stdio.h>
#include <stdlib.h>

typedef enum 
{
    MON = 1,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN,
} dayOfWeek;

int main(void)
{
    dayOfWeek day;
    printf("Monday is %d, and Sunday is %d\n", MON, SUN);
    printf("Please enter the day as an integer\n");
    scanf("%u", &day);

    switch (day)
    {
        case MON:
            printf("Today is Monday");
            break;
        case TUE:
            printf("Today is Tuesday");
            break;
        case WED:
            printf("Today is Wednesday");
            break;
        case THU:
            printf("Today is Thursday");
            break;
        case FRI:
            printf("Today is Friday");
            break;
        case SAT:
            printf("Today is Saturday");
            break;
        case SUN:
            printf("Today is Sunday");
            break;

        default:
            printf("Not a day of the week");
            break;
    }

    return EXIT_SUCCESS;
}