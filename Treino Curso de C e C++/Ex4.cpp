//Exercicio aula 6
// Inverter valor de A para B e de B para A

#include <iostream>
#include <conio.h>
using namespace std;

int main(){
    
    int a, b, c;
    cout << "Digite aqui o valor de A: ";
    cin >> a;

    cout << "Digite o valor de B: ";
    cin >> b;

    

    cout << "Valor de A: " << a << endl;
    cout << "Valor de B: " << b << endl;
    

    c = a;
    a = b;
    b = c;

    cout << "\nValor de A invertido: " << a << endl;
    cout << "Valor de B invertido: " << b << "\n" << endl;

 

    return 0;

}