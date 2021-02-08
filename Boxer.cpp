//  Devan Otton
//  CS 201
//  HW 3
//  02.07.2021

#include <iostream>
#include <vector>
#ifndef BOXER_H
#define BOXER_H
#endif

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

string box(string s, int n)
{
    string star = "";
    string layers;
    string message = "";

    string wid = "";
    for (int i = 0; i < n; i++)
    {
        wid += "*";
    }

    if (n != 0)
    {
        star = "**";
        for (int i = 0; i < s.size(); i++)
        {
            star += "*";
        }
        star = wid + star + wid;
        if (n > 1)
        {
            for (int i = 0; i < n; i++)
            {
                layers += star;

                if (i < n - 1)
                    layers += "\n";
            }
            star = layers;
        }
    }

    message += wid + " ";
    for (int i = 0; i < s.size(); i++)
    {
        message += " ";
    }
    message += " " + wid;

    message += "\n" + wid + " " + s + " " + wid + "\n";

    message += wid + " ";
    for (int i = 0; i < s.size(); i++)
    {
        message += " ";
    }
    message += " " + wid;
    return star + "\n" + message + "\n" + star;
}
int main()
{
    string s;
    int n;

    while (s != "exit")
    {
        cout << "Enter a Message (type 'exit' to stop): " << endl;
        cin >> s;
        if (s == "exit")
        {
            break;
        }
        cout << "Enter a positive integer: ";
        cin >> n;
        while (n < 0)
        {
            cout << "Please enter a positive integer: ";
            cin >> n;
        }
        cout << box(s, n) << endl;
    }
    return 0;
}
