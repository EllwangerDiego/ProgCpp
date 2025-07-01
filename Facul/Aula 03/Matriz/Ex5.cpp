/*

Transpor a matriz criada no item 1, criando uma nova matriz e
permutando as linhas pelas colunas. A linha 1 para coluna 1, linha 2
para coluna 2, linha “n” para coluna “n”. Imprimir a matriz transposta;

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    float numeros[10][10];
    float transposta[10][10];
    float temp = 0.0;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            numeros[i][j] = i + j / 10.0;

        }
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            transposta[j][i] = numeros[i][j];
        }
    }

    for(int i = 0; i < 10; i++){
        cout << endl;
        for(int j = 0; j < 10; j++){
            cout << setprecision(1) << fixed;
            cout << transposta[i][j] << "  ";
        }
    }


    
    return 0;
}
