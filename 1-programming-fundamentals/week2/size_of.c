#include <stdio.h>

int main()
{
    int a = 5, b = 7, c = 6;
    double average = 0.0;
    char ch = 'e';

    printf("int is %lu bytes.\n", sizeof(int));
    printf("long int is %lu bytes.\n", sizeof(long int));
    printf("char is %lu bytes.\n", sizeof(char));
    printf("float is %lu bytes.\n", sizeof(float));
    printf("double is %lu bytes.\n", sizeof(double));
    printf("long double is %lu bytes.\n", sizeof(long double));

    printf("a is %lu bytes.\n", sizeof(a));

    return 0;
}