#include <stdio.h>
#include <math.h>

int main(void)
{
    // Iterating over x from 0 to 1 in increments of 0.1
    for (double i = 0; i <= 1; i += 0.1)
    {
        // Computing sin and cos and printing each row of the table
        double sin_value = sin(i);
        double cos_value = cos(i);
        printf("sin(%.1lf)=%.3lf\tcos(%.1lf)=%.3lf\n", i, sin_value, i, cos_value);
    }
    printf("\n");

    return 0;
}