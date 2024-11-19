#include <iostream>
#include "header.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    int x = 5, y = 3;
    Test t(x, y);
    cout << t.sum() << endl;
    return 0;
}
