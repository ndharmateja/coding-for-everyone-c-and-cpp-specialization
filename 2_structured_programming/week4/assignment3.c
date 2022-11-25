#include <stdio.h>

// Reads and returns the first integer of the file
int read_size(FILE *fp)
{
    rewind(fp);
    int size;
    fscanf(fp, "%d", &size);
    return size;
}

// Reads the file data into the given array
void read_data(FILE *fp, int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        fscanf(fp, "%d", &array[i]);
    }
}

// Finds the max value of the elements in array
int get_max(int array[], int size)
{
    int max = array[0];
    for (int i = 0; i < size; i++)
        if (array[i] > max)
            max = array[i];

    return max;
}

// Finds the average of the elements in the array
double get_average(int array[], int size)
{
    double average = 0.0;
    for (int i = 0; i < size; i++)
        average += array[i];

    return average / size;
}

// Prints values to the give output stream
// If we give a file pointer, it writes to the file
// If we give "stdout" instead, it prints the values
void print_values(FILE *fp, int size, int max, double average)
{
    fprintf(fp, "Number of elements: %d\n", size);
    fprintf(fp, "Max: %d\n", max);
    fprintf(fp, "Average: %lf\n", average);
}

int main(int argc, char *argv[])
{
    // If input filename is given as arg, we use it
    // otherwise we use "input_data.txt"
    char *input_filename = argc == 1 ? "input_data.txt" : argv[1];
    char *output_filename = "answer-hw3.txt";

    // Open the files
    FILE *ifp = fopen(input_filename, "r");
    FILE *ofp = fopen(output_filename, "w");

    // Read the first integer as size
    int size = read_size(ifp);

    // Initialize array and read the data into the array
    int array[size];
    read_data(ifp, array, size);

    // Compute max and average of the array
    int max = get_max(array, size);
    double average = get_average(array, size);

    // Print values to standard output
    print_values(stdout, size, max, average);

    // Write values to the output file
    print_values(ofp, size, max, average);

    // Close the files
    fclose(ifp);
    fclose(ofp);
}