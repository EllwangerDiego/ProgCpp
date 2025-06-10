#include <iostream>
using namespace std;

//Declarar as funcoes antes da main para funcionar
//Funcoes sao lidas de cima para baixo, se ela esta depois da main
//ela nao eh lida, por isso declarar antes
void HappyBirthday(string name, int age);

int main(){

    // Function = a block of reusable code
    string name = "Diego";
    int age = 19;
    HappyBirthday(name, age);

    return 0;
}

void HappyBirthday(string name, int age){
    cout << "Happy Birthday " << name << "!" << endl;
    cout << "You are " << age << " years old!" << endl;
}
