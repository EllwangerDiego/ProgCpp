/*

Altere o programa da atividade 3 adicionando os métodos “carregar(string
nomeArquivo)” e “salvar(string nomeArquivo)”. Instancie uma pessoa, carregue
seus atributos a partir de um arquivo e visualize. Depois, altere o valor de alguns
atributos e salve;

*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Pessoa {
private:
    string nome_completo;
    char sexo;
    int idade;
    float altura;
    float peso;

public:
    Pessoa() : nome_completo(""), sexo('?'), idade(0), altura(0), peso(0) {}

    // Getters
    string getNomeCompleto() const { return nome_completo; }
    char getSexo() const { return sexo; }
    int getIdade() const { return idade; }
    float getAltura() const { return altura; }
    float getPeso() const { return peso; }

    // Setters
    void setNomeCompleto(const string& nome) { nome_completo = nome; }
    void setSexo(char s) { sexo = s; }
    void setIdade(int i) { idade = i; }
    void setAltura(float a) { altura = a; }
    void setPeso(float p) { peso = p; }

    // Exibe os dados
    void visualizar() const {
        cout << "Nome: " << nome_completo << endl;
        cout << "Sexo: " << sexo << endl;
        cout << "Idade: " << idade << endl;
        cout << "Altura: " << altura << endl;
        cout << "Peso: " << peso << endl;
    }

    // Carrega os dados de um arquivo
    bool carregar(const string& nomeArquivo) {
        ifstream arquivo(nomeArquivo);
        if (!arquivo.is_open()) {
            cerr << "Erro ao abrir arquivo para leitura." << endl;
            return false;
        }

        string linha;

        // Nome completo (linha inteira)
        if (!getline(arquivo, nome_completo)) return false;

        // Sexo (char)
        if (!getline(arquivo, linha)) return false;
        if (!linha.empty()) sexo = linha[0];
        else return false;

        // Idade (int)
        if (!getline(arquivo, linha)) return false;
        {
            stringstream ss(linha);
            ss >> idade;
            if (ss.fail()) return false;
        }

        // Altura (float)
        if (!getline(arquivo, linha)) return false;
        {
            stringstream ss(linha);
            ss >> altura;
            if (ss.fail()) return false;
        }

        // Peso (float)
        if (!getline(arquivo, linha)) return false;
        {
            stringstream ss(linha);
            ss >> peso;
            if (ss.fail()) return false;
        }

        arquivo.close();
        return true;
    }

    // Salva os dados em um arquivo
    bool salvar(const string& nomeArquivo) const {
        ofstream arquivo(nomeArquivo);
        if (!arquivo.is_open()) {
            cerr << "Erro ao abrir arquivo para escrita." << endl;
            return false;
        }

        arquivo << nome_completo << '\n';
        arquivo << sexo << '\n';
        arquivo << idade << '\n';
        arquivo << altura << '\n';
        arquivo << peso << '\n';

        arquivo.close();
        return true;
    }
};

int main() {
    Pessoa p;

    // Carrega dados do arquivo
    if (!p.carregar("dados_usuario.txt")) {
        cout << "Falha ao carregar dados." << endl;
        return 1;
    }

    cout << "Dados carregados:" << endl;
    p.visualizar();

    // Altera alguns dados
    p.setIdade(31);
    p.setPeso(72.0f);

    // Salva de volta no arquivo
    if (!p.salvar("dados_usuario.txt")) {
        cout << "Falha ao salvar dados." << endl;
        return 1;
    }

    cout << "Dados alterados e salvos com sucesso." << endl;

    return 0;
}
