#include <stdio.h>

int main(void)
{
    const int SIZE = 5;
    int grades[SIZE] = {78, 67, 92, 83, 88};
    double sum = 0.0;
    for (int i = 0; i < SIZE; i++)
    {
        sum += grades[i];
    }
    printf("Average grade: %.2f\n", sum / SIZE);

    return 0;
}