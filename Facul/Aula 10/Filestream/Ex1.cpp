/*

Crie um programa que solicite ao usuário o seu nome completo (string), sexo
(M/F) (char), idade (int), altura (float) e peso (float). Salve cada uma dessas
informações em linhas separadas de um arquivo texto;

*/
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    
    stringstream ss;
    string nome = "Diego";
    char sexo = 'm';
    int idade = 19;
    float altura = 1.74;
    float peso = 80;

    ss << nome << '\n' << sexo << '\n' << idade << '\n' << altura << '\n' << peso << endl;
    cout << ss.str(); 

    fstream fs;
    fs.open("arq1.txt", fstream::out | fstream::trunc);
    if(fs.is_open()){
        fs << ss.str();
        fs.close();
    }
    
    
    
    
    return 0;
}
