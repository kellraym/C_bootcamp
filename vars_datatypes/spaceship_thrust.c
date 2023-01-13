#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    NONE,
    LOW = 5,
    MEDIUM = 9,
    HIGH = 12,
    MAXIMUM = 20,
} ThrustLevel;

int main(void)
{
    ThrustLevel thrust = NONE;
    printf("Ready to go %d\n", thrust);
    thrust = MAXIMUM;
    printf("Ready to level %d\n", thrust);
    thrust = MEDIUM;
    printf("Enterint into the ionosphere %d\n", thrust);
    thrust = LOW;
    printf("Traveling to deep space %d", thrust);

    return EXIT_SUCCESS;
}