#include <stdio.h>

int main()
{
    float a, b, c, sum;
    printf("Input 3 floats: ");
    scanf("%f%f%f", &a, &b, &c);
    printf("a: %.1f, b: %.1f, c: %.1f, a + b + c: %.1f\n\n", a, b, c, a + b + c);
    return 0;
}