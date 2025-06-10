#include <iostream>
#include <fstream>     // Para manipular arquivos
#include <sstream>     // Para manipular strings como fluxos
#include <string>      // Para usar strings
using namespace std;

int main() {
    // Abre o arquivo de entrada com nome específico deste exemplo
    fstream entrada_exemplo("dados_pessoas_exemplo.txt", fstream::in);

    // Abre o arquivo de saída onde os dados formatados serão gravados
    fstream saida_exemplo("dados_formatados_exemplo.txt", fstream::out);

    // Verifica se os arquivos foram abertos corretamente
    if (!entrada_exemplo.is_open() || !saida_exemplo.is_open()) {
        cout << "Erro ao abrir os arquivos.\n";
        return 1;
    }

    string linha;

    // Lê o arquivo linha por linha
    while (getline(entrada_exemplo, linha)) {
        stringstream ss(linha);  // Converte a linha para um fluxo de leitura

        string nome;
        int idade;
        float altura;

        // Lê os dados da linha com base nos separadores (tabulações)
        getline(ss, nome, '\t');
        ss >> idade;
        ss >> altura;

        // Escreve os dados formatados no arquivo de saída
        saida_exemplo << "Nome: " << nome
                      << " | Idade: " << idade
                      << " | Altura: " << altura << endl;
    }

    entrada_exemplo.close();
    saida_exemplo.close();

    cout << "Leitura e escrita concluídas!\nConfira: dados_formatados_exemplo.txt\n";
    return 0;
}
