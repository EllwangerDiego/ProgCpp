/*

Monte um programa que leia 10 números fracionários, os armazene em um array e
em seguida mostre na tela:
a. O índice e o conteúdo do elemento de menor valor;
b. O índice e o conteúdo do elemento de maior valor;
c. A diferença entre os elementos de maior e menor valor;

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    float array[10];
    float num = 0;
    float maior = 0;
    float menor = 0;
    float temp = 0;

    
    for(int i = 0; i < 10; i++){
        num += 0.33;
        array[i] = num;
    }

    for(int i = 0; i < 10; i++){
        cout << array[i] << "  ";
    }

    for(int i = 0; i < 10; i++){
        temp = array[i];
        maior = array[0];
        menor = array[0];
        if(temp > maior){
            maior = temp;
        }
        else if(temp < menor){        
            menor = temp;
        }
    }
    float diferenca = maior - menor;
    cout << setprecision(2) << fixed;
    cout << "\nMenor numero: " << menor << endl;
    cout << "Maior numero: " << maior << endl;
    cout << "Diferenca entre o maior e o menor: " << diferenca << endl;
    
    return 0;
}
