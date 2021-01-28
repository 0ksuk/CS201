//  Devan Otton
//  HW1
//  Mileskm.cpp
//  1.27.2021

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int a,b,c,large=0;
    cout << "How many numbers? (0 to end): ";
    cin >> b;
    for (a = 0; a < b; ++a)
    {
        cout << "Enter a positive integer: ";
        cin >> c;
        if (c > large)
            large = c;
    }
    cout << "The largest number is: " << large;
    return 0;
}
