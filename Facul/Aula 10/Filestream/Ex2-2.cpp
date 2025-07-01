/*

Crie um programa que leia o arquivo criado anteriormente e mostre os dados na
tela, identificando o nome e valor de cada informação. Ex: Nome: <nome> \n
Sexo: M/F \n, etc;

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

    fstream fs;

    fs.open("arq12.txt", fstream::in);
    if(fs.is_open()){
        getline(fs, nome);


        fs >> sexo;
        fs.ignore();

        fs >> idade;
        fs.ignore();

        fs >> altura;
        fs.ignore();

        fs >> peso;

        cout << "\nNome: " << nome << endl;
        cout << "Sexo: " << sexo << endl;
        cout << "Idade: " << idade << endl;
        cout << "Altura: " << altura << endl;
        cout << "Peso: " << peso << endl;
    }
    
    
    return 0;
}
