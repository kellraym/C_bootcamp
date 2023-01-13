#include <stdlib.h>
#include <stdio.h>

void decompose(float number, int *const int_part, float *const frac_part);

int main() {
    int int_part;
    float frac_part, input;
    printf("Input a floating point number: ");
    scanf("%f", &input);
    decompose(input, &int_part, &frac_part);

    printf("Integer part of %.2f: %d\n", input, int_part);
    printf("Decimal part of %.2f: %.2f\n", input, frac_part);
    printf("Reconstructed number: %.2f\n", int_part + frac_part);

    return EXIT_SUCCESS;
}

void decompose(float number, int *const int_part, float *const frac_part) {
    *int_part = (int) number;
    *frac_part = number - *int_part;
}