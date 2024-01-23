#include <iostream>
#include "ArrayStack.hpp"
#include <string>

using namespace std;

int main()
{
    ArrayStack<const char *> AStack(5);
    AStack.push("!");
    AStack.push("World");
    AStack.push(" ");
    AStack.push("Hello");

    cout << "AStack length : " << AStack.length() << endl;
    // AStack.clear();
    while (AStack.length())
    {
        cout << AStack.topValue();
        AStack.pop();
    }
    cout << endl;

    // while (AStack.length())
    // {
    //     cout << AStack.pop();
    // }
    // cout << endl;
    return 0;
}