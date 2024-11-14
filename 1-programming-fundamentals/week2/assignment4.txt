#include <stdio.h>
#include <math.h>

int main(void)
{
    // Declarations
    double x = 0.75, sin_value;

    // Compute the sin value of the given input
    sin_value = sin(x);

    // Print the sin value
    printf("sin(%lf) = %lf\n", x, sin_value);
}