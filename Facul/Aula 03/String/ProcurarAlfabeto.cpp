#include <iostream>
#include <string>
using namespace std;

int main() {
    string alfabeto = "abcdefghijklmnopqrstuvwxyz";
    string palavra;

    cout << "Digite uma palavra: ";
    cin >> palavra;

    bool encontrouInvalido = false;

    for (int i = 0; i < palavra.length(); i++) {
        char letra = tolower(palavra[i]);  // opcional: deixa tudo minúsculo
        if (alfabeto.find(letra) == string::npos) {
            cout << "Caractere invalido encontrado: '" << palavra[i] << "' na posicao " << i << endl;
            encontrouInvalido = true;
        }
    }

    if (!encontrouInvalido) {
        cout << "Todos os caracteres sao letras do alfabeto minusculo." << endl;
    }

    return 0;
}
