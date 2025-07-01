/*

Desenvolva um programa que imprima na tela uma sequência de
“n” números fracionários, iniciando com um número “i” e sendo
incrementados por um número “m”. Peça para o usuário informar
os valores de “n”, “m” e “i” antes de gerar a sequência.
Ex: “n” = 6, “m” = 0,3 e “i” = -1; sequência = -1,0 -0,7 -0,4 -0,1
0,2 0,5;

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    int n;
    float i;
    float m;
    
    
    cout << "Digite quantos numeros: ";
    cin >> n;

    cout << "\nDigite o valor inicial: ";
    cin >> i;
    float resultado = i;

    cout << "\nDigite o valor para incrementar: ";
    cin >> m;

    cout << setprecision(1) << fixed;
    for (int j = 0; j < n; j++) {
        cout << resultado << "\t";
        resultado += m;
    }
    
    return 0;
}
