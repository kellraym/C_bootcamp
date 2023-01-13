#include <stdio.h>
#include <stdlib.h>

int main() {
    // null character is implied at the end, I told the compiler where to terminate the array
    char str1[10] = {'H', 'e', 'l', 'l', 'o', '!'}; 
    char str2[] = {'H', 'e', 'l', 'l', 'o', '!', '\0'};
    char str3[] = "Hello!"; // same as str2 Hello!\n

    // not valid, array already initialized
    // str3 = {'a', 'b', 'c'}; 

    const char str4[] = "Hello!"; // contents cannot be mutated
    char *str5 = "Hello!";
    // space at str is reserved for Hello!\0, also cannot be mutated but can be reassigned
    str5 = "yoyoyo";

    char str6[] = "This course is boring";
    printf("%s\n", str6);

    // make sure you use address operator for this
    // str6[15] is the value at index 15, &str6[15] is the address of the 15th index of str6
    printf("%s\n", &str6[15]); // prints remaining string from index 15

    printf("%.4s\n", &str6[15]);

    // array of strings
    // must specify the length of the strings when declaring, they must all be the same and the compiler can't guess what the longest one will be
    char days[][10] = {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday",
    };

    for (int i = 0; i < 7; printf("%s\n", days[i++]));

    // array of pointers to strings
    // compiler stores the string literals somewhere and the pointers are indexed instead. No need to specify size but addresses will be scattered. Saves space, but matrix optimizations cannot be used
    char *days2[] = {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday",
    };

    for (int i = 0; i < 7; printf("%s\n", days2[i++]));

    char input_str[10];

    // will write outside of input string if you enter something too large
    scanf("%s", input_str);
    printf("%s", input_str);

    return EXIT_SUCCESS;
}