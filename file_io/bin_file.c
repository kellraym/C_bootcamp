#include <stdio.h>

int main()
{
    double a[] = {1, 2, 3, 4, 5};
    FILE *fp = fopen("test.bin", "wb"); 
    fwrite(a, sizeof *a, 5, fp); // write a to bin file
    fclose(fp);

    double b[5];
    fp = fopen("test.bin", "rb");
    size_t ret_code = fread(b, sizeof *b, 5, fp); // returns num of items read (items are size of *float)
    if (ret_code == 5)
    {
        puts("Array read successfully, contents: ");
        for (int n = 0; n < 5; ++n)
        {
            printf("%f ", b[n]);
        }
        putchar('\n');
    }
    else{
        if (feof(fp))
        {
            printf("Error reading test.bin: unexpected end of file\n");
        }
        else if (ferror(fp))
        {
            perror("Error reading test.bin");
        }
    }

    fclose(fp);
    return 0;
}