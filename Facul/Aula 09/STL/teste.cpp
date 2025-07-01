#include <iostream>
#include <deque>
#include <cctype>
using namespace std;

int main() {
    deque<char> lista;
    int cont = 0;

    while(cont < 10){
        char usuario;
        cout << "Digite um char: ";
        cin >> usuario;

        if(isalpha(usuario)){
            if(isupper(usuario)){
                lista.push_front(usuario);
            } else if(islower(usuario)){
                lista.push_back(usuario);
            }
            cont++;

            cout << "Letra inserida: " << usuario << endl;
            cout << "Deque atual: ";
            for(char ch : lista) cout << ch << " ";
            cout << endl << endl;
        } else {
            cout << "Caractere invalido, digite uma letra." << endl;
        }
    }

    cout << "Conteudo final do deque: ";
    for(char ch : lista) cout << ch << " ";
    cout << endl;

    return 0;
}
