/*

Solicitar um número inteiro "a" e imprimir na tela se ele é par ou
ímpar;

*/

#include <iostream>
using namespace std;

int main() {
    
    int a;
    
    cout << "Digite um numero inteiro: ";
    cin >> a;

    if (a % 2 == 0){
        cout << "Numero eh par" << endl;
    }
    else{
        cout << "Numero impar" << endl;
    }
    
    return 0;
}
