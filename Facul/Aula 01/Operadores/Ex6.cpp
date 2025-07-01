/*

Implementar um programa que solicite um número ao
usuário. Sendo este número uma temperatura em graus
Fahrenheit, faça um programa para converter esta
temperatura em graus Celsius e exiba o resultado na tela. C
= (F - 32) / 1.8

*/

#include <iostream>
using namespace std;

int main() {
    
    float fahrenheit;
    cout << "Digite uma temperatura em fahrenheit: ";
    cin >> fahrenheit;
    float celsius = (fahrenheit - 32) / 1.8;
    cout << "Celsius: " << celsius;  
    
    return 0;
}
