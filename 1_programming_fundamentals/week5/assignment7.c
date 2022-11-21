#include <stdio.h>

double compute_average(int weights[], long count)
{
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += weights[i];
    }
    return (double)sum / count;
}

int *read_weights()
{
    int weights[5] = {1, 2, 3, 4, 5, 6};
    return &weights;
}

int main(void)
{
    // read weights from file
    int weights[] = *read_weights();
    printf("average: %f\n", compute_average(weights, 5));
    return 0;
}
