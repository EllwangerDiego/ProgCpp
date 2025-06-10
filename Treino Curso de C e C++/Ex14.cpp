#include <iostream>
#include <string>


using namespace std;

//Prototipo da funcao
int soma (int a, int b);

int main() {
    int numero1;
    int numero2;

    cout << "Digite aqui um numero: ";
    cin >> numero1;

    cout << "\nDigite aqui outro numero: ";
    cin >> numero2;
    cout << endl;

    cout << "Resultado da soma de " << numero1 << " + " << numero2 << " = " << soma (numero1, numero2) << endl;
    cout << endl;


    return 0;
}

//Implementar a funcao
int soma (int a, int b){

    return a + b;

}
