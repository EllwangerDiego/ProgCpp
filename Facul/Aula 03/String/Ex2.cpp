/*

Receba duas palavras através do teclado e mostre na tela se ambas são
iguais ou se a primeira é anterior ou posterior à segunda conforme a ordem
alfabética

*/

#include <iostream>
using namespace std;

int main() {
    
    string palavra1;
    string palavra2;
    char temp;
    char temp2;
    char letra;
    int j = 0;
    string alfabeto = "abcdefghijklmnopqrstuvwxyz";
    
    cout << "Digite uma palavra: ";
    getline(cin, palavra1);

    cout << "\nDigite outra palavra: ";
    getline(cin, palavra2);

    if(palavra1 == palavra2){
        cout << "As palavras sao iguais" << endl;
    }
    else if(palavra1 < palavra2){
        cout << "A primeira palavra vem antes da segunda no alfabeto" << endl;
    }
    else{
        cout << "A segunda palavra vem antes da primeira no alfabeto" << endl;
    }

    return 0;
}
