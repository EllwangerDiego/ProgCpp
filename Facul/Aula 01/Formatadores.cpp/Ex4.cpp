#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    char moeda;
    cout << "Digite um caractere para representar uma moeda: ";
    cin >> moeda;
    float valor;
    cout << "Digite um valor: ";
    cin >> valor;
    cout << moeda << setprecision(2) << fixed << valor << endl;
    
    return 0;
}
