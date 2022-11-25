#include <stdio.h>

void print_array(int array[], int size)
{
    printf("{");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", array[i]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }

    printf("}\n\n");
}

double average(int array[], int size)
{
    double average = 0.0;
    for (int i = 0; i < size; i++)
    {
        average += array[i];
    }

    return average / size;
}

void read_data(FILE *fp, int array[], int *size)
{
    *size = 0;
    while (fscanf(fp, "%d", &array[*size]) == 1)
    {
        (*size)++;
    }
}

int main(void)
{
    int size = 1000;
    int array[size];

    FILE *ifp;
    ifp = fopen("scores.txt", "r");
    read_data(ifp, array, &size);
    fclose(ifp);

    printf("My %d values are:\n", size);
    print_array(array, size);
    printf("Average: %lf\n", average(array, size));
}