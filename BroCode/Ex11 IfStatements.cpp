#include <iostream>
using namespace std;

int main(){

    int age;

    cout << "Digite sua idade: ";
    cin >> age;

    if(age >= 18 && age < 100){
        cout << "Maior de idade" << endl;
    }
    else if( age <= 0){
        cout << "Idade invalida" << endl;
    }
    else if( age >= 100){
        cout << "Ta velho" << endl;
    }
    else{
        cout << "Menor de idade" << endl;
    }

    return 0;
}