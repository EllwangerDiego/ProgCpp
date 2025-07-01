/*

Monte um programa que leia 10 números inteiros positivos e os armazene em um
array. Reorganize o próprio array armazenando seus elementos em ordem inversa.
Não utilize outro vetor para isso, use apenas uma variável auxiliar. Mostre o array na
tela após a inversão dos elementos;

*/
#include <iostream>
using namespace std;

int main() {
    
    int array[10];
    int num = 1;
    int temp;
    int j = 10;

    for(int i = 0; i< 10; i++){
        /*
        cout << "Digite um numero: ";
        cin >> num;
        */
        array[i] = num++;
    }

    cout << "\nArray normal: ";
    for(int i = 0; i < 10; i++){
        cout << array[i] <<"  ";
    }

    for(int i = 0; i < 5; i++){\
        j--;
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    cout << "\nArray inverso: ";
    for(int i = 0; i < 10; i++){
        cout << array[i] <<"  ";
    }
    
    return 0;
}
