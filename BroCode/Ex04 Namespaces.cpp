#include <iostream>
using namespace std;

namespace first{
    int x = 1;
}
namespace second{
    int x = 2;
}

int main(){
    //Para utilizar direto a variavel do primeiro namespace, sendo ela como uma local, utiliza-se:
    //using namespace first;

    int x = 0;

    //Pega a variavel local
    cout << "Local: " << x << endl;

    //Pega a variavel do primeiro namespace
    cout << "Primeiro: " << first::x << endl;

    //Pega a variavel do segundo namespace
    cout <<"Segundo: " << second::x << endl;
    cout << endl;

    return 0;
}