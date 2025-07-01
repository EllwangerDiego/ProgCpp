/*

Solicitar que o usuário informe as dimensões de uma matriz,
obrigatoriamente menor que 10 x 10. Copiar as últimas linhas e
colunas da matriz do item 1 para dentro dessa nova matriz e exibir na
tela;

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int tamanho = 0;
    int linhas = 0;
    int colunas = 0;

    do{
    tamanho = 0;

    cout << "\n\nDigite a quantidade de linhas da matriz: ";
    cin >> linhas;

    cout << "\nDigite a quantidade de colunas da matriz: ";
    cin >> colunas;

    }while(linhas > 10 || colunas > 10);

    float matriz[linhas][colunas];

    float numeros[10][10];
    float temp = 0.0;

    for(int i = 0; i < 10; i++){
        cout << endl;
        for(int j = 0; j < 10; j++){
            numeros[i][j] = i + j / 10.0;
            cout << setprecision(1) << fixed;
            cout << numeros[i][j] << "  ";

        }
    }

        

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matriz[i][j] = numeros[10 - linhas + i][10 - colunas + j];


        }
    }

    for(int i = 0; i < linhas; i++){
        cout << endl;
        for(int j = 0; j < colunas; j++){
            matriz[i][j] = i + j / 10.0;
            cout << setprecision(1) << fixed;
            cout << numeros[i][j] << "  ";

        }
    }




    
    return 0;

}

