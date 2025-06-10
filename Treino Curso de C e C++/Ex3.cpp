// Entrada de dados

// C
/*
#include <stdio.h>
#include <conio.h>

int main( void ) {

    char nome[30];

    printf("Digite seu nome: ");
    gets( nome );

    printf( "O nome digitado foi %s",nome);
    getch();

    return 0;

}
*/

// C++
#include <iostream>
using namespace std;

int main() {
    int valor;

    //cout recebe o valor
    cout << "Qual valor? ";
    //cin vai mandar o valor para variavel
    cin >> valor;

    cout << "O valor digitado foi " << valor << endl;

    return 0;
}