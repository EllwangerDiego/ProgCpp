/*

Implemente um programa que define um array B[10] vazio. Em seguida, faça um
laço que inicialize o array de forma dinâmica com os valores [−1.5 −1 −0.5 0 0.5 1
1.5 2 2.5 3], utilizando uma fórmula matemática para calcular os valores. Nenhum
elemento do array deve deixar de ser inicializado. Depois, faça outro laço que
mostre todo o array na tela;

*/

#include <iostream>
using namespace std;

int main() {
    int tamanho = 10;
    float array[tamanho];
    float num = -2.00;
    
    for(int i = 0; i < tamanho; i++){
        num += 0.5;
        array[i] = num;
    }

    for(int i = 0; i < tamanho; i++){
        cout << array[i] << "  ";
    }
    
    return 0;
}
