/*

Desenvolva um programa que solicite dois números ao usuário.
Estes números são os catetos de um triângulo retângulo. Sendo
assim, apresente ao usuário:
• Hipotenusa
• Área
• Perímetro
• Seno
• Cosseno
• Tangente

*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    
    float catetoOposto;
    float catetoAdjascente;

    cout << "Digite o valor do cateto oposto: ";
    cin >> catetoOposto;

    cout << "\nDigite o valor do cateto adjascente: ";
    cin >> catetoAdjascente;

    cout << setprecision(2) << fixed;
    float hipotenusa = sqrt(pow(catetoOposto, 2) + pow(catetoAdjascente, 2));
    cout << "\nHipotenusa: " << hipotenusa << endl;

    float area = (catetoOposto * catetoAdjascente) / 2;
    cout << "Area: " << area << endl;

    float perimetro = catetoOposto + catetoAdjascente + hipotenusa;
    cout << "Perimetro: " << perimetro << endl;

    float seno = catetoOposto / hipotenusa;
    cout << "Seno: " << seno << endl;

    float cosseno = catetoAdjascente / hipotenusa;
    cout << "Cosseno: " << cosseno << endl;

    float tangente = catetoOposto / catetoAdjascente;
    cout << "Tangente: " << tangente << endl;
    
    return 0;
}
