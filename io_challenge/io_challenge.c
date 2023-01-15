#include <stdio.h>
#include <stdlib.h>

#define SAMPLES_LEN 100
#define DOWNSAMPLE_K 10

void program_failure(char str[])
{
    perror(str);
    exit(EXIT_FAILURE);
}

int main()
{
    // write contents of a double array to a bin file
    // array from 0.1 to 10.0 with steps of .1 between each element

    double samples[SAMPLES_LEN];
    for (int i = 0; i < SAMPLES_LEN; i++)
    {
        samples[i] = 0.1 * (i + 1);
        printf("%.1f, ", samples[i]);
    }

    printf("\n----\n");

    FILE* fp = fopen("samples.bin", "wb");
    if (!fp)
    {
        program_failure("File opening error");
    }

    size_t written_count = fwrite(samples, sizeof(samples[0]), SAMPLES_LEN, fp);
    if (written_count != SAMPLES_LEN)
    {
        program_failure("File writing failed");
    }
    fclose(fp);


    double sam_k[SAMPLES_LEN / DOWNSAMPLE_K];
    fp = fopen("samples.bin", "rb");

    for (int i = 0; i < SAMPLES_LEN / DOWNSAMPLE_K; i++)
    {
        int offset = (DOWNSAMPLE_K - 1) * sizeof(sam_k[0]);
        if (fseek(fp, offset, SEEK_CUR) != 0)
        {
            program_failure("File seeking failed");
        }
        size_t count = fread(&sam_k[i], sizeof(sam_k[0]), 1, fp);
        if (count != 1)
        {
            if (feof(fp))
            {
                program_failure("Unexpected End Of File");
            }
            else
            {
                program_failure("Error reading the file");
            }
        }
        printf("%.1f, ", sam_k[i]);
    }
    fclose(fp);

    return EXIT_SUCCESS;
}