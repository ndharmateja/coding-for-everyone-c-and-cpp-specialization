#include <stdio.h>

void print_array(int data[], int size, char *str)
{
    printf("%s\n", str);
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", data[i]);
    }
    printf("\n\n");
}

void merge(int a[], int b[], int c[], int size)
{
    int i = 0, j = 0, k = 0;
    while (i < size && j < size)
    {
        c[k++] = a[i] < b[j] ? a[i++] : b[j++];
    }
    while (i < size)
    {
        c[k++] = a[i++];
    }
    while (j < size)
    {
        c[k++] = b[j++];
    }
}

int main(void)
{
    const int SIZE = 5;
    int a[SIZE] = {5, 10, 15, 20, 30};
    int b[SIZE] = {12, 14, 27, 33, 45};
    int c[2 * SIZE];

    merge(a, b, c, SIZE);

    print_array(a, SIZE, "My grades");
    print_array(b, SIZE, "More grades");
    print_array(c, 2 * SIZE, "Sorted grades");
    return 0;
}