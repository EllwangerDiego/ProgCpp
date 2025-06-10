#include <iostream>
using namespace std;

int main(){

    int month;
    cout << "Digite um mes: ";
    cin >> month;
    cout << endl;

    //Mes
    switch(month){
        case 1:
            cout << "Janeiro" << endl;
            break;
        case 2:
            cout << "Fevereiro" << endl;
            break;
        case 3:
            cout << "Marco" << endl;
            break;
        case 4:
            cout << "Abril" << endl;
            break;
        case 5:
            cout << "Maio" << endl;
            break;
        case 6:
            cout << "Junho" << endl;
            break;
        case 7:
            cout << "Julho" << endl;
            break;
        case 8:
            cout << "Agosto" << endl;
            break;
        case 9:
            cout << "Setembro" << endl;
            break;
        case 10:
            cout << "Outubro" << endl;
            break;
        case 11: 
            cout << "Novembro" << endl;
            break;
        case 12:
            cout << "Dezembro" << endl;
            break;
        default:
            cout << "Mes invalido" << endl;
            cout << "Digite entre 1 e 12" << endl;
            break;
        
    }
    cout << endl;

    //Nota
    char grade;
    cout << "What letter grade?: ";
    cin >> grade;

    switch(grade){
        case 'A':
            cout << "You did great!";
            break;
        case 'B':
            cout << "You did good!";
            break;
        case 'C':
            cout << "You did OK";
            break;
        case 'D':
            cout << "You did not do good";
            break;
        case 'F':
            cout << "You failed";
            break;
        default:
            cout << "Please enter in a letter grade (A-F)";
            break;
    }

    return 0;
}