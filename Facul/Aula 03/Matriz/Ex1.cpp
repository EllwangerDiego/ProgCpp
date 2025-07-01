/*

Criar uma matriz de números fracionários com 10 linhas e 10 colunas.
Inicializar cada elemento da matriz com a parte inteira correspondente
ao índice da linha e a parte fracionária correspondente ao índice da
coluna. Imprimir a matriz na tela mostrando os números com uma
casa decimal;

*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
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


    
    return 0;
}
