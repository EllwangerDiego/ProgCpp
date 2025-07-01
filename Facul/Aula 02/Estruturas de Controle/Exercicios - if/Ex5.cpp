/*

Solicitar um número inteiro "a" representando uma temperatura
em graus Celsius. Imprimir na tela se nessa temperatura a água
se encontra em estado sólido, líquido ou gasoso;

*/

#include <iostream>
using namespace std;

int main() {
    
    int a;
    cout << "Digite a temperatura em celsius: ";
    cin >> a;

    if(a <= 0){
        cout << "\nAgua se encontra em estado solido" << endl;
    }
    else if(a >= 100){
        cout << "Agua se encontra em estado gasoso" << endl;
    }
    else{
        cout << "Agua se encontra em estado liquido" << endl;
    }
    
    return 0;
}
