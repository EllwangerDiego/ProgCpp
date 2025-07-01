/*

Solicitar dois números inteiros "a" e "b" e imprimir na tela se o
primeiro é perfeitamente divisível pelo segundo ("a"/"b"), sem gerar
resto;


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

    if( a % b == 0){
        cout << "Numero perfeitamento divisivel pelo segundo, sem gerar resto" << endl;
    }
    else{
        cout << "Numero gera resto" << endl;
    }
    
    return 0;
}
