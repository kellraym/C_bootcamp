#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b);

int main() {

    int num1 = 5, num2 = 8;
    printf("Number one: %d, Number 2: %d\n", num1, num2);
    swap(&num1, &num2);
    printf("Number one: %d, Number 2: %d\n", num1, num2);

    return EXIT_SUCCESS;
}

void swap(int *const a, int *const b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}