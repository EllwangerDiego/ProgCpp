#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream arquivo;
    string nome;

    // 🔹 ABRINDO EM MODO DE ESCRITA (e apagando o conteúdo antigo)
    arquivo.open("nomes.txt", fstream::out | fstream::trunc);

    if (arquivo.is_open()) {
        cout << "Digite 3 nomes para salvar no arquivo:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Nome " << (i + 1) << ": ";
            getline(cin, nome);
            arquivo << nome << endl;
        }
        arquivo.close(); // 🔒 FECHA O ARQUIVO DEPOIS DE ESCREVER
    } else {
        cout << "Erro ao abrir o arquivo para escrita!" << endl;
        return 1;
    }

    // 🔹 AGORA ABRINDO PARA LEITURA
    arquivo.open("nomes.txt", fstream::in);

    if (arquivo.is_open()) {
        cout << "\nNomes lidos do arquivo:\n";
        while (getline(arquivo, nome)) {
            cout << "- " << nome << endl;
        }
        arquivo.close(); // 🔒 FECHA O ARQUIVO DEPOIS DE LER
    } else {
        cout << "Erro ao abrir o arquivo para leitura!" << endl;
        return 1;
    }

    return 0;
}
