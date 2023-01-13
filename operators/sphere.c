#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const double PI = 3.14159265359;
    double radius, area, volume;
    printf("Enter the radius:\n");
    scanf("%lf", &radius);

    area = 4 * PI * radius * radius;
    volume = 4.0 / 3.0 * PI * radius * radius * radius;

    printf("A sphere with radius %.2lf has an area of %.2lf and a volume of %.2lf\n", radius, area, volume);
    printf("A sphere with radius %.3e has an area of %.3e and a volume of %.3e\n", radius, area, volume);
    return EXIT_SUCCESS;
}