/*

Solicite ao usuário que ele informe um número entre 32 e 255 e
imprima na tela o caractere ASCII correspondente

*/

#include <iostream>

using namespace std;

int main(){

    int num;
    cout << "Digite um numero entre 32 e 255: ";
    cin >> num;
    char caractere = (char)num;
    cout << caractere << endl;;

    

    return 0;
}