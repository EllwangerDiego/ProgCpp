/*

Solicitar duas letras "a" e "b" e imprimir na tela se a letra "a" é
igual, antecessora ou sucessora da letra "b". Utilizar a tabela ASCII
para consulta;

*/

#include <iostream>
using namespace std;

int main() {
    
    char a;
    char b;
    
    cout << "Digite uma letra: ";
    cin >> a;

    cout << "\nDigite outra letra: ";
    cin >> b;

    int Aascii = (int)a;
    int Bascii = (int)b;

    if(Aascii < Bascii){
        cout << "\nLetra '" << a << "' vem antes da letra '" << b << "' na tabela ASCII" << endl;
    }
    else if(Aascii > Bascii){
        cout << "\nLetra '" << a << "' vem depois da letra '" << b << "' na tabela ASCII" << endl;
    }
    else{
        cout << "Letras iguais" << endl;
    }
    
    return 0;
}
