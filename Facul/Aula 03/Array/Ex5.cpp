/*

Monte um programa que leia 10 números inteiros positivos e os armazene em um
array. Mostre os números na ordem inversa a que foram digitados;

*/

#include <iostream>
using namespace std;

int main() {
    
    int array[10];
    int num;

    for(int i = 0; i < 10; i++){
        cout << "Digite um numero: ";
        cin >> num;
        array[i] = num;
        cout << endl;
    }

    for(int i = 9; i >= 0; i--){
        cout << array[i] << "  ";
    }
    
    return 0;
}
