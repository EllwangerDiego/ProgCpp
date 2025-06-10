#include <iostream>
using namespace std;

// Definindo o enum para os dias da semana
// Se nao passar um valor de int para eles, ele comeca do 0 ate o final da declaracao,
// mas pode dar um valor especifico se quiser, ex: Thursday = 9
enum Day { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

int main() {
    Day today = Thursday;

    switch (today) {
        case 0:
            cout << "Hoje é domingo!" << endl;
            break;
        case 1:
            cout << "Hoje é segunda-feira!" << endl;
            break;
        case 2:
            cout << "Hoje é terça-feira!" << endl;
            break;
        case 3:
            cout << "Hoje é quarta-feira!" << endl;
            break;
        case 4:
            cout << "Hoje é quinta-feira!" << endl;
            break;
        case 5:
            cout << "Hoje é sexta-feira!" << endl;
            break;
        case 6:
            cout << "Hoje é sábado!" << endl;
            break;
        default:
            cout << "Dia inválido!" << endl;
    }

    return 0;
}
