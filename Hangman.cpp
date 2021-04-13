//  Devan Otton
//  CS 201
//  Hangman.cpp
//  04.13.21

include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

void blankSpace(vector<string>& blank) // Prints underscores for the letters that havent been revealed
{
    for_each(blank.begin(), blank.end(), [](string a) {cout << a; });
}
void showLetter(vector<string>& answer, vector<string>& blank, string guess)
{
    vector<string>::iterator it = find(answer.begin(), answer.end(), guess);
    blank[it - answer.begin()] = guess;
}
bool isCorrect(vector<string> answer, string guess) // Determines if guess is correct
{
    if (find(answer.begin(), answer.end(), guess) != answer.end())
    {
        return true;
    }
    return false;
}
bool alreadyGuessed(map<string, int>& usedGuesses, string guess)
{
    map<string, int>::iterator it = usedGuesses.find(guess);
    if (it != usedGuesses.end())
    {
        return true;
    }
    else
        return false;
}
bool AllLettersFound(vector<string>& answer, vector<string>& blank)
{
    if (answer == blank)
    {
        return true;
    }
    else
        return false;
}
int main()
{
    vector<string> answer{ "s","k","y" };
    vector<string> blank{ "_","_","_" };
    string guess; //The letter guessed
    map<string, int> usedGuesses; // Stores letters used in guesses.
    int attempts = answer.size() * 2; // Gets 6 tries
    int win = 0;
    cout << "*WELCOME TO THE GAME OF HANGMAN*" << endl << endl;
    while (attempts != 0 && win == 0)
    {
        cout << "Attempts left: " << attempts << endl;
        blankSpace(blank);
        cout << endl << "Guess a letter or the word: ";
        getline(cin, guess);
        if (alreadyGuessed(usedGuesses, guess))
        {
            cout << "You already guessed that! Type in a different letter." << endl;
            continue;
        }
        if (guess.length() == 1) // determines if the guess is a letter or a word
        {
            if (isCorrect(answer, guess))
            {
                cout << guess << " is correct! " << endl;
                usedGuesses[guess] = attempts;
                attempts--;
                showLetter(answer, blank, guess);
            }
            else
            {
                cout << guess << " is incorrect." << endl;
                usedGuesses[guess] = attempts;
                attempts--;
            }
        }
        // Will end loop if correct
        else if (guess == "sky")
        {
            cout << "Correct! The answer is sky!" << endl;
            win = 1;
        }
        else
        {
            cout << guess << " is incorrect. " << endl;
            usedGuesses[guess] = attempts;
            attempts--;
        }
        if (AllLettersFound(answer, blank))
        {
            cout << "The word is complete! The answer is sky!" << endl;
            win = 1;
        }
    }
    if (attempts == 0)
    {
        cout << "You're all out of attempts! Try again!";
    }
}
Project("{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}") = "hangman", "hangman.vcxproj", "{C023C2EA-66E0-4805-B211-5A08D6C6659B}"
EndProject
Global
    GlobalSection(SolutionConfigurationPlatforms) = preSolution
        Debug|x64 = Debug|x64
        Debug|x86 = Debug|x86
        Release|x64 = Release|x64
        Release|x86 = Release|x86
    EndGlobalSection
    GlobalSection(ProjectConfigurationPlatforms) = postSolution
        {C023C2EA-66E0-4805-B211-5A08D6C6659B}.Debug|x64.ActiveCfg = Debug|x64
        {C023C2EA-66E0-4805-B211-5A08D6C6659B}.Debug|x64.Build.0 = Debug|x64
        {C023C2EA-66E0-4805-B211-5A08D6C6659B}.Debug|x86.ActiveCfg = Debug|Win32
        {C023C2EA-66E0-4805-B211-5A08D6C6659B}.Debug|x86.Build.0 = Debug|Win32
        {C023C2EA-66E0-4805-B211-5A08D6C6659B}.Release|x64.ActiveCfg = Release|x64
        {C023C2EA-66E0-4805-B211-5A08D6C6659B}.Release|x64.Build.0 = Release|x64
        {C023C2EA-66E0-4805-B211-5A08D6C6659B}.Release|x86.ActiveCfg = Release|Win32
        {C023C2EA-66E0-4805-B211-5A08D6C6659B}.Release|x86.Build.0 = Release|Win32
    EndGlobalSection
    GlobalSection(SolutionProperties) = preSolution
        HideSolutionNode = FALSE
    EndGlobalSection
    GlobalSection(ExtensibilityGlobals) = postSolution
        SolutionGuid = {B4E91C1B-9554-4FC3-8E95-7B5C90AB02FA}
    EndGlobalSection
EndGlobal
