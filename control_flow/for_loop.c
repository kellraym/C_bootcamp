#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // const char symbol = 'x';
    // const int BASE_WIDTH = 10;
    // const int TIP_WIDTH = 5;

    // for (int i = 0; i < BASE_WIDTH; i++) {
    //     printf("%c", symbol);
    // }
    // printf("\n");

    // for (int i = 1; i < TIP_WIDTH; i++) {
    //     for (int j = 0; j < i; j++) {
    //         printf(" ");
    //     }
    //     printf("%c\n", symbol);
    // }

    // for (int i = TIP_WIDTH; i > 0; i--) {
    //     for (int j = 0; j < i; j++) {
    //         printf(" ");
    //     }
    //     printf("%c\n", symbol);
    // }

    // for (int i = 0; i < BASE_WIDTH; i++) {
    //     printf("%c", symbol);
    // }
    printf("xxxxxxxxxx\n");
    for (int i = 1; i < 11; i++) {
        if (i < 6) {
            for (int j = 0; j < i; j++) {
                printf(" ");
            }
        } else {
            for (int j = 10 - i; j > 0; j--) {
                printf(" ");
            }
        }
        printf("x\n");
    }
    printf("xxxxxxxxxx");
    return EXIT_SUCCESS;
}