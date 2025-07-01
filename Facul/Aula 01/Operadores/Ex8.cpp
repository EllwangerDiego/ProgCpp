/*

Implemente um programa que solicite ao usuário o valor de
um calçado e o percentual de desconto. Em seguida, calcule
o valor do desconto e o valor final a ser pago pelo calçado.

*/

#include <iostream>
using namespace std;

int main() {
    
    float valor;
    float desconto;
    cout << "Digite o valor: ";
    cin >> valor;
    cout << "\nDigite o desconto: ";
    cin >> desconto;

    float valorDesconto = valor * (desconto/100);
    cout << "Valor desconto: " << valorDesconto << endl;
    float valorFinal = valor - valorDesconto;
    cout << "Valor final com desconto: " << valorFinal << endl;

    
    return 0;
}
