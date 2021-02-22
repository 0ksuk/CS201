//  Devan Otton
//  CS 201
//  HW 4
//  02.21.2021

#include "tokenizer.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::istringstream;

#ifndef tokenizer_H
#define tokenizer_H

bool ReadLine(string& str);
unsigned StringToTokenWS(const string& input, vector<string>& tokens);
void AnalyzeTokens(const vector<string>& tokens);

#endif

bool ReadLine(string & str)
{
    std::getline(cin, str);
    if (str.size() == 0)
        return false;
    else
        return true;
}
unsigned StringToTokenWS(const string& str, vector<string>& tokens)
{
    istringstream instream(str);
    string s;
    int a = 0;
    while (a < str.size())
    {
        instream >> s;
        tokens.push_back(s);
        a = a + s.size() + 1;
    }
    tokens.push_back("");
    return 0;
}
void AnalyzeTokens(const vector<string>& tokens)
{
    for (int i = 0; i < tokens.size(); i++)
    {
        int noti = 0;
        string::size_type pos1 = tokens[i].find_first_of("0123456789");
        string::size_type pos2 = tokens[i].substr(0, 1).find_first_of("_0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
        string::size_type pos3 = tokens[i].find_first_of("\"");
        if (pos1 > 1000)
            noti++;
        else
            for (int j = 0; j < tokens[i].size(); j++)
            {
                if (tokens[i].substr(j, 1).find_first_of("0123456789") > 1)
                    noti++;
            }
        if (noti == 0)
            cout << "[integer]              \"" << tokens[i] << "\"" << endl;
        else if (tokens[i].size() == 0)
            cout << "[integer]              \"\"" << tokens[i] << endl;
        else if (pos3 < 10)
            cout << "[string]               \"\\" << tokens[i] << "\\\"" << endl;
        else if (pos2 < 10)
            cout << "[identifier]           \"" << tokens[i] << "\"" << endl;
        else
            cout << "[other]                \"" << tokens[i] << "\"" << endl;
    }
}
