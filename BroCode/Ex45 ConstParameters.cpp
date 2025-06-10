#include <iostream>
using namespace std;

void printInfo(const string &name, const int &age);

    // const parameter = parameter that is effectively read-only
    //                   code is more secure & conveys intent
    //                   useful for references and pointers

int main() {
    
    string name = "Diego";
    int age = 19;
    
    printInfo(name, age);

    return 0;
}
void printInfo(const string &name, const int &age){
    cout << name << endl;
    cout << age << endl;

}