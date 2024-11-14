// Imports
#include <iostream>
#include <vector>

// Namespace
using namespace std;

// Constants
const int n = 40;

// Generic sum function
template <class Summable>
inline void sum(Summable &p, int size, vector<Summable> d)
{
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
    int accum = 0;
    vector<int> data(n);

    // Compute the sum
    for (int i = 0; i < n; ++i)
    {
        data[i] = i;
    }
    sum(accum, n, data);

    // Output the results
    cout << "sum is " << accum << endl;
    return 0;
}