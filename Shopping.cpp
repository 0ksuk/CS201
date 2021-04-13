//  Devan Otton
//  CS 201
//  Shopping.cpp
//  04.13.21

#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <algorithm>
using std::cout;
using std::endl;
using std::cin;
struct Record
{
    double unitPrice;
    int units;
};
void printInventory(std::map<std::string, Record>& inventory);
void buy(std::map<std::string, Record>& inventory, double& total);
void drop(std::map<std::string, Record>& inventory, double& total);
int main()
{
    std::string action;
    std::map<std::string, Record > inventory;
    inventory["Napkin"] = { 5.0,5 };
    inventory["toilet paper"] = { 50.0,4 };
    inventory["apple"] = { 1.0,15 };
    inventory["egg"] = { 3.0,10 };
    inventory["potato chip"] = { 4.0,8 };
    double total = 0;
    printInventory(inventory);
    cout << "You can 'view', 'buy', 'exit', or 'remove item'." << endl;
    while (true)
    {
        getline(cin, action);
        std::transform(action.begin(), action.end(), action.begin(), ::tolower);
        if (action == "view")
        {
            printInventory(inventory);
        }
        else if (action == "buy")
        {
            buy(inventory, total);
        }
        else if (action == "exit")
        {
            break;
        }
        else if (action == "remove item")
        {
            drop(inventory, total);
        }
        cout << "Current total is: " << total << "$" << endl;
    }
    return 0;
}
void printInventory(std::map<std::string, Record>& inventory)
{
    for (auto item : inventory)
    {
        cout << "We have " << item.second.units << " " << item.first << "s for " << item.second.unitPrice << " $ each. " << endl;
    }
}
void buy(std::map<std::string, Record>& inventory, double& total)
{
    cout << "What would you like to buy? ";
    std::string item;
    getline(cin, item);
    if (inventory[item].units > 0)
    {
        inventory[item].units -= 1;
        total += inventory[item].unitPrice;
    }
    else
    {
        cout << endl << "We are out of stock on that item." << endl;
    }
}
void drop(std::map<std::string, Record>& inventory, double& total)
{
    cout << "What would you like to remove from your cart?";
    std::string item;
    getline(cin, item);
    inventory[item].units += 1;
    total -= inventory[item].unitPrice;
}

Project("{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}") = "shopping", "shopping.vcxproj", "{E168A8B6-F5E1-4587-A6AF-D4703B999CCA}"
EndProject
Global
    GlobalSection(SolutionConfigurationPlatforms) = preSolution
        Debug|x64 = Debug|x64
        Debug|x86 = Debug|x86
        Release|x64 = Release|x64
        Release|x86 = Release|x86
    EndGlobalSection
    GlobalSection(ProjectConfigurationPlatforms) = postSolution
        {E168A8B6-F5E1-4587-A6AF-D4703B999CCA}.Debug|x64.ActiveCfg = Debug|x64
        {E168A8B6-F5E1-4587-A6AF-D4703B999CCA}.Debug|x64.Build.0 = Debug|x64
        {E168A8B6-F5E1-4587-A6AF-D4703B999CCA}.Debug|x86.ActiveCfg = Debug|Win32
        {E168A8B6-F5E1-4587-A6AF-D4703B999CCA}.Debug|x86.Build.0 = Debug|Win32
        {E168A8B6-F5E1-4587-A6AF-D4703B999CCA}.Release|x64.ActiveCfg = Release|x64
        {E168A8B6-F5E1-4587-A6AF-D4703B999CCA}.Release|x64.Build.0 = Release|x64
        {E168A8B6-F5E1-4587-A6AF-D4703B999CCA}.Release|x86.ActiveCfg = Release|Win32
        {E168A8B6-F5E1-4587-A6AF-D4703B999CCA}.Release|x86.Build.0 = Release|Win32
    EndGlobalSection
    GlobalSection(SolutionProperties) = preSolution
        HideSolutionNode = FALSE
    EndGlobalSection
    GlobalSection(ExtensibilityGlobals) = postSolution
        SolutionGuid = {9CD7EF09-62D3-40D6-A229-250AEA6FC9E1}
    EndGlobalSection
EndGlobal
