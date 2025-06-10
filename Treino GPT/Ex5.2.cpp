#include <iostream>
using namespace std;

int num_fatorial(int i){
    int resultado = 1;
    for (int j = i; j > 1; j--){
        resultado *= j;
    }
    return resultado;
}


int main(){

    int y;
    cout << "Digite um numero para calcular o fatorial: ";
    cin >> y;

    int fatorial = num_fatorial(y);

    cout << "Numero: " << y << " em fatorial = " << fatorial << endl;
    return 0;
}