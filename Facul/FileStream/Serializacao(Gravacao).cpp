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
    // Construtor padrão
    Pessoa(string nome, char sexo, int idade, float altura) {
        this->nome = nome;
        this->sexo = sexo;
        this->idade = idade;
        this->altura = altura;
    }

    // Método para serializar os dados do objeto em uma string formatada
    string serializar() {
        stringstream ss;
        ss << nome << ';' << sexo << ';' << idade << ';' << altura;
        return ss.str();
    }
};

int main() {
    vector<Pessoa*> familia;

    // Criando objetos dinamicamente
    familia.push_back(new Pessoa("Pedro", 'M', 42, 1.76));
    familia.push_back(new Pessoa("Maria", 'F', 39, 1.63));
    familia.push_back(new Pessoa("Roberto", 'M', 11, 1.49));

    // Abre o arquivo para escrita (trunc apaga o conteúdo anterior)
    fstream fs("familia.txt", ios::out | ios::trunc);

    if (fs.is_open()) {
        fs << "nome;sexo;idade;altura"; // cabeçalho do arquivo

        // Serializa e grava cada objeto no arquivo
        for (auto pessoa : familia) {
            fs << endl << pessoa->serializar();
        }

        fs.close();
        cout << familia.size() << " pessoas adicionadas ao arquivo.\n";
    }

    for (auto pessoa : familia) {
        delete pessoa;
    }

    return 0;
}

