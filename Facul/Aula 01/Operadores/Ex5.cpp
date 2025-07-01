/*

 Implementar um programa que solicite um número ao
usuário. Sendo este número uma temperatura em graus
Celsius, faça um programa para converter esta temperatura
em graus Fahrenheit e exiba o resultado na tela. F = C * 1.8
+ 32


*/
#include <iostream>
using namespace std;

int main() {
    
    float celsius;

    cout << "Digite uma temperatura em celsius: ";
    cin >> celsius;

        float fahrenheit = (celsius * 1.8) + 32;
        cout << "Fahrenheit: " << fahrenheit;
    
    return 0;
}
