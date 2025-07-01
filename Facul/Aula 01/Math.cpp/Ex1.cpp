/*

Desenvolva um programa que solicite ao usuário o raio de um
círculo e exiba o diâmetro, circunferência e a área deste círculo na
tela

*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    float pi = 3.14159;
    float raio;
    cout << "Digite o raio de um circulo: ";
    cin >> raio;
    float diametro = raio * 2;
    cout << "Diametro: " << diametro;
    float circunferencia = 2 * pi * raio;
    cout << "\nCircunferencia: " << setprecision(2) << fixed << circunferencia << endl;
    float area = pi * pow(raio,2);
    cout << "Area: " << setprecision(2) << fixed << area << endl;

    
    return 0;
}
