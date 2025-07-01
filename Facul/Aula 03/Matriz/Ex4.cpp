/*

Na matriz criada no item 1, percorrer as bordas e mostrar os
elementos na tela, em formato tabular;

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
        cout << endl;
        for(int j = 0; j < 10; j++){
            if(j == 0 || j == 9 || i == 0 || i == 9){
                cout << setprecision(1) << fixed;
                cout << numeros[i][j] << "  ";
            }
            else{
                cout << "     ";
            }

        }
    }


    
    return 0;
}