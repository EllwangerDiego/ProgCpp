#include <iostream>
#include <cmath>
using namespace std;

int main(){

    double x = 3;
    double y = 4;
    double z;

    double pi = 3.14;

    //Funcao para mostrar o maior numero
    z = max(x, y);
    cout << "Max: " << z << endl;

    //Funcao para mostrar o menor numero
    z = min(x, y);
    cout << "Min: " << z << endl;

    //A partir daqui, apenas com a biblioteca cmath
    //Primeiro numero elevado ao segundo
    z = pow(2, 3);
    cout << "2 elevado a 3 (ao cubo): " << z << endl;

    //Raiz quadrada
    z = sqrt(9);
    cout << "Raiz Quadrada de 9: " << z << endl;

    //Absolute value (Distancia ate o 0), vai mostrar o numero em positivo
    z = abs(-3);
    cout << "Absolute Value of -3: " << z << endl;

    //Arredondar
    z = round(pi);
    cout << "Valor de pi arredondado: " << z << endl;

    //Arredondar para cima
    z = ceil(pi);
    cout << "Valor de pi arredondado para cima: " << z << endl;

    //Sempre arredondar para baixo
    z = floor(pi);
    cout << "Valor de pi arredondado para baixo: " << z << endl;



    return 0;
}