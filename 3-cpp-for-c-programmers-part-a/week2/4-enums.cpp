#include <iostream>

using namespace std;

typedef enum days
{
    SUN,
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT
} days;

days &operator++(days &d)
{
    d = static_cast<days>((static_cast<int>(d) + 1) % 7);
    return d;
}

ostream &operator<<(ostream &out, days &d)
{
    switch (d)
    {
    case SUN:
        out << "Sunday";
        break;
    case MON:
        out << "Monday";
        break;
    case TUE:
        out << "Tuesday";
        break;
    case WED:
        out << "Wednesday";
        break;
    case THU:
        out << "Thursday";
        break;
    case FRI:
        out << "Friday";
        break;
    case SAT:
        out << "Saturday";
        break;

    default:
        break;
    }

    return out;
}

int main(int argc, char const *argv[])
{
    days d = SUN;
    cout << d << endl;

    days e = ++d;
    cout << d << "\t" << e << endl;

    return 0;
}
