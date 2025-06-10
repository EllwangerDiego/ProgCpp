#include <iostream>
using namespace std;

int main(){

    string name;

    while(name.empty()){
        cout << "Digite seu nome: ";
        getline(cin, name);
    }

    cout << "Hello " << name;

    //Infinite loop example
    while( 1 == 1 ){
        cout << "INFINITE";
    }

    return 0;
}