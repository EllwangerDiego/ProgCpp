/*

Desenvolva um programa que imprima na tela uma sequência
com os “n” primeiros números naturais sem considerar o zero.
Peça para o usuário informar o valor de “n” antes de gerar a
sequência;


*/

#include <iostream>
using namespace std;

int main() {
    
    int n;
    cout << "Digite quantos numeros: ";
    cin >> n;
    
    for(int i = 1; i <= n; i++ ){
        cout << i << endl;
    }
    
    return 0;
}
