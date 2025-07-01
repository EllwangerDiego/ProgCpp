/*

Solicite ao usuário que ele informe um número fracionário e o
imprima como um número inteiro e depois como um número
fracionário com três casas decimais

*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    float numero;
    cout << "Digite um numero fracionario: ";
    cin >> numero;
    int numInt = (int)numero;
    cout << "Numero inteiro: " << numInt << endl;
    cout << "Numero fracionario: " << numero << endl;
    cout << "Numero fracionario 3 casas decimais: " << setprecision(3) << fixed << numero << endl;
    
    return 0;
}
