/*

Crie um array com 10 elementos, mas inicialize apenas os 5 primeiros com o valor
do próprio índice utilizando um laço. Imprima na tela o vetor completo e veja o que
aparece;

*/

#include <iostream>
using namespace std;

int main() {
    
    int array[10];
    int num = 0;
    
    for(int i = 0; i < 5; i++){
        num+= 1;
        array[i] = num;
    }

    for(int i = 0; i < 10; i++){
        cout << array[i] << "  ";
    }
    
    return 0;
}
