/*

•
Imprimir no terminal:
– O seu primeiro nome
– A sua idade, utilizando uma variável do tipo int
– A sua altura, em metros e com duas casas decimais, utilizando
uma variável do tipo float
– A forma abaixo (4 linhas e 8 colunas)
    ● Com 4 comandos
    ● Com 1 comando
    ********
    ********
    ********
    ********

*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int idade = 19;
    float altura = 1.740000;

    cout << "Diego" << endl;
    cout << "Idade: " << idade << endl;
    cout << "Altura: " << setprecision(2) << fixed << altura << endl;


    for(int i = 0; i < 4; i++){
        cout << "********\n";
    }    
    
    return 0;
}
