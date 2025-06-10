#include <iostream>
using namespace std;

void bakePizza();
void bakePizza(string topping1);
void bakePizza(string topping1, string topping2);

int main(){

    bakePizza();
    bakePizza("pepperoni");
    bakePizza("queijo","cogumelos");

    return 0;
}

//Funcoes podem compartilhar o mesmo nome, mas passar diferentes parametros bakePizza(parametros) (functions signatures)
void bakePizza(){
    cout << "Here is your pizza!" << endl;
}

void bakePizza(string topping1){
    cout << "Here is your " << topping1 << " pizza!" << endl;
}

void bakePizza(string topping1, string topping2){
    cout << "Here is your " << topping1 << " and " << topping2 << " pizza!" << endl;
}