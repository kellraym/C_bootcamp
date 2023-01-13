#include <stdlib.h>
#include <stdio.h>

int sum(int a, int b) {
    return a + b;
}

// address of accumulator is constant, never need to change it
int accumulate(int *const accumulator, int value) {
    int dummy = 0;
    if (value > 0) {
        *accumulator += value;
        return 0;
    } else {
        return -1;
    }
}

void accumulateWrapper(int *const accumulator, int value) {
    // accumulate returns a 0 on successful operation, a -1 would be truthy and trigger the warning
    if (accumulate(accumulator, value)) {
        printf("Warning! Value = %d\n", value);
    }
}

void printStudents(int students) {
    students--;
    printf("Students = %d\n", students);
}

int main() {
    int girls = 12, boys = 9;
    int students = sum(girls, boys);
    printStudents(students);
    printf("Original students = %d\n", students);

    int class_1 = 28, class_2 = 19, class_3 = -1;

    int accumulator = 0;

    accumulateWrapper(&accumulator, class_1);
    accumulateWrapper(&accumulator, class_2);
    accumulateWrapper(&accumulator, class_3);

    printf("Accumulator = %d\n", accumulator);

    return EXIT_SUCCESS;
}