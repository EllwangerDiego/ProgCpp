/*

Crie um programa que solicite ao usuário o seu nome completo (string), sexo
(M/F) (char), idade (int), altura (float) e peso (float). Salve cada uma dessas
informações em linhas separadas de um arquivo texto;

*/

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    
    string nome;
    char sexo;
    int idade;
    float altura;
    float peso;

    cout << "\nDigite seu nome: ";
    getline(cin, nome);

    cout << "\nDigite seu sexo (M-F): ";
    cin >> sexo;
    sexo = toupper(sexo);

    cout << "\nDigite sua idade: ";
    cin >> idade;

    cout << "\nDigite sua altura: ";
    cin >> altura;

    cout << "\nDigite seu peso: ";
    cin >> peso;

    stringstream ss;

    ss << nome << "\n" << sexo << "\n" << idade << "\n" << altura << "\n" << peso;
    cout << ss.str();

    fstream fs;
    fs.open("arq12.txt", fstream::out | fstream::trunc);
    if(fs.is_open()){
        fs << ss.str();
    }
    
    
    return 0;
}
