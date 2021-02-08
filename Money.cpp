//  Devan Otton
//  CS 201
//  HW 2
//  02.07.2021

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int pennies;
int nickels;
int dimes;
int quarters;
int dollars;

void money(int amount, string moneyplural, string money);
int main()
{
    cout << "How many pennies do you have?" << endl;
        cin >> pennies;
    cout << "How many nickels do you have?" << endl;
        cin >> nickels;
    cout << "How many dimes do you have?" << endl;
        cin >> dimes;
    cout << "How many quarters do you have?" << endl;
        cin >> quarters;
    cout << "How many dollars do you have?" << endl;
        cin >> dollars;

    money(pennies, "Pennies", "Penny");
    money(nickels, "Nickels", "Nickel");
    money(dimes, "Dimes", "Dime");
    money(quarters, "Quarters", "Quarter");
    money(dollars, "Dollars\n", "Dollar\n");

    double total = pennies * 0.01 + nickels * 0.05 + dimes * 0.10 + quarters * 0.25 + dollars * 1.00;
    cout << "Total amount of money is: $" << total << endl;
}

void money(int amount, string moneyplural, string moneysingle)
{
    if (amount < 0)
    {
        cout << "Negative values were given" << endl;
        return;
    }
    cout << "You have: " << amount << " ";
    if (amount == 1)
    {
        cout << moneysingle << endl;
    }
    else
    {
        cout << moneyplural << endl;
    }
}
