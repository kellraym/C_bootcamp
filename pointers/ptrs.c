#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
char a = 'A';
char *ptr = &a;

printf("1 | %c, %c, %u\n", a, *ptr, (uint64_t) ptr);

char b = 'B';
ptr = &b;
printf("2 | %c, %c, %u\n", b, *ptr, (uint64_t) ptr);

*ptr = 'C';
printf("3 | %c, %c, %u\n", b, *ptr, (uint64_t) ptr);

(*ptr)++;
printf("4 | %c, %c, %u\n", b, *ptr, (uint64_t) ptr);

unsigned x = 'A';
ptr = (char *) &x;
printf("5 | %c, %c, %u\n", x, *ptr, (uint64_t) ptr);

unsigned y = 'B';
ptr = (char *) &y;
printf("6 | %c, %c, %u\n", y, *ptr, (uint64_t) ptr);

*ptr = 'C';
printf("7 | %c, %c, %u\n", y, *ptr, (uint64_t) ptr);

(*ptr)++;
printf("8 | %c, %c, %u\n", y, *ptr, (uint64_t) ptr);

x = 0xABCD1234;
ptr = (char *) &x;
printf("9 | %u, %X, %X, %c\n", x, x, *ptr, *ptr);

// char pointer pointing to an unsigned int, changing value at ptr only modifies one byte of x's value
*ptr = 'C';
printf("10 | %u, %X, %X, %c\n", x, x, *ptr, *ptr);

unsigned *uint_ptr = (unsigned *)ptr;
*uint_ptr = 'C';
printf("11 | %u, %X, %X, %c\n", x, x, *ptr, *ptr);


return EXIT_SUCCESS;
}