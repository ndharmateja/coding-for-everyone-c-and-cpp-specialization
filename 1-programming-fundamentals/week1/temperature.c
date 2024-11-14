#include <stdio.h>

int main()
{
    int fahrenheit, celsius;

    printf("Enter temperature in Fahrenheit (integer): ");
    scanf("%d", &fahrenheit);

    // silent conversion or rhs from double to int as celsius is of type int
    celsius = (fahrenheit - 32) / 1.8;

    printf("%d°F is %d°C\n", fahrenheit, celsius);

    return 0;
}
