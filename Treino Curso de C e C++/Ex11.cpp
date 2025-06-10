#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    int i = 1;
    int opcao;

    do {
        cout << "Menu"
        << "\n1. Pizzas"
        << "\n2. Massas"
        << "\n3. Refri"
        << "\n4. Encerrar Programa" << endl;

        cout << "-----------------------------\nDigite aqui a sua opcao: ";
        cin >> opcao;

        switch (opcao){
            case 1:
                cout << "MENU DE PIZZAS" << endl;
                Sleep(1500);
            break;

            case 2:
                cout << "MENU DE MASSAS" << endl;
                Sleep(1500);
            break;

            case 3:
                cout << "MENU DE REFRIGERANTES" << endl;
                Sleep(1500);
            break;

            case 4:
                cout << "Encerrando programa...";
                Sleep(1500);
                cout << endl;
                i = 0;
            break;
            
            default:
                cout << "Digite um numero entre 1 e 4";
                Sleep(1500);
                cout << endl;
            


        }


    }while (i == 1);

    return 0;
}