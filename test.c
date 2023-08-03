#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double find_x(double x)
{
    double x_cubed = x * x * x;
    double x_squared = x * x;

    return (x_cubed - 3 * x_squared) / (5 * x - 15);
}

void get_x(float *x)
{
    float new_x;
    printf("Enter x: ");
    scanf("%f", &new_x);
    *x = new_x;
}

float *get_test_vals(double x)
{
    float *vals = malloc(sizeof(double) * 6);
    float modifiers[] = {.1, .01, .001, -.001, -.01, -.1};
    printf("Hello\n");
    for (int i = 0; i < 6; i++)
    {
        *(vals + i) = x + modifiers[i];
    }
    return vals;
}

//adding an important comment

int main(void)
{
    float x;
    get_x(&x);
    printf("%.3f", x);
    
    // float* test_vals = get_test_vals(x);
    float test_vals[] = {x + .1, x + .01, x + .001, x - .001, x - .01, x - .1};

    for (int i = 0; i < 6; i++)
    {
        printf("x = %.3f, then y = %.3f\n", test_vals[i], find_x(test_vals[i]));
        // printf("x = %.3f, then y = %.3f\n", *(test_vals + i), find_x(*(test_vals + i)));
    } 

    // free(test_vals);
    // test_vals = NULL;
    return EXIT_SUCCESS;
}