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
    gen g(1, 0.01);
    vector<double> v(100);
    generate(v.begin(), v.end(), g);
    for (double val : v)
        cout << val << endl;
    return 0;
}
