/*

Faça um programa que declare 4 arrays (char, short int, int e float) com
5 elementos cada. Inicialize os vetores com os valores 65, 66, 67, 68 e
69. Depois, liste o endereço e o conteúdo de cada elemento dos
arrays. Observe os valores e endereços impressos

*/

#include <iostream>
using namespace std;

int main() {
    char array1[5] = {65, 66, 67, 68, 69};
    short int array2[5] = {65, 66, 67, 68, 69};
    int array3[5] = {65, 66, 67, 68, 69};
    float array4[5] = {65, 66, 67, 68, 69};

    cout << "ARRAY CHAR:\n";
    for(int i = 0; i < 5; i++) {
        cout << "Valor: " << (int)array1[i] << "\tEndereco: " << (void*)&array1[i] << endl;
    }

    cout << "\nARRAY SHORT INT:\n";
    for(int i = 0; i < 5; i++) {
        cout << "Valor: " << array2[i] << "\tEndereco: " << &array2[i] << endl;
    }

    cout << "\nARRAY INT:\n";
    for(int i = 0; i < 5; i++) {
        cout << "Valor: " << array3[i] << "\tEndereco: " << &array3[i] << endl;
    }

    cout << "\nARRAY FLOAT:\n";
    for(int i = 0; i < 5; i++) {
        cout << "Valor: " << array4[i] << "\tEndereco: " << &array4[i] << endl;
    }

    return 0;
}
