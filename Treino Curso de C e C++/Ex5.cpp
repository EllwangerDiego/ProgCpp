#include <iostream>
using namespace std;

int main(){

    int a, b;

    a = 5;
    b = 2;

    int adicao, subtracao, multiplicacao;
    float divisao, resto;

    //Somar dois numeros
    adicao = a + b;
    cout << "\nAdicao: " << adicao << endl;

    subtracao = a - b;
    cout << "\nSubtracao: " << subtracao << endl;

    multiplicacao = a * b;
    cout << "\nMultiplicacao: " << multiplicacao << endl;

    divisao = a / b;
    cout << "\nDivisao: " << divisao << endl;

    resto = a % b;
    cout << "\nResto da divisao: " << resto << "\n" << endl;

    

    return 0;
}
