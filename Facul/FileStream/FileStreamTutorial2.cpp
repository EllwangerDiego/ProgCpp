#include <iostream>
#include <fstream>   // Para arquivos
#include <string>    // Para strings
using namespace std;

int main() {
    // ------------------------------
    // Escrita com <<, put, write, flush
    // ------------------------------

    ofstream saida("saida.txt"); // Cria e abre para escrita (sobrescreve)

    // << escreve tipos de dados formatados (como cout)
    saida << "Nome: Pedro" << endl;
    saida << "Idade: " << 25 << endl;

    // put escreve um único caractere
    saida.put('A');
    saida.put('\n');

    // write escreve blocos fixos de caracteres de um array
    char palavra[] = "Exemplo";
    saida.write(palavra, 7); // Escreve exatamente 7 caracteres
    saida.put('\n');

    // flush força o salvamento imediato no disco
    saida.flush();

    saida.close(); // Sempre feche o arquivo após o uso

    // ------------------------------
    // Leitura com >>, get, getline, read
    // ------------------------------

    ifstream entrada("entrada.txt"); // Abre arquivo existente para leitura

    // >> lê valores tipados (separados por espaço)
    string nome1;
    int idade1;
    entrada >> nome1 >> idade1;
    cout << "[>>] Nome: " << nome1 << ", Idade: " << idade1 << endl;

    // get() lê caractere por caractere
    char c;
    entrada.get(c); // Lê o próximo caractere
    cout << "[get()] Primeiro caractere após >>: " << c << endl;

    // getline() lê uma linha completa (até '\n')
    string linha;
    getline(entrada, linha);
    cout << "[getline()] Linha lida: " << linha << endl;

    // read() lê um número fixo de caracteres e armazena em um array
    char buffer[9]; // 8 caracteres + '\0'
    entrada.read(buffer, 8); // Lê 8 caracteres
    buffer[8] = '\0';        // Adiciona terminador para imprimir como string
    cout << "[read()] Bloco fixo de 8 caracteres: " << buffer << endl;

    entrada.close(); // Fecha o arquivo

    return 0;
}
