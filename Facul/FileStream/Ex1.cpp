/*

Crie um programa que solicite ao usuário o seu nome completo (string), sexo
(M/F) (char), idade (int), altura (float) e peso (float). Salve cada uma dessas
informações em linhas separadas de um arquivo texto;

*/

#include <iostream>
#include <fstream>  // Para manipulação de arquivos
#include <string>

using namespace std;

int main() {
    string nome_completo;
    char sexo;
    int idade;
    float altura, peso;

    // Entrada de dados
    cout << "Digite seu nome completo: ";
    getline(cin, nome_completo);

    cout << "Digite seu sexo (M/F): ";
    cin >> sexo;

    cout << "Digite sua idade: ";
    cin >> idade;

    cout << "Digite sua altura (em metros): ";
    cin >> altura;

    cout << "Digite seu peso (em kg): ";
    cin >> peso;

    // Abrindo arquivo para escrita
    ofstream arquivo("Ex1.txt");

    if (!arquivo) {
        cerr << "Erro ao abrir arquivo para escrita." << endl;
        return 1; // Sai do programa com erro
    }

    // Escrevendo cada dado em uma linha separada
    arquivo << nome_completo << "\n";
    arquivo << sexo << "\n";
    arquivo << idade << "\n";
    arquivo << altura << "\n";
    arquivo << peso << "\n";

    arquivo.close();

    cout << "Dados salvos no arquivo 'Ex1.txt' com sucesso!" << endl;

    return 0;
}
