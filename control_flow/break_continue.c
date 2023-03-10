#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int input, accumulator = 0;
    const int ITERATIONS = 10;

    for (int i = 0; i < ITERATIONS; i++) {
        printf("Enter an integer (-1 to exit): ");
        scanf("%d", &input);
        
        if (input == -1) {
            break;
        }

        accumulator += input;
    }

    printf("\nAccumulator: %d\n", accumulator);

    return EXIT_SUCCESS;
}