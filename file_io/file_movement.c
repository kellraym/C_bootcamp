#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
    enum {SIZE = 4};
    FILE* fp = fopen("test.bin", "wb");
    assert(fp);
    int rc = fwrite((double[SIZE]) {1.1, 2.2, 3.3, 4.4}, sizeof(double), SIZE, fp);

    assert(rc == SIZE);
    fclose(fp);

    fp = fopen("test.bin", "rb");
    fpos_t pos;
    fgetpos(fp, &pos);
    double d;
    rc = fread(&d, sizeof d, 1, fp);
    assert(rc == 1);
    printf("First value in the file: %.1f\n", d);
    fsetpos(fp, &pos);
    rc = fread(&d, sizeof d, 1, fp);
    printf("First value in the file again: %.1f\n", d);
    fclose(fp);

    rc = fsetpos(stdin, &pos);
    if (rc) perror("could not fsetpos stdin");
    return EXIT_SUCCESS;
}