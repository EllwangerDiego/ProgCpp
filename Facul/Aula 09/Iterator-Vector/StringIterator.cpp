#include <iostream>
using namespace std;

int main()
{
    string str = "String de teste";
    string::iterator it;
    for (it = str.begin(); it != str.end(); it++)
        cout << (char)toupper(*it);

    cout << '\n';
    return 0;
}