/*

Crie a classe “Pessoa” com os atributos da atividade 1. Além dos métodos getter
e setter de cada atributo, crie o método “visualizar()”, que deverá mostrar na tela
os nomes e valores dos atributos no mesmo formato da atividade 2. Instancie
uma pessoa, defina seus atributos e visualize;

*/
#include <iostream>
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
    // Construtor padrão
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

    // Método para mostrar os dados formatados
    void visualizar() const {
        cout << "Nome: " << nome_completo << endl;
        cout << "Sexo: " << sexo << endl;
        cout << "Idade: " << idade << endl;
        cout << "Altura: " << altura << endl;
        cout << "Peso: " << peso << endl;
    }
};

int main() {
    Pessoa p;

    // Definindo os atributos
    p.setNomeCompleto("João da Silva");
    p.setSexo('M');
    p.setIdade(30);
    p.setAltura(1.75f);
    p.setPeso(70.5f);

    // Exibindo os dados
    p.visualizar();

    return 0;
}
