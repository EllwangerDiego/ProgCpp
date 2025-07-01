/*

Crie um programa que solicite ao usuário digitar 5 números fracionários e os
armazene em um array A. Depois, solicite mais 5 números e armazene em um
segundo array B. Mostre na tela as operações matemáticas soma, subtração,
multiplicação e divisão, índice por índice dos vetores;

*/

#include <iostream>
using namespace std;

int main() {
    
    float A[5];
    float B[5];
    float num = 0;
    float temp;

    for(int i = 0; i < 5; i++){
        /*
        cout << "Digite um valor fracionario para o array A: ";
        cin >> num;
        A[i] = num;
        */
        num += 0.1;
        A[i] = num;
        B[i] = num;

    }

    for(int i = 0; i < 5; i++){
        /*
        cout << "Digite um valor fracionario para o array B: ";
        cin >> num;
        B[i] = num;
        */
    }

    for(int i = 0; i < 5; i++){
        temp = A[i] + B[i];
        cout << "Soma: '" << A[i] << " + " << B[i] << " = " << temp << "\t";
        cout << endl;

        temp = A[i] - B[i];
        cout << "Subtracao: '" << A[i] << " - " << B[i]<< " = "<< temp << "\t";
        cout << endl;

        temp = A[i] * B[i];
        cout << "Multiplicacao: '" << A[i] << " * " << B[i]<< " = "<< temp << "\t"; 
        cout << endl;

        temp = A[i] / B[i];
        cout << "Divisao: '" << A[i] << " / " << B[i]<< " = "<< temp << "\t"; 
        cout << "\n" << endl;

    }
    cout << endl;
    
    return 0;
}
