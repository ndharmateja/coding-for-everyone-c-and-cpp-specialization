#include <stdio.h>

int main()
{
    int sum = 0, n = 10;

    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }

    printf("Sum of first %d natural numbers: %d\n\n", n, sum);

    return 0;
}