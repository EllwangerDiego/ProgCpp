#include <iostream>
#include <sstream>
using namespace std;

int main() {
    // String com dados separados por tabulações e quebra de linha
    string texto = "Pedro Silva\t25\t1.76\nMaria Pereira\t23\t1.69";

    // Cria o stream de leitura a partir da string
    stringstream ss(texto);

    string nome;
    int idade;
    float altura;

    // Enquanto ainda tiver dados no stream
    while (!ss.eof()) {
        // Lê o nome até a próxima tabulação
        getline(ss, nome, '\t');

        // Lê os valores seguintes (idade e altura)
        ss >> idade;
        ss >> altura;

        // Ignora o caractere de quebra de linha (necessário após altura)
        ss.ignore();

        // Mostra os dados
        cout << "Nome: " << nome << ", Idade: " << idade << ", Altura: " << altura << endl;
    }

    return 0;
}
