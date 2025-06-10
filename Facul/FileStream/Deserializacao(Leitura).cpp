#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Pessoa {
private:
    string nome;
    char sexo;
    int idade;
    float altura;

public:
    // Construtor que recebe a linha do arquivo e extrai os atributos
    Pessoa(string linha) {
        char separador;
        stringstream ss(linha);

        getline(ss, nome, ';');
        ss >> sexo >> separador >> idade >> separador >> altura;
    }

    void imprimir() {
        cout << "Nome: " << nome
             << "\nSexo: " << sexo
             << "\nIdade: " << idade
             << "\nAltura: " << altura
             << "\n------------------\n";
    }
};

int main() {
    vector<Pessoa*> familia;
    string linha;

    // Abre o arquivo para leitura
    fstream fs("familia.txt", ios::in);

    if (fs.is_open()) {
        getline(fs, linha); // ignora o cabeçalho

        while (getline(fs, linha)) {
            // Cria um objeto a partir da linha lida
            familia.push_back(new Pessoa(linha));
        }

        fs.close();
        cout << familia.size() << " pessoas lidas do arquivo.\n\n";

        for (auto pessoa : familia) {
            pessoa->imprimir();
        }
    }

    // Libera a memória dos objetos criados com new
    for (auto pessoa : familia) {
        delete pessoa;
    }


    return 0;
}
