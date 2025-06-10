#include <iostream>
#include <string>

using namespace std;


const string alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 .";
const int tamanho_alfabeto = alfabeto.length();


char matriz[66][66];


void matriz_alfabeto(char matriz[66][66]) {
    for (int i = 0; i < tamanho_alfabeto; i++) {
        for (int j = 0; j < tamanho_alfabeto; j++) {
            matriz[i][j] = alfabeto[(i + j) % tamanho_alfabeto];
        }
    }
}


void imprimir_matriz(char matriz[66][66]) {
    cout << "Matriz da cifra de Vigenère:\n\n";
    for (int i = 0; i < tamanho_alfabeto; i++) {
        for (int j = 0; j < tamanho_alfabeto; j++) {
            cout << matriz[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    matriz_alfabeto(matriz);
    imprimir_matriz(matriz);
    return 0;
}
