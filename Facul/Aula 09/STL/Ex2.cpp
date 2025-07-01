/*

Declare um estrutura deque que armazena caracteres e a alimente com 10 letras informadas pelo
usuário. Caso a letra seja maiúscula, adicione no início da estrutura. Caso seja minúscula, armazene
no final. Em seguida, mostre na tela todas as letras digitadas obedecendo a ordem de
armazenamento no deque.

*/

#include <iostream>
#include <deque>
#include <cctype>
using namespace std;

int main() {

    deque<char> lista;
    int cont = 0;

    deque<char>::iterator it;
    do{
        char usuario;
        cout << "Digite um char: ";
        cin >> usuario;

        //Verifica se o usuario digitou mesmo uma letra
        if(isalpha(usuario)){
            //Verifica se usuario digitou maiuscula
            if(isupper(usuario)){
            lista.push_front(usuario);
        }
        //Verifica se usuario digitou minuscula
        else if(islower(usuario)){
            lista.push_back(usuario);
        }
        cont++;

        cout << "Letra inserida: " << usuario << endl;
            cout << "Deque atual: ";
            for(char ch : lista) cout << ch << " ";
            cout << endl << endl;
        }

        else{
            cout << "Caractere invalido, digite uma letra." << endl;
        }
    }while(cont != 10);

    for(it = lista.begin(); it != lista.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    
    
    return 0;
}
