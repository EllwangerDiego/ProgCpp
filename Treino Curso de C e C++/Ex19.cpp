#include <iostream>
#include <cstring>

using namespace std;

int main() {

    char frase[100];

    cout << "Digite uma frase: ";
    cin >> frase;

    cout << "Capacidade total do array: " << sizeof(frase) << endl;;

    cout << "Tamanho da string: " << strlen(frase) << endl;

    return 0;
}