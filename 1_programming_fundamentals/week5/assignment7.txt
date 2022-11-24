#include <stdio.h>
#include <stdlib.h>

// Eg: 393 and '5' will return 3935
int add_digit(int value, char c)
{
    return (10 * value) + ((int)(c - 48));
}

int main(void)
{

    // Maintain running totals for sum and count
    long int sum = 0;
    long int count = 0;

    // variable to store curr number
    int currNumber = 0;

    // Loop over all the characters of the given file
    while (1)
    {
        // variable to store the current character
        char c = getchar();

        // If character is a digit
        // we append it to the current number
        if (c >= '0' && c <= '9')
        {
            currNumber = add_digit(currNumber, c);
        }

        // otherwise we add the current number to our sum
        // and increment count by 1
        // and make currNumber to be 0
        else
        {
            if (currNumber != 0)
            {
                count++;
                sum += currNumber;
                currNumber = 0;
            }
        }

        // if char is EOF
        // we exit the loop
        if (c == EOF)
        {
            break;
        }
    }

    // print the average
    printf("Average: %lf\n", (double)sum / count);

    return 0;
}
