#include <iostream>
#include <complex>

using namespace std;

template <class T>
T subtract(const T data[], int size, T init = 0)
{
    for (int i = 0; i < size; i++)
    {
        init -= data[i];
    }
    return init;
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3};
    cout << subtract(a, 3) << endl;
    cout << subtract(a, 3, 10) << endl;

    double b[] = {-1, 2.5, 3.75};
    cout << subtract(b, 3) << endl;
    cout << subtract(b, 3, 10.0) << endl;

    complex<double> c[] = {complex<double>(2.5, 3.75), complex<double>(-2.5, 13.75)};
    cout << subtract(c, 2) << endl;

    return 0;
}
