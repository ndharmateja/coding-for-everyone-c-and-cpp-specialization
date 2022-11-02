#include <stdio.h>

int main()
{
    int miles, yards;
    double kilometers;

    printf("Enter miles (integer): ");
    scanf("%d", &miles);

    printf("Enter yards (integer): ");
    scanf("%d", &yards);

    kilometers = 1.609 * (miles + yards / 1760.0);
    printf("\n%d miles %d yards is %.2lf km\n", miles, yards, kilometers);

    return 0;
}