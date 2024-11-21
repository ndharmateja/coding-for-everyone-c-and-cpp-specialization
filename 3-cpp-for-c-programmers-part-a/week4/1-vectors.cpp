#include <iostream>

using namespace std;

void print(vector<int> &lst)
{
    cout << "{ ";
    for (auto it = lst.begin(); it != lst.end(); it++)
        cout << *it << " ";
    cout << "}" << endl;
}

int main(int argc, char const *argv[])
{
    // Assign values using iterator
    vector<int> lst(10);
    int i = 0;
    for (auto it = lst.begin(); it != lst.end(); it++)
        *it = ++i;
    print(lst);
    cout << endl;

    // Create lst2 from lst's iterator
    cout << "Created lst2 from lst's iterator" << endl;
    vector<int>::iterator start = lst.begin(), end = lst.end();
    vector<int> lst2(start, end);
    print(lst2);
    cout << endl;

    // Increment values by 2 in lst2 using for-each
    cout << "Incremented lst2 values by 2" << endl;
    for (int &val : lst2)
        val += 2;
    print(lst2);
    cout << endl;

    // Resizing lst2
    lst2.resize(2 * lst2.size());
    for (int i = 0; i < lst2.size(); i++)
        lst2[i] = i * i + 1;
    print(lst2);

    return 0;
}
