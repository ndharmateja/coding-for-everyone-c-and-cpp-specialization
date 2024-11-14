#include <stdio.h>
#include <math.h>

// A function that prints the sin cos values for a given x
void print_sin_cos_values(double x)
{
    // Computing sin and cos and printing each row of the table
    double sin_value = sin(x);
    double cos_value = cos(x);
    printf("sin(%.1lf)=%.3lf\tcos(%.1lf)=%.3lf\n", x, sin_value, x, cos_value);
}

int main(void)
{
    // Iterating over x from 0 to 1 in increments of 0.1
    for (double x = 0; x <= 1; x += 0.1)
    {
        print_sin_cos_values(x);
    }
    printf("\n");

    return 0;
}