/*

Alimente um array com 10 números e o imprima. Peça para o usuário informar um
número e o procure no array. Se encontrar, imprima o número lido e a(s)
posição(ões) em que foi(foram) encontrado(s). Se não encontrar, imprima o número
lido e a mensagem "NÃO ENCONTRADO";

*/

#include <iostream>
using namespace std;

int main() {
    
    int array[10];
    int num = 1;
    int usuario = 0;
    int pos = -1;
    bool encontrado = false;
    
    for(int i = 0; i < 10; i++){
        array[i] = num++;
    }

    for(int i = 0; i < 10; i++){
        cout << array[i] << "  ";
    }

    cout << "\nDigite um numero para procurar no array: ";
    cin >> usuario;

    for(int i = 0; i < 10; i++){
        if(array[i] == usuario){
            pos = i;
            if(pos != -1){
            cout << "Numero "<< usuario <<" encontrado na pos "<< pos << endl;
            encontrado = true;
            }
        }
        else{
        }
    }
    if(encontrado == false){
        cout << "Numero " << usuario << " nao encontrado!" << endl;
    }
    
    return 0;
}
