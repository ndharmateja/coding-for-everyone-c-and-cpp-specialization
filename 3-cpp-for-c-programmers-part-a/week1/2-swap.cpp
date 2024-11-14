#include <iostream>

using namespace std;

void swap(int &i, int &j)
{
    int temp = i;
    i = j;
    j = temp;
}

int main(int argc, char const *argv[])
{
    int x = 5, y = 10;
    cout << "Before swap" << endl
         << "x: " << x << endl
         << "y: " << y << endl
         << endl;
    swap(x, y);
    cout << "After swap" << endl
         << "x: " << x << endl
         << "y: " << y << endl
         << endl;

    return 0;
}
