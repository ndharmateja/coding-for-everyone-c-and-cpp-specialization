#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int sides = 6;
inline int r_sides() { return rand() % sides + 1; }

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
        cout << endl
             << "Enter #trials: ";
        cin >> trials;
    }

    // Define counts array
    const int n_dice = 3;
    const int n_counts = sides * n_dice + 1;
    int outcomes[n_counts];
    initializeArray(outcomes, n_counts, 0);

    // Simulation
    for (int i = 0; i < trials; i++)
    {
        int sum = 0;
        for (int j = 0; j < n_dice; j++)
            sum += r_sides();
        outcomes[sum]++;
    }

    // Print probabilities
    for (int i = n_dice; i < n_counts; i++)
    {
        double percent = 100 * static_cast<double>(outcomes[i]) / trials;
        cout << "sum = " << i << "; "
             << "chance = " << percent << " %"
             << endl;
    }

    return 0;
}
