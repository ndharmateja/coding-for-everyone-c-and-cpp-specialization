// Imports
#include <iostream>
#include <vector>

// Namespace
using namespace std;

// Constants
const int n = 40;

// Sum function
inline void sum(int *p, int n, vector<int> d)
{
    *p = 0;
    for (int i = 0; i < n; ++i)
    {
        *p = *p + d[i];
    }
}

// Main function
int main()
{
    // Variable declaration
    int accum = 0;
    vector<int> data(n);

    // Compute the sum
    for (int i = 0; i < n; ++i)
    {
        data[i] = i;
    }
    sum(&accum, n, data);

    // Output the results
    cout << "sum is " << accum << endl;
    return 0;
}