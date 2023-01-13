#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = NULL;
    
    if (ptr) {
        printf("1 | Pointed valude: %d\n", *ptr);
    }
   
    int someValue = 123;

    if (!ptr) {
        ptr = &someValue;
    }

    if (ptr) {
        printf("2 | Pointed valude: %d\n", *ptr);
    }


    return EXIT_SUCCESS;
}