/*

Implemente um programa que define um array A[6] vazio. Em seguida, faça um laço
que inicialize o array de forma dinâmica com os valores [2 4 6 8 10 12], utilizando
uma fórmula matemática para calcular os valores. Nenhum elemento do array deve
deixar de ser inicializado. Depois, faça outro laço que mostre todo o array na tela;

*/

#include <iostream>
using namespace std;

int main() {
    
    int array[6];
    int num;

    for (int i = 0; i < 6; i++){
        num += 2;
        array[i] = num;
    }

    for(int i = 0; i < 6; i++){
        cout << array[i] << "\t";
    }
    
    return 0;
}
