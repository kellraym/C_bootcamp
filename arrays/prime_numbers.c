#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define PRIME_ARR_LEN 100000
#define MIN_UPPER_LIMIT 3
#define MAX_UPPER_LIMIT 1000000

bool is_prime(int num, int arr[PRIME_ARR_LEN]) {
    for (int i = 0; arr[i] <= sqrt(num); i++) {
        if (!(num % arr[i])) return false;
    }   
    return true;
}

void findPrimes(int limit, int arr[PRIME_ARR_LEN]) {
    int index = 0;
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i, arr)) arr[index++] = i;
    }
}

double elapsed_time_sec(clock_t start, clock_t end) {
    return (end - start) / (double) CLOCKS_PER_SEC;
}

int main() {
    int upper_limit;
    printf("Enter an upper limit (int between %d and %d inclusive): ", MIN_UPPER_LIMIT, MAX_UPPER_LIMIT);
    scanf("%d", &upper_limit);
    if (upper_limit < MIN_UPPER_LIMIT || upper_limit > MAX_UPPER_LIMIT) {
        printf("Not within limit");
        return EXIT_FAILURE;
    }

    int prime_arr[PRIME_ARR_LEN] = {2};
    clock_t start_clk = clock();
    findPrimes(upper_limit, prime_arr);
    printf("%.3f miliseconds elapsed\n", elapsed_time_sec(start_clk, clock()));
    for (int i = 0; i < 50; i++) printf("%d\n", prime_arr[i]);
    
    return EXIT_SUCCESS;
}