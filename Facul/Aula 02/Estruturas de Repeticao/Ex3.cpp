/*

Desenvolva um programa que imprima na tela uma sequência
com os “n” primeiros números naturais ímpares. Peça para o
usuário informar o valor de “n” antes de gerar a sequência;

*/

#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Digite o valor de n: ";
    cin >> n;

    for(int i = 0; i <=n ; i++){
        if(i % 2 != 0){
            cout << i << endl;
        }
        else{
            continue;
        }
    }
    
    return 0;
}
