/*

Desenvolva um programa que imprima na tela a
seguinte forma:
*
* *
* * *
* * * *
* * * * *

*/

#include <iostream>
using namespace std;

int main() {

    for(int i = 0; i < 5; i++){
        cout << endl;
        for(int j = i; j >= 0; j--){
            cout << "* ";
        }
    }
    
    return 0;
}
