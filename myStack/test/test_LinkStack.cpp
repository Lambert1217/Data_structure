#include <iostream>
#include "LinkStack.hpp"

using namespace std;

int main()
{
    LinkStack<const char *> LStack;
    LStack.push("!");
    LStack.push("World");
    LStack.push(" ");
    LStack.push("Hello");

    cout << "LStack length : " << LStack.length() << endl;
    // LStack.clear();
    // while (LStack.length())
    // {
    //     cout << LStack.topValue();
    //     LStack.pop();
    // }
    // cout << endl;

    while (LStack.length())
    {
        cout << LStack.pop();
    }
    cout << endl;
    return 0;
}