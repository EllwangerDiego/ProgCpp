/*

Crie um programa que leia o arquivo criado anteriormente e mostre os dados na
tela, identificando o nome e valor de cada informação. Ex: Nome: <nome> \n
Sexo: M/F \n, etc;

*/

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    
    fstream fs;
    stringstream ss;
    string nome;
    char sexo;
    int idade;
    float altura;
    float peso;

    

    fs.open("arq1.txt", fstream::in);
    if(fs.is_open()){
        string linha;

        getline(fs, nome);
        fs >> sexo;
        sexo = toupper(sexo);
        fs.ignore(); // ignora o \n
        
        fs >> idade;
        fs.ignore();

        fs >> altura;
        fs.ignore();

        fs >> peso;
        fs.ignore();

        fs.close();

        // Se o arquivo estivesse separado por espaco ou tab, poderia ler o arquivo assim:
        // fs >> nome >> sexo >> idade >> altura >> peso;
        // Usamos o fs.ignore() para pular o '\n'

        cout << "Nome: " << nome << endl;
        cout << "Sexo: " << sexo << endl;
        cout << "Idade: " << idade << " anos" << endl;
        cout << "Altura: " << altura << " m" << endl;
        cout << "Peso: " << peso << " kg\n" << endl;

        ss << nome << '\n' << sexo << '\n' << idade << '\n' << altura << '\n' << peso << endl;

        //cout << ss.str();
    }


    
    return 0;
}
