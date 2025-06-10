#include <iostream>

using namespace std;

void tabuada (int numero);


int main(){
    int numero;

    cout << "Digite aqui um numero: ";
    cin >> numero;
    cout << endl;

    tabuada(numero);

    return 0;
}

void tabuada (int numero){

    cout << "Tabuada do " << numero << endl;
    cout << endl;
    for (int i = 1; i <=10; i++){
        cout << numero << " X " << i << " = " << (numero*i) << endl;
        
    }
    cout << endl;

}