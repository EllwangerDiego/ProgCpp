/*

Declare um array de char com tamanho 100 e o inicialize com uma frase
digitada pelo usuário. Em seguida, mostre na tela a capacidade de
armazenamento total do array e a quantidade de caracteres da frase
digitada

*/

#include <iostream>
#include <string>
#include <cstring> // para strlen
using namespace std;

int main() {
    char array[100];          // array de char com capacidade para 100
    string frase;

    cout << "Digite uma frase: ";
    getline(cin, frase);      // lê a frase com espaços

    // Copia a string para o array de char (até o limite de 99 caracteres + '\0')
    strncpy(array, frase.c_str(), sizeof(array) - 1);
    array[sizeof(array) - 1] = '\0'; // garante que o último caractere seja '\0'

    cout << "\nCapacidade total do array: " << sizeof(array) << " caracteres" << endl;
    cout << "Quantidade de caracteres da frase: " << strlen(array) << " caracteres" << endl;

    return 0;
}
