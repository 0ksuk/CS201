//  Devan Otton
//  HW1
//  Dimond.cpp
//  1.27.2021

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int  i, j, k, space, n;
    cout << "Enter a positive integer: ";
    cin >> n;
    space = n - 1;
    cout << endl;
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= space; j++)
                cout << " ";
            space--;
            for (k = 1; k <= 2 * i - 1; k++)
                cout << "#";
            cout << endl;
        }
        space = 1;
        for (i = 1; i <= n - 1; i++)
        {
            for (j = 1; j <= space; j++)
                cout << " ";
            space++;
            for (k = 1; k <= 2 * (n - i) - 1; k++)
                cout << "#";
            cout << endl;
        }
        return 0;
    }
}
