//  Devan Otton
//  CS 201
//  HW 4
//  02.21.2021

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

string str;
string item;
string answer;
vector<string> container;
vector<string> test{ "A" , "B" , "C" , "D" };
int fifolifo;
int fifo;
int lifo;
int yes_no = 1;
int finish = 1;
int confirm_test;
bool b;

void FifoPush(vector<string>& container, const string& item);
void FifoPop(vector<string>& container, string& item);
void LifoPush(vector<string>& container, const string& item);
void LifoPop(vector<string>& container, string& item);

bool IsContainerEmpty(const vector<string>& container);
void PrintContainer(const vector<string>& container);

bool TestFifo();
bool TestLifo();

int main()
{
    cout << "Would you like to fill a container? Type \"Yes\" if you do. Or type \"test\" to access the testing functions." << endl;
    cin >> answer;
    if (answer == "yes")
        finish = 0;
    else if (answer == "Yes")
        finish = 0;
    else if (answer == "YES")
        finish = 0;
    else if (answer == "test")
        finish = 2;
    else
        cout << "Oh, okay... Bye then.";
    cout << endl;

    if (finish == 0)
    {
        cout << "Hello, welcome to your container." << endl;
        cout << "\nHow would you like to fill your container?" << endl;
        cout << "With Fifo (First-In First-Out) or with Lifo (Last-In First-Out)?" << endl;
        cout << "Enter \"Fifo\" for Fifo or \"Lifo\" for Lifo: ";
        while (true)
        {
            if (fifolifo > 0)
                cout << "Please enter \"Fifo\" or \"Lifo\"." << endl;
            cin >> str;
            if (str == "Fifo")
                break;
            if (str == "Lifo")
                break;
            fifolifo++;
        }
        cout << endl;
        if (str == "Fifo")
        {
            cout << "You chose Fifo. Enter something to place in your container: ";
            yes_no = 1;
            while (yes_no != 0)
            {
                if (fifo > 0)
                    cout << "Enter another item to place in your container: ";

                cin >> item;
                FifoPush(container, item);

                cout << "Would you like to add another item? Enter \"1\" for yes or \"0\" for no: ";
                cin >> yes_no;

                fifo++;
            }
            yes_no = 1;
            while (yes_no != 0)
            {
                cout << endl;
                cout << "Would you like to \"Pop\" the last item out of your container? Enter \"1\" for yes or \"0\" for no: ";
                cin >> yes_no;
                if (yes_no == 1)
                {
                    if (container.size() == 0)
                    {
                        cout << "Your container is empty.";
                        break;
                    }
                    cout << "Your last item was: ";
                    FifoPop(container, item);
                }
            }
        }
        else if (str == "Lifo")
        {
            cout << "You chose Lifo. Enter something to place in your container: ";
            yes_no = 1;
            while (yes_no != 0)
            {
                if (lifo > 0)
                    cout << "Enter another item to place in your container: ";
                cin >> item;
                LifoPush(container, item);
                cout << "Would you like to add another item? Enter \"1\" for yes or \"0\" for no: ";
                cin >> yes_no;
                lifo++;
            }
            yes_no = 1;
            while (yes_no != 0)
            {
                cout << endl;
                cout << "Would you like to \"Pop\" the last item out of your container? Enter \"1\" for yes or \"0\" for no: ";
                cin >> yes_no;
                if (yes_no == 1)
                {
                    if (container.size() == 0)
                    {
                        cout << "Your container is empty.";
                        break;
                    }
                    cout << "Your last item was: ";
                    LifoPop(container, item);
                }
            }
        }
        finish = 3;
        cout << "Do want to know what is in your container? Type: yes or no: ";
        while (finish != 0)
        {
            cin >> answer;
            if (answer == "yes")
                finish = 0;
            else if (answer == "Yes")
                finish = 0;
            else if (answer == "YES")
                finish = 0;
            else if (answer == "no")
            {
                finish = 1;
                break;
            }
            else if (answer == "No")
            {
                finish = 1;
                break;
            }
            else if (answer == "NO")
            {
                finish = 1;
                break;
            }
            else
                cout << "Please type: yes or no: ";

            if (finish == 0)
            {
                b = IsContainerEmpty(container);
                if (b)
                    cout << "Your container is empty." << endl;
                else
                {
                    cout << "These are the items in your container: " << endl;
                    PrintContainer(container);
                }
                break;
            }
        }
    }
    if (finish == 2)
    {
        fifolifo = 0;
        cout << "Enter \"Fifo\" to test Fifo or \"Lifo\" to test Lifo: ";
        while (true)
        {
            b = false;
            yes_no = 0;
            if (fifolifo > 0)
                cout << "Please enter \"Fifo\" or \"Lifo\"." << endl;
            cin >> str;
            if (str == "Fifo")
                b = TestFifo();
            if (str == "Lifo")
                b = TestLifo();
            if (b)
                cout << "The container was filled and emptied properly." << endl; // works
            else
                cout << "There was a problem. " << endl; // doesn't work
            cout << endl;
            cout << "If you want to test the other one, enter \"1\" for yes or \"0\" for no: ";
            cin >> yes_no;
            if (yes_no == 0)
                break;
            fifolifo++;
        }
    }
    int q;
    cout << endl;
    cout << "Program has finished. Enter a character to return: ";
    cin >> q;
    return 0;
}
void FifoPush(vector<string>& container, const string& item)
{
    int container_size = container.size();
    if (container_size > 0)
    {
        container.resize(container_size + 1);
        for (int i = (container_size); i > 0; i--)
        {
            container[i] = container[i - 1];
        }
        container[0] = item;
    }
    else
        container.push_back(item);
}
void FifoPop(vector<string>& container, string& item)
{
    cout << container.back() << endl;
    container.pop_back();
}

void LifoPush(vector<string>& container, const string& item)
{
    container.push_back(item);
}
void LifoPop(vector<string>& container, string& item)
{
    cout << container.back() << endl;
    container.pop_back();
}
bool IsContainerEmpty(const vector<string>& container)
{
    if (container.size() == 0)
        return true;
    else
        return false;
}
void PrintContainer(const vector<string>& container)
{
    for (int i = 0; i < container.size(); i++)
        cout << container[i] << endl;
}
bool TestFifo()
{
    confirm_test = 0;
    for (int i = 0; i < test.size(); i++)
    {
        item = test[i];
        FifoPush(container, item);
    }
    if (container[3] == test[0])
        confirm_test++;
    if (container[2] == test[1])
        confirm_test++;
    if (container[1] == test[2])
        confirm_test++;
    if (container[0] == test[3])
        confirm_test++;
    for (int i = 0; i < test.size(); i++)
    {
        FifoPop(container, item);
    }
    if (container.size() > 0)
        confirm_test = 0;
    if (confirm_test == 4)
        return true;
    else
        return false;
}
bool TestLifo()
{
    confirm_test = 0;
    for (int i = 0; i < test.size(); i++)
    {
        item = test[i];
        LifoPush(container, item);
    }
    if (container[0] == test[0])
        confirm_test++;
    if (container[1] == test[1])
        confirm_test++;
    if (container[2] == test[2])
        confirm_test++;
    if (container[3] == test[3])
        confirm_test++;
    for (int i = 0; i < test.size(); i++)
    {
        LifoPop(container, item);
    }
    if (container.size() > 0)
        confirm_test = 0;
    if (confirm_test == 4)
        return true;
    else
        return false;
}
