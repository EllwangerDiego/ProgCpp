/*

Faça um programa que solicite ao usuário informar uma hora,
minuto e segundo no formato “hh:mm:ss”. Crie uma função
chamada “horaParaFloat” que recebe esses 3 parâmetros
separadamente. Essa função deverá retornar um número float
representando as horas, minutos e segundos como um número
fracionário. Ex: “01:15:30” = 1,2583 ou “13:20:15” = 13,3375. 

*/

#include <iostream>
#include <iomanip>
using namespace std;

float horaParaFloat(int hora, int minuto, int segundo);

int main() {
    int hora, minuto, segundo;
    char sep1, sep2;

    cout << "Digite o horario: (hh:mm:ss): ";
    cin >> hora >> sep1 >> minuto >> sep2 >> segundo;  

    cout << setprecision(4) << fixed << horaParaFloat(hora, minuto, segundo);
    
    return 0;
}

float horaParaFloat(int hora, int minuto, int segundo){
    float resultado = hora + (minuto / 60.0f) + (segundo / 3600.0f);
    return resultado;

}
