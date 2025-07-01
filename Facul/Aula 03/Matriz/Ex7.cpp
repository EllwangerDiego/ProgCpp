/*

Criar uma matriz de caracteres 10 x 10 e inicializar todos os
elementos com “·” (ASCII 250). Depois, alterar para o valor “X” os
elementos das duas diagonais utilizando estruturas de repetição.
Imprimir a matriz na tela;

*/

#include <iostream>
using namespace std;

int main() {
    
    char matriz[10][10];
    int x = 10;
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            matriz[i][j] = '.';
        }
    }

    for(int i = 0; i < 10; i++){
        cout << endl;
        for(int j = 0; j < 10; j++){
            cout << matriz[i][j] << "  ";
        }
    }
    
    for(int i = 0; i < 10; i++){
            matriz[i][i] = 'X';
    }

    for(int i = 0; i < 10; i++){
        x--;
        matriz[x][i] = 'X';
    }

    cout << "\n\n";
    for(int i = 0; i < 10; i++){
        cout << endl;
        for(int j = 0; j < 10; j++){
            cout << matriz[i][j] << "  ";
        }
    }



    return 0;
}

