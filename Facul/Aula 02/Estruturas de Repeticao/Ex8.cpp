/*

Desenvolva um programa que imprima na tela a
seguinte forma:

* * * * *
* * * * *
* * * * *
* * * * *
* * * * *


*/

#include <iostream>
using namespace std;

int main() {
    
    for(int i = 0; i < 5; i++){
        cout << endl;
        for(int j = 0; j< 5; j++)
        cout << "* ";
        
    }
    cout << '\n';
    
    return 0;
}
