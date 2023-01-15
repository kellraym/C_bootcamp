#include <stdio.h>
#include <stdlib.h>

int main(void)
{
#define SIZE 5
    double A[SIZE] = {1, 2, 3, 4, 5};
    FILE* fp = fopen("test.bin", "wb");
    fwrite(A, sizeof(double), SIZE, fp);
    fclose(fp);

    double B[SIZE];
    fp = fopen("test.bin", "rb");

    if ((fseek(fp, sizeof(double) * 2L, SEEK_SET) != 0));
    {
        perror("fseek()");
        fprintf(stderr, "fseek() failed in file %s at line # %d\n", __FILE__, __LINE__, -5);
        exit(EXIT_FAILURE);
    }
    // printf("%d\n", fseek(fp, sizeof(double) * 2L, SEEK_SET));
    int ret_code = fread(B, sizeof(double), 1, fp);
    printf("%.1f\n", B[0]);

    fclose(fp);
    return EXIT_SUCCESS;
}