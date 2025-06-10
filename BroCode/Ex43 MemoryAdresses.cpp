#include <iostream>
using namespace std;

// memory address = a location in memory where data is stored
// a memory address can be accessed with '&' (address-of operator)

int main() {
    
    string name = "Diego";
    int age = 19;
    bool student = true;

    cout << &name << endl;
    cout << &age << endl;
    cout << &student << endl;

    
    return 0;
}