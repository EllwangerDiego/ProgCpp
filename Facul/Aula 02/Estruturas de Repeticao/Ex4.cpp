/*

Desenvolva um programa que solicite um número inteiro “n” e
imprima na tela o seu fatorial. Fatorial é o produto dos números
inteiros consecutivos de 1 até um dado inteiro “n”;

*/

#include <iostream>
using namespace std;

int main() {
    
    int n;
    int fatorial = 1;
    cout << "Digite o valor de n: ";
    cin >> n;
    int temp = n;
    
    for(int i = 1; i <= n; i++) {
        fatorial *= i;
    }

    cout << "Fatorial de '" << temp << "' = " << fatorial << endl;
    
    return 0;
}
