#include <stdio.h>
#include "mod2.h"

void print_mod2()
{
    Led led = LED_OFF;
    printf("This is mod 2, led status: ");
    print_led_status(led);
    printf("\n");
}