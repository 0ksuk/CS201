//  Devan Otton
//  CS 201
//  HW 2
//  02.07.2021

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

void InputNames(vector<string> & names);
bool DoesNameExist(const string & nameToFind, const vector<string> names);
void PrintNames(const vector<string> & names);

int main(int argc, char** argv)
{
    vector<string> names;
    string nameToFind;

    InputNames(names);

    cout << "Search for a name: ";
    cin >> nameToFind;
    DoesNameExist(nameToFind, names);

    PrintNames(names);
    return 0;
}
void InputNames(vector<string> & names)
{
    for (int i = 0; i < 10; i++)
    {
        string name;
        cout << "Please enter a name: ";
        std::getline(cin, name);
        names.push_back(name);
    }
    cout << "\n" << endl;
}
void PrintNames(const vector<string> & names)
{
    cout << "List of names: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << names[i] << endl;
    }
    int longest_name = 0;
    string name;
    cout << "\nThe name with the most letters is: " << endl;
    for (int i = 0; i < 10; i++)
    {
        if (names[i].size() > longest_name)
        {
            longest_name = names[i].size();
            name = names[i];
        }
    }
    cout << name;
}
bool DoesNameExist(const string & nameToFind, const vector<string> names)
{
    for (int i = 0; i < 10; i++)
    {
        if (nameToFind == names[i])
        {
            cout << "Name found on line " << i << ": " << names[i] << endl;
            return true;
        }
    }
    cout << "Name does not exist." << endl;
    return false;
}
