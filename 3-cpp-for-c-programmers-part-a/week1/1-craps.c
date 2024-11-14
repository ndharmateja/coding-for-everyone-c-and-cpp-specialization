#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6
#define R_SIDE (rand() % SIDES + 1)

void initializeArray(int *array, int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = value;
    }
}

int main(int argc, char const *argv[])
{
    // Random seed
    srand(clock());

    // Get trials
    int trials;
    if (argc == 2)
    {
        trials = atoi(argv[1]);
    }
    else
    {
        printf("\nEnter #trials: ");
        scanf("%d", &trials);
    }

    // Define counts array
    int n_dice = 3;
    int n_counts = SIDES * n_dice + 1;
    int outcomes[n_counts];
    initializeArray(outcomes, n_counts, 0);

    // Simulation
    int i;
    for (i = 0; i < trials; i++)
    {
        int sum = 0;
        for (int j = 0; j < n_dice; j++)
            sum += R_SIDE;
        outcomes[sum]++;
    }

    // Print probabilities
    for (i = n_dice; i < n_counts; i++)
    {
        printf("sum = %2d chance = %.2lf %%\n", i, 100 * ((double)outcomes[i]) / trials);
    }

    return 0;
}
