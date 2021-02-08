//  Devan Otton
//  CS 201
//  HW 3
//  02.07.2021

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

double convert(double t)
{
    double k = t + 273.15;
    return k;
}
int main()
{
    double t = 0;
    cout << "Enter a temperature in Celsius to convert to Kelvin: ";
    cin >> t;

    double k = convert(t);
    if (k < 0)
    {
        cout << "This temperature is not possible.";
        return 0;
    }
    cout << k << endl;
}
