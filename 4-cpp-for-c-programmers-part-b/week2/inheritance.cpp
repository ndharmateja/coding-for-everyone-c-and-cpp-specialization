#include <iostream>

using namespace std;

class Duo
{
protected:
    double first, second;

public:
    Duo(double first, double second) : first(first), second(second) {}
    double get_first() { return first; }
    void set_first(double t) { first = t; }
    double get_second() { return second; }
    void set_second(double t) { second = t; }
};

class Point : public Duo
{
public:
    Point() : Duo(0.0, 0.0) {}
    Point(double x, double y = 0.0) : Duo(x, y) {}
    virtual double len() { return sqrt(first * first + second * second); }
};

class Point3d : public Point
{
private:
    double z;

public:
    Point3d() : Point(), z(0.0) {}
    double len() { return sqrt(first * first + second * second + z * z); }
    void set_z(double t) { z = t; }
};

int main(int argc, char const *argv[])
{
    Point p;
    p.set_first(1.5);
    p.set_second(3);
    cout << p.len() << endl;

    Point3d p2;
    p2.set_first(3);
    p2.set_second(4);
    p2.set_z(5);
    cout << p2.len() << endl;
    return 0;
}
