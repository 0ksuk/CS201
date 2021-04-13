//  Devan Otton
//  CS 201
//  Caesar-cypher.cpp
//  04.13.21

include <string>
#include <iostream>
#include <sstream>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::istringstream;

using std::vector;

unsigned StringToTokenWS(const string& user_string, vector<string>& tokens);

int main()
{
    string user_string;
    string cypher_shift_str;
    int cypher_shift_val;
    cout << "Caesar Cypher" << endl;
    cout << endl;
    while (true)
    {
        vector<string> tokens;
        // Takes users line
        cout << "Enter a message to cypher: ";
        std::getline(cin, user_string);
        if (user_string.size() == 0) // Checks if line is blank
            break;
        else
            StringToTokenWS(user_string, tokens);
        // Asks for an amount to shift the characters over
        cout << "Enter an integer to use as the shift: ";
        while (true)
        {
            std::getline(cin, cypher_shift_str);
            istringstream instream(cypher_shift_str);
            instream >> cypher_shift_val;
            if (instream) // Confirms if there is an int value in cypher_shift_str
                break;
            else
                cout << "You need to enter an integer: ";
        }

        // Makes cypher_shift_val positive to prevent problems when changing char values
        while (cypher_shift_val < 0)
            cypher_shift_val += 26;

        // Divides the tokens into chars and outputs them onto the console
        char c;
        cout << endl;
        cout << "Cyphered message: ";
        for (size_t i = 0; i < tokens.size(); i++)
        {
            istringstream instream(tokens[i]);
            for (size_t j = 0; j < tokens[i].size(); j++)
            {
                instream >> c;
                if (c > 96)
                    if (c < 123)
                        c = 97 + ((c - 97 + cypher_shift_val) % 26);
                if (c < 91)
                    if (c > 64)
                        c = 65 + ((c - 65 + cypher_shift_val) % 26);
                cout << c;
            }
            cout << " ";
        }
        cout << endl;
        cout << endl;
    }
}

// Takes the inputted string and divides it into tokens.
unsigned StringToTokenWS(const string& user_string, vector<string>& tokens)
{
    istringstream instream(user_string);
    string s;
    int n = 0;
    while (n < user_string.size()) // This is used to add all of the parts of
                                   // the inputed string or line into the vector tokens.
    {
        instream >> s;
        tokens.push_back(s);
        n = n + s.size() + 1; // Here the part's size and the space after it are added to n.
    }                          // When (n > size of str) then the while loop stops.
    tokens.push_back("");
    return 0;
}
