/*

Declare um estrutura deque que armazena caracteres e a alimente com 10 letras informadas pelo
usuário. Caso a letra seja maiúscula, adicione no início da estrutura. Caso seja minúscula, armazene
no final. Em seguida, mostre na tela todas as letras digitadas obedecendo a ordem de
armazenamento no deque.


*/
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<char> letras;
    char letra;

    cout << "Digite 10 letras:\n";
    for (int i = 0; i < 10; ++i) {
        cin >> letra;
        if (letra >= 'A' && letra <= 'Z') {
            letras.push_front(letra);  // maiúscula no início
        } else {
            letras.push_back(letra);   // minúscula no final
        }
    }

    cout << "Letras armazenadas no deque:\n";
    for (char c : letras) cout << c << " ";
    cout << endl;

    return 0;
}
