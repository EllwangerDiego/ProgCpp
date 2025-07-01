#include <iostream>
using namespace std;

int main() {
    
    string name = "Diego";
    int age = 19;
    string freePizzas[5] = {"pizza1", "pizza2", "pizza3", "pizza4", "pizza5"};
    
    string *pName = &name;
    int *pAge = &age;
    //string *pFreePizzas = &freePizzas;

    cout << *pName << endl;
    cout << pAge << endl;
    cout << freePizzas << endl;
    
    return 0;
}
