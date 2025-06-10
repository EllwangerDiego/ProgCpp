#include <iostream>
#include <string>

using namespace std;

void imprime(string mensagem);

int main(){

    imprime("Programa exemplo");

    return 0;
}

void imprime (string mensagem){

    cout << "\nMENSAGEM: " << mensagem << endl;
    cout << endl;

}