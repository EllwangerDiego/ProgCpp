/*#include <iostream>
#include <windows.h>

using namespace std;

int main(){

    int numero;
    cout << "Digite um numero menor que 10: ";
    cin >> numero;

    while (numero <= 10 ){

        cout << numero << endl;
        Sleep(1000);
        numero++;
    }

    return 0;
}
*/

#include <iostream>
#include <windows.h> // Para usar Sleep no Windows

using namespace std;

int main() {

    int numero = 1;

    while (numero == 1) {
        cout << "Menu"
             << "\n1. Pizza"
             << "\n2. Massa"
             << "\n3. Refri"
             << "\n4. Encerrar Programa" << endl;

        int opcao;
        cout << "Digite aqui uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Menu de Pizzas" << endl;
                Sleep(1500);
                cout << "---------------" << endl;
                break;
            case 2:
                cout << "Menu de Massas" << endl;
                Sleep(1500);
                cout << "---------------" << endl;
                break;
            case 3:
                cout << "Menu de Refri" << endl;
                Sleep(1500);
                cout << "---------------" << endl;
                break;
            case 4:
                cout << "Encerrando programa..." << endl;
                Sleep(1500);
                numero = 0;
                break;
            default:
                cout << "---------------" << endl;
                cout << "Digite um numero entre 1 e 4" << endl;
                Sleep(1500);
                cout << "---------------" << endl;
            break;
        }
    }

    return 0;
}
