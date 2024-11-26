#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void increment(int &i)
{
    static int n = 1;
    i += n++;
}
void output(int i) { cout << i << endl; }

int main(int argc, char const *argv[])
{
    vector<int> v(6);
    for_each(v.begin(), v.end(), increment);
    for_each(v.begin(), v.end(), output);

    copy(v.begin(), v.begin() + 3, v.begin() + 3);
    for_each(v.begin(), v.end(), output);
    return 0;
}
