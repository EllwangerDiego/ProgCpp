/*

Desenvolva um programa que solicite ao usuário a altura e a
largura de um retângulo e exiba o perímetro e a área deste
retângulo na tela

*/

#include <iostream>
using namespace std;

int main() {
    
    float altura;
    float largura;

    cout << "Digite a altura do retangulo: ";
    cin >> altura;
    cout << "\nDigite o lado do retangulo: ";    
    cin >> largura;
    float perimetro = (altura * 2) + (largura * 2);
    float area = largura * altura;
    cout << "Perimetro: " << perimetro << endl;
    cout << "Area: " << area << endl;
    
    return 0;
}
