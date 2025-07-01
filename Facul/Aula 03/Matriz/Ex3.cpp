/*

Na matriz criada no item 1, percorrer a diagonal secundária de [0][9]
até [9][0] e mostrar os elementos na tela;

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    float numeros[10][10];
    int x = 10;

        for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            numeros[i][j] = i + j / 10.0;

        }
    }

    for(int i = 0; i < 10; i++){
        x--;
        cout << setprecision(1) << fixed;
        cout << numeros[i][x] << "  ";

    }


    
    return 0;
}