#include <stdio.h>
#include <math.h>

int main()
{
    double x, sin_value;
    printf("Enter a value between 0 and 1: ");
    scanf("%lf", &x);

    sin_value = sin(x);
    printf("sin(%lf) = %lf\n", x, sin_value);
}