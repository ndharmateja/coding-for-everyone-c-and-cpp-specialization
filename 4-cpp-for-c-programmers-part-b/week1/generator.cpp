#include <iostream>
#include <algorithm>

using namespace std;

class gen
{
private:
    double x, incr;

public:
    gen(double x, double incr) : x(x), incr(incr) {};
    double operator()()
    {
        x += incr;
        return x * x;
    }
};

int main(int argc, char const *argv[])
{
    gen g(1, 0.1);
    vector<double> v(10);

    for (int i = 0; i < 20; i++)
        cout << g() << endl;

    return 0;
}
