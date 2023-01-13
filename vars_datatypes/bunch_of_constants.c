#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int moonLanding = 1969;
    const double speedOfLight = 299792458.;
    const float pi = 3.142f;
    const unsigned int hexaDead = 0xDEADU;
    const unsigned int hexaSecret = 51966U;

    printf("%10d\n", moonLanding);
    printf("%010d\n", moonLanding);
    printf("%.0f\n", speedOfLight);
    printf("%.3e\n", speedOfLight);
    printf("%.2f\n", pi);
    printf("%+.1e\n", pi);
    printf("0x%X\n", hexaDead);
    printf("%u\n", hexaDead);
    printf("%x\n", hexaSecret);

    return EXIT_SUCCESS;
}