#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MIN_WEIGHT 4400
#define MAX_WEIGHT 8800

// Macros
#define RANGE 4400
#define POPULATION 25
#define WEIGHT_OVER rand() % RANGE
#define WEIGHT WEIGHT_OVER + MIN_WEIGHT

// Multiline macro
#define FILL                         \
    for (i = 0; i < POPULATION; i++) \
    data[i] = WEIGHT

void print_array(int data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", data[i]);
    }
    printf("\n\n");
}

int main(void)
{
    int i;
    int data[POPULATION];
    srand(time(0)); // Reset seed based on time of system
    FILL;
    print_array(data, POPULATION);
    return 0;
}