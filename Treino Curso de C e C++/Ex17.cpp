#include <iostream>

using namespace std;

int main(){

    int numero = 5;

    int *ponteiro;

    ponteiro = &numero;



    cout << "Valor da variavel numero: " << numero << endl;
    cout << "Posicao de memoria da variavel numero: " << &numero << endl;

    //Posicao da memoria
    cout << "Ponteiro: " << ponteiro <<endl;

    //Valor da variavel
    cout << "Valor: " << *ponteiro << endl;

    return 0;
}











