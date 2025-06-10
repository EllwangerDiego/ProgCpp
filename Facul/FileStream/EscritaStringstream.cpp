#include <iostream>
#include <sstream>
using namespace std;

int main() {
    // Cria o stream para escrever na memória
    stringstream ss;

    // Escreve valores usando << como no cout
    string nome = "Pedro Silva";
    int idade = 25;
    float altura = 1.76;

    ss << nome << '\t' << idade << '\t' << altura << '\n';
    ss << "Maria Pereira\t23\t1.69\n";

    // Mostra todo o conteúdo formatado de uma vez
    cout << ss.str();

    return 0;
}
