/*

Solicitar uma letra e imprimir na tela se ela é maiúscula ou
minúscula. Utilizar a tabela ASCII para consulta;

*/

#include <iostream>
using namespace std;

int main() {
    
    char letra;
    cout << "Digite uma letra: ";
    cin >> letra;
    
    int ascii = (int)letra;

    if (ascii >= 65 && ascii <= 90){
        cout << "Letra maiuscula" << endl;
    }
    else{
        cout << "Letra minuscula" << endl;
    }
    
    return 0;
}
