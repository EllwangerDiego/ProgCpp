/*

Monte um programa que leia 10 números inteiros positivos e os armazene em um
array. Crie um segundo vetor e o alimente com os valores em ordem inversa ao
primeiro. Mostre ambos na tela, percorrendo do primeiro ao último elemento;

*/

#include <iostream>
using namespace std;

int main() {
    
    int array[10];
    int arrayI[10];
    int j = 10;
    int num;
    
    for(int i = 0; i < 10; i++){
        cout << "Digite um numero: ";
        cin >> num;
        array[i] = num;
    }
    
    for(int i = 0; i < 10; i++){
        j--;
        arrayI[j] = array[i];
    }

    cout << "\nArray normal: ";
    for(int i = 0; i < 10; i++){
        cout << array[i] << "  ";
    }

    cout << "\nArray inverso: ";
    for(int i = 0; i < 10; i++){
        cout << arrayI[i] << "  ";
    }
    
    return 0;
}
