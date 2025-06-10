/*

Crie um programa que leia o arquivo criado anteriormente e mostre os dados na
tela, identificando o nome e valor de cada informação. Ex: Nome: <nome> \n
Sexo: M/F \n, etc;

*/

#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
using namespace std;

int main() {
    ifstream arquivo("Ex1.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    string nome_completo;
    string linha;
    char sexo;
    int idade;
    float altura, peso;

    // Nome (linha completa)
    getline(arquivo, nome_completo);

    // Sexo
    getline(arquivo, linha);
    stringstream ss_sexo(linha);
    ss_sexo >> sexo;

    // Idade
    getline(arquivo, linha);
    stringstream ss_idade(linha);
    ss_idade >> idade;

    // Altura
    getline(arquivo, linha);
    stringstream ss_altura(linha);
    ss_altura >> altura;

    // Peso
    getline(arquivo, linha);
    stringstream ss_peso(linha);
    ss_peso >> peso;

    arquivo.close();

    // Exibe os dados
    cout << "Nome: " << nome_completo << endl;
    cout << "Sexo: " << sexo << endl;
    cout << "Idade: " << idade << endl;
    cout << "Altura: " << altura << endl;
    cout << "Peso: " << peso << endl;

    return 0;
}
