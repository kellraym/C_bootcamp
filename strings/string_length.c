#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char my_string[] = "I love programming in C!";
    printf("The string: \"%s\"\n", my_string);
    int i;
    for (i = 0; my_string[i] != '\0'; i++);
    printf("String length (from scratch): %d\n", i);
    printf("Sizeof string: %lld\n", sizeof(my_string));

    printf("String length (built in): %d\n", strlen(my_string));

    char another_string[] = "Programming is funny";
    printf("Before copy: \"%s\"\n", my_string);
    printf("After copy: \"%s\"\n", strcpy(my_string, another_string));
    printf("After copy: \"%s\"\n", my_string);

    char another_long_string[] = "This is a dummy very very very long string...........";

    // printf("Bad copy: \"%s\"\n", strcpy(my_string, another_long_string));
    printf("safe copy: \"%s\"\n", strncpy(my_string, another_long_string, sizeof(my_string) - 1));

    char str_1[] = "abcd";
    char str_2[] = "abcz";

    printf("strcmp %s, %s: %d\n", str_1, str_2, strcmp(str_1, str_2));
    printf("strcmp %s, %s: %d\n", str_1, str_2, strncmp(str_1, str_2, 3));


    return EXIT_SUCCESS;
}