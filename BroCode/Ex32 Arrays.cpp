#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    // array = a data structure that can hold multiple values
    //         values are accesed by an index number
    //         "kind of like a variable that holds multiple values"


    //Pode setar o tamanho automaticamente no inicio passando os valores
    string car[] = {"BMW", "Mustang", "Corvette"};

    car[2] = "Camaro";

    cout << car[0] << endl;
    cout << car[1] << endl;
    cout << car[2] << endl;
    cout << endl;

    //Se nao passar os valores, tem que incluir o tamanho do array
    string pizza[3];


    pizza[0] = "Pepperoni";
    pizza[1] = "Cheese";
    pizza[2] = "Portuguese";

    for(int i = 0; i < 3; i++){
        cout << pizza[i] << endl;
    }
    cout << endl;

    double prices[] = {5.00, 7.50, 9.99, 15.00};
    for (int i = 0; i < 4; i++){
        cout << setprecision(2) << fixed << prices[i] << endl;
    }
    cout << endl;

    return 0;
}