/*

Peça para o usuário digitar uma frase qualquer, com diversas palavras. Em seguida, crie uma
estrutura map<char,int> e armazene na parte char as letras da frase, sem repetição. Na parte int
correspondente a cada letra, armazene a quantidade de vezes que a letra aparece na frase.

*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    string frase;
    cout << "Digite uma frase: ";
    getline(cin, frase);

    map<char, int> contador;

    for (char c : frase) {
        if (c != ' ') {    // ignorar espaços
            contador[c]++;
        }
    }

    cout << "Frequência das letras na frase:\n";
    for (auto &par : contador) {
        cout << par.first << ": " << par.second << "\n";
    }

    return 0;
}
