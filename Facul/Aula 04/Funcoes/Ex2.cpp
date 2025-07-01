/*

Faça uma função chamada “ehPositivo” que recebe um número
como parâmetro. Deverá retornar 1 (true) caso o parâmetro seja
positivo ou zero e retornar 0 (false) caso o número seja negativo.
Imprimir a partir do “main” o resultado da função;

*/



#include <iostream>
using namespace std;

bool ehPositivo(float x);

int main() {
    float numero;
    cout << "Digite um numero: ";
    cin >> numero;

    int resultado = ehPositivo(numero);

    if(resultado == 1){
        cout << "Numero positivo" << endl;
    }
    else{
        cout << "Numero negativo" << endl;
    }
    
    return 0;
}
bool ehPositivo(float x){
    if(x >= 0){
        return true;
    }
    else{
        return false;
    }
}
