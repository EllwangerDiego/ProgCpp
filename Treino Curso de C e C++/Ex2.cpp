/* Comentario
#include <stdio.h>

int main( void ) {
    //puts( "Ola Mundo" );
    //printf("Oi");

    char nome[30] = "Daves";

    printf( "O valor do nome eh %s\n", nome );
    return 0;
}
*/


#include <iostream>
#include <string>

using namespace std;

int main(){

    int numero = 10;
    float numerinho = 0.123456;
    double num_maior = 99999999999999999999999.999;
    char letra = 'a';

    string nome = "Daves";

    


    cout << "O numero eh: " << numerinho << endl;
    cout << "Numero grande eh " << num_maior << endl;
    cout << "Letra eh " << letra << endl;
    cout << "O nome eh " << nome << endl;
    cout << "----------------" << endl;
    

    return 0;
}
