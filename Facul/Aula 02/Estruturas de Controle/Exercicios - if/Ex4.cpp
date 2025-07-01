/*

Solicitar dois números inteiros "a" e "b" e imprimir na tela se o
resultado da subtração entre eles ("a"-"b") resulta em número
positivo ou negativo;

*/

#include <iostream>
using namespace std;

int main() {
    
    int a;
    int b;
    
    cout << "Digite um numero: ";
    cin >> a;

    cout << "\nDigite outro numero: ";
    cin >> b;

    int resultado = a - b;

    if (resultado >= 0){
        cout << "resultado da subtração entre (a - b) resulta em número positivo " << endl;
    }
    else{
        cout << "resultado da subtração entre (a - b) resulta em número negativo " << endl;
    }

    
    
    return 0;
}
