#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MIN_ROWS 2
#define MAX_ROWS 10
#define MIN_COLS 2
#define MAX_COLS 10
#define MIN_UPPER_LIMIT 2
#define MAX_UPPER_LIMIT 1000

int gen_matrix(const int rows, const int cols, int matrix[rows][cols], int upper_limit) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % upper_limit;
        }
    }
    return EXIT_SUCCESS;
}

void display_matrix(const int rows, const int cols, int matrix[rows][cols], bool transposed) {
    printf("---\n");
    for (int i = 0; i < (transposed ? cols : rows); i++) {
        for (int j = 0; j < (transposed ? rows: cols); j++) {
            printf("%3d ", matrix[transposed ? j : i][transposed ? i : j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols, upper_limit;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    printf("Enter upper limit: ");
    scanf("%d", &upper_limit);

    if (rows < MIN_ROWS || rows > MAX_ROWS || cols < MIN_COLS || cols > MAX_COLS) {
        printf("Out of bounds");
        return EXIT_FAILURE;
    }
    if (upper_limit < MIN_UPPER_LIMIT || upper_limit > MAX_UPPER_LIMIT) {
        printf("Out of bounds");
        return EXIT_FAILURE;
    }
    int matrix[rows][cols];
    srand(time(NULL));
    gen_matrix(rows, cols, matrix, upper_limit);
    display_matrix(rows, cols, matrix, false);
    display_matrix(rows, cols, matrix, true);
    return EXIT_SUCCESS;
}