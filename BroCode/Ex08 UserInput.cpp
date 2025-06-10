#include <iostream>
using namespace std;

int main(){

    string name;
    int age;

    cout << "Digite sua idade: ";
    cin >> age;

    cout << "Digite seu nome: ";
    getline(cin >> ws, name);

    
    cout << endl;
    cout << "Nome do usuario: " << name << endl;
    cout << "Idade do usuario: " << age << endl;

    return 0;
}