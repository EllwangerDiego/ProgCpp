#include <iostream>
using namespace std;

int main(){
    float nota;
    cout << "Digite uma nota de 0 a 10: ";
    cin >> nota;

    if( nota >= 6){
        cout << "Voce esta aprovado!" << endl;
    }

    else{
        cout << "Voce esta de recuperacao! :(" << endl;
    }

    return 0;
}