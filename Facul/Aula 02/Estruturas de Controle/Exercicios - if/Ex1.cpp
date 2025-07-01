/*

Modifique o último exemplo para exibir ao usuário uma mensagem
de nota inválida menor que zero e outra mensagem de nota inválida
maior que 10, além de indicar se está aprovado ou pegou grau C;

*/

#include <iostream>
using namespace std;
int main()
{
    float notaFinal = 9.5;

    if (notaFinal < 0 || notaFinal > 10)
        cout << "Nota inválida!" << endl;

    else if (notaFinal >= 6.0)
        cout << "Aprovado!" << endl;

    else
        cout << "Grau C" << endl;

    return 0;
}