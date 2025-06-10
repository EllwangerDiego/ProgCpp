#include <iostream>
using namespace std;

int main () {

    int opcao;

    do {
        cout << "Digite 1 ou 2: ";
        cin >> opcao;


        if (opcao == 1) {
            cout << "\nOpcao 1" << "\n" << endl;
        
        }

        else if (opcao == 2) {
            cout << "\nOpcao 2" << "\n" << endl;
            cout << "Colocar codigo entre chaves se possuir mais de uma opcao no if" << "\n" << endl;
        
        }

        else {
            cout << "\nOpcao invalida!" << "\n" << endl;
    
        }
    } while (opcao != 1 && opcao != 2);


    return 0;
}