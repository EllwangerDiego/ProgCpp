/*

Calculadora básica: Digite uma expressão matemática com dois
números inteiros ou fracionários, exemplos:
1+1 2.3*2 5-2.7 9.3/2.4
• Interprete a expressão e dê o resultado correto;
• Cada operação matemática deve ser uma opção do switch-case;
• Cada operação matemática deve ser uma função que retorna o
resultado da operação para o chamador (main);
• A impressão do resultado deve ser feita no main;

*/

#include <iostream>
using namespace std;

float calculadora(float x, char operador, float y);
float somar(float x, float y);
float subtrair(float x, float y);
float multiplica(float x, float y);
float dividir(float x, float y);

int main() {
    float x;
    char operador;
    float y;

    cout << "Digite a expressão (ex: 2.5 + 3.2): ";
    cin >> x >> operador >> y;



    //cout << calculadora(x, operador, y);

    float resultado = calculadora(x, operador, y);
        cout << "Resultado: " << resultado << endl;
    
    
    return 0;
}


float calculadora(float x, char operador, float y){

    switch(operador){
        case '+':
            return somar(x, y);

        case '-':
            return subtrair(x, y);

        case '*':
            return multiplica(x, y);

        case '/':
            return dividir(x, y);

        default:
            cout << "Digite um operador valido ( +  -  *  /)" << endl;
            return -1;
    }
}

float somar(float x, float y){
    return x + y;
}

float subtrair(float x, float y){
    return x - y;
}

float multiplica(float x, float y){
    return x * y;
}

float dividir(float x, float y){
    if(y == 0){
        cout << "Erro, divisao por 0" << endl;
        return 0;
    }
    else{
    return x / y;
    }
}
