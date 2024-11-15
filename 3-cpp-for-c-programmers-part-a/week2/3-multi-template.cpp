#include <iostream>
#include <complex>

using namespace std;

template <class E, class F>
void copy(const E src[], F dest[], int size)
{
    for (int i = 0; i < size; i++)
        dest[i] = static_cast<F>(src[i]);
}

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
    int size = 3;
    int a[] = {1, 2, 3};
    double b[size];
    copy(a, b, size);
    display(a, size);
    display(b, size);

    return 0;
}
