#include <iostream>

using namespace std;

class Point
{
public:
    Point() { x = y = 0.0; }
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    double getx() const { return x; }
    double gety() const { return y; }
    void setx(double v) { x = v; }
    void sety(double v) { y = v; }

private:
    double x, y;
};

ostream &operator<<(ostream &out, const Point &p)
{
    out << "(" << p.getx() << ", " << p.gety() << ")";
    return out;
}

const Point operator+(const Point &p1, const Point &p2)
{
    return Point(p1.getx() + p2.getx(), p1.gety() + p2.gety());
}

int main(int argc, char const *argv[])
{
    Point p1(2.5, 3.5), p2(3.75, 33.52);
    cout << "Point 1: " << p1 << endl;
    cout << "Point 2: " << p2 << endl;

    Point p3 = p1 + p2;
    cout << "Sum: " << p1 + p2 << endl;

    return 0;
}
