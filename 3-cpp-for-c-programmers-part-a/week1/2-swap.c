#include <stdio.h>

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

int main(int argc, char const *argv[])
{
    int x = 5, y = 10;
    printf("Before swap\nx: %d\ny: %d\n\n", x, y);
    swap(&x, &y);
    printf("After swap\nx: %d\ny: %d\n", x, y);

    return 0;
}
