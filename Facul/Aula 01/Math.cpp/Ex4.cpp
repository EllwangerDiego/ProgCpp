/*

Desenvolva um programa que solicite dois números ao usuário e
que exiba o resultado do primeiro número elevado ao segundo, ou
seja, potência

*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    float num1;
    float num2;
    
    cout << "Digite o valor do numero 1: ";
    cin >> num1;
    cout << "Digite o valor do numero 2: ";
    cin >> num2;

    float resultado = pow(num1, num2);
    cout << "\nNumero " << num1 << " elevado a " << num2 << " = " << resultado << endl;
    
    return 0;
}
