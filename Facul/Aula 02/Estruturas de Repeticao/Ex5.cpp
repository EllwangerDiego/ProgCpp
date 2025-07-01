/*

Desenvolva um programa que imprima na tela uma sequência
com os “n” primeiros números fracionários múltiplos de 0,5
iniciando em 1,5. Peça para o usuário informar o valor de “n”
antes de gerar a sequência.
Ex: “n” = 5; sequência = 1,5  2,0  2,5  3,0  3,5;

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    int n;
    cout << "Digite o valor de n: ";
    cin >> n;
    float resultado = 1;
    
    cout << setprecision(1) << fixed;
    for(int i = 1; i <= n; i++){
        resultado += 0.5;
        cout << resultado << "\t";
    }
    
    return 0;
}
