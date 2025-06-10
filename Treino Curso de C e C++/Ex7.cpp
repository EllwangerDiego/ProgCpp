#include <iostream>
using namespace std;

int main() {

    int numero;



    do {
        cout << "Digite aqui um numero entre 1 e 3: ";
        cin >> numero;

        switch (numero) {
            case 1 :
                cout << "Um" << endl;
            break;

            case 2 :
                cout << "Dois" << endl;
            break;

            case 3 : 
                cout << "Tres" << endl;
            break;
            
            default:
                cout << "Escolha entre 1 e 3" << endl;
        }

    } while (numero != 1 && numero !=2 && numero != 3 );


    return 0;

}