#include <iostream>
#include <complex>

using namespace std;

template <class T>
void display(const T data[], int size)
{
    cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        cout << data[i];
        if (i != size - 1)
            cout << ", ";
    }
    cout << " }" << endl;
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3};
    display(a, 3);

    double b[] = {-1, 2.5, 3.75};
    display(b, 3);

    complex<double> c[] = {
        complex<double>(2.5, 3.75),
        complex<double>(-2.5, 13.75)};
    display(c, 2);

    string d[] = {"dharma", "teja", "nuli"};
    display(d, 3);

    return 0;
}
