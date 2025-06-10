#include <iostream>
#include <cstring>

using namespace std;



int main(){

    string first_name;

    cout << "Entre seu primeiro nome: ";
    getline(cin, first_name);

    int tamanho = first_name.length();
    cout << tamanho << endl;

    if (tamanho >= 12) {
        cout << "Nome maior que 12 caracteres " << endl;

    }
    else {
        cout << "Bem Vindo, " << first_name << "!" << endl;
    }

    return 0;
}