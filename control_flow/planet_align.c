#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int a, b, c, max;
    printf("Enter planet 1 orbit time (in days): ");
    scanf("%d", &a);

    printf("Enter planet 2 orbit time (in days): ");
    scanf("%d", &b);

    printf("Enter planet 3 orbit time (in days): ");
    scanf("%d", &c);

    max = a > b ? a : b;
    max = c > max ? c : max;
    int lcm = 1;
    const int MAX_ITER = 10000;

    for (int i = 1; i < MAX_ITER; i++) {
        int mul = max * i;
        if (!(mul % a) && !(mul % b) && !(mul % c)) {
            lcm = mul;
            break;
        }
    }

    printf("Orbits a, b, c align every %d days\n", lcm);
    printf("Planet a completes %d orbits\n", lcm / a);
    printf("Planet b completes %d orbits\n", lcm / b);
    printf("Planet c completes %d orbits\n", lcm / c);
}