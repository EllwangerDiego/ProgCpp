/*

Implementar um programa que solicite um número ao
usuário. Sendo este número uma velocidade em km/h, faça
um programa para converter esta velocidade em m/s e exiba
o resultado na tela


*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    float km;
    cout << "Digite um km/h: ";
    cin >> km;
    float ms = km / 3.6;
    cout << "m/s: " << setprecision(2) << fixed << ms << endl;    
    
    return 0;
}
