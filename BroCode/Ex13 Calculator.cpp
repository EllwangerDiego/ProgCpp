#include <iostream>
using namespace std;

int main(){

    char op; // Operador
    double num1;
    double num2;
    double result;
    int opcao;

    cout << "---------------CALCULATOR---------------" << endl;
    cout << "1. Adicao (+)" << endl;
    cout << "2. Subtracao (-)" << endl;
    cout << "3. Multiplicacao (*)" << endl;
    cout << "4. Divisao (/)" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Digite a opcao que deseja: ";
    cin >> opcao;


    switch(opcao){
        case 1:
            cout << "\n1. Adicao (+)" << endl;
            cout << "\nDigite o primeiro numero: ";
            cin >> num1;

            cout <<"Digite o segundo numero: ";
            cin >> num2;

            result = num1 + num2;
            cout << "\n" << num1 << " + " << num2 << " = " << result << endl;
            break;

        case 2:
            cout << "\n2. Subtracao (-)" << endl;
            cout << "\nDigite o primeiro numero: ";
            cin >> num1;

            cout <<"Digite o segundo numero: ";
            cin >> num2;

            result = num1 - num2;
            cout << "\n" << num1 << " - " << num2 << " = " << result << endl;
            break;
            
        case 3:
            cout << "\n3. Multiplicacao (*)" << endl;
            cout << "\nDigite o primeiro numero: ";
            cin >> num1;

            cout <<"Digite o segundo numero: ";
            cin >> num2;

            result = num1 * num2;
            cout << "\n" << num1 << " * " << num2 << " = " << result << endl;
            break;
            
        case 4:
            cout << "\n4. Divisao (/)" << endl;
            cout << "\nDigite o primeiro numero: ";
            cin >> num1;

            cout <<"Digite o segundo numero: ";
            cin >> num2;

            result = num1 / num2;
            cout << "\n" << num1 << " / " << num2 << " = " << result << endl;
            break;
        
        default:
            cout << "Digite entre 1 e 4" << endl;
    }
    cout << endl;
    

    return 0;
}