#include <stdio.h>
#include <stdlib.h>

#define LEN 5 // preprocessor directive to define LEN as 5

int main() {
    int a[LEN];

    for (int i = 0; i < LEN; i++) {
        a[i] = 1;
    }

    int x[] = {1, 2, 3, 4, 5};
    int y[LEN] = {1, 2, 3}; // using a macro as LEN works here, would not work with a const int
    // last two values initialized as 0 by compiler

    // printf("%d", y[4]);

    // Sparse array, initialization with designators
    // specified elements initializd with given values, all others 0
    int w[LEN] = {[1] = 1, [3] = 1}; //  will be 0, 1, 0, 1, 0
    int q[LEN] = {[1] = 3, [LEN - 1] = 5};
    int t[10] = {[0] = 5, 4, [10 - 3] = 3, 2, 1};
    for (int i = 0; i < 10; i++) {
        printf("%d ", t[i]);
    }

    return EXIT_SUCCESS;
}