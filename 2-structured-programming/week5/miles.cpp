#include <iostream>
using namespace ::std;

const double MILES_TO_KM = 1.609;

// * inline => optimized functions
// * to replace macros
inline double convert(int miles) { return (miles * MILES_TO_KM); }

void take_input(int *miles)
{
    cout << "Input miles (or 0 to terminate): ";
    cin >> *miles;
}

int main(void)
{
    int miles;
    take_input(&miles);

    while (miles != 0)
    {
        cout << "Entered distance in kms: " << convert(miles) << "km" << endl
             << endl;
        take_input(&miles);
    }

    cout << endl
         << "End of program!"
         << endl;
    return 0;
}