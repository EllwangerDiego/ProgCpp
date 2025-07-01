/*

Altere o programa anterior e adicione uma função chamada “char*
floatParaHora”, que recebe como parâmetro um número fracionário
e retorne uma referência para um array de char contendo as horas,
minutos e segundos correspondentes, no formato “hh:mm:ss”;

*/

#include <iostream>
#include <iomanip>
using namespace std;

float horaParaFloat(int hora, int minuto, int segundo);
char* floatParaHora(float& resultado);

int main() {
    int hora, minuto, segundo;
    char sep1, sep2;

    cout << "Digite o horario: (hh:mm:ss): ";
    cin >> hora >> sep1 >> minuto >> sep2 >> segundo;  

    float resultado1 = horaParaFloat(hora, minuto, segundo);;
    cout << setprecision(4) << fixed << resultado1;
    cout << endl;

    char* resultado2 = floatParaHora(resultado1);;
    cout << resultado2 << endl;
    
    return 0;
}

float horaParaFloat(int hora, int minuto, int segundo){
    float resultado = hora + (minuto / 60.0f) + (segundo / 3600.0f);
    return resultado;

}

char* floatParaHora(float& resultado){
    static char resultadoStr[9];
    int hora = (int)resultado;
    float resto = resultado - hora;
    int minuto = (int)(resto * 60);
    int segundo = (int)((resto * 60 - minuto) * 60);

    sprintf(resultadoStr, "%02d:%02d:%02d", hora, minuto, segundo);
    return resultadoStr;
}