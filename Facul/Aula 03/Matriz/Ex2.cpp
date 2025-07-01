/*

Na matriz criada no item 1, percorrer a diagonal principal de [0][0] até
[9][9] e mostrar os elementos na tela;

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    float numeros[10][10];
    float temp = 0.0;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            numeros[i][j] = i + j / 10.0;

        }
    }
    for(int i = 0; i < 10; i++){
        cout << numeros[i][i] << "  ";
    }


    
    return 0;
}