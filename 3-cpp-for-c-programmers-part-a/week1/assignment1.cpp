// Imports
#include <iostream>
#include <vector>

// Namespace
using namespace std;

// Constants
const int n = 40;

// Generic sum function
// The first and the 3rd arguments are passed by reference
template <class Summable>
inline void sum(Summable &p, int size, vector<Summable> &d)
{
    // Loop over the vector and accumulate the sum in the passed value
    p = 0;
    for (int i = 0; i < size; ++i)
    {
        p = p + d[i];
    }
}

// Main function
int main()
{
    // Variable declaration
    // Variable to store the sum and the vector
    int accum = 0;
    vector<int> data(n);

    // Initialize the vector of 'n' values
    for (int i = 0; i < n; ++i)
    {
        data[i] = i;
    }

    // Compute the sum and store the result in the 'accum' variable
    sum(accum, n, data);

    // Output the results
    cout << "sum is " << accum << endl;
    return 0;
}