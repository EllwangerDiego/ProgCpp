#include <iostream>
#include <cmath>
using namespace std;

int main(){

    double a;
    double b;
    double c;


    cout << "Digite o tamanho de um dos lados do triangulo: ";
    cin >> a;
    cout << endl;

    cout << "Digite o tamanho do outro lado: ";
    cin >> b;
    cout << endl;

    a = pow(a, 2);
    b = pow(b, 2);

    c = sqrt(a + b);

    cout << "Hipotenuse: " << c << endl;
    cout << endl;



    return 0;
}