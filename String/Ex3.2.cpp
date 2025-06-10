#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char palavra1[100], palavra2[100];

    cout << "Digite uma palavra: ";
    cin >> palavra1;
    cout << endl;

    cout << "Digite outra palavra: ";
    cin >> palavra2;
    cout << endl;

    int resultado = strcmp(palavra1, palavra2);

    if (resultado == 0) {
        cout << "Palavras iguais " << endl;
    }
    else if(resultado < 0){
        cout << "Primeira palavra vem antes" << endl;
    }
    else {
        cout << "Segunda palavra vem antes" << endl;
    }

    return 0;
}