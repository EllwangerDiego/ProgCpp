/*

Cada objeto deve ter uma função que carrega a string com os
dados serializados a partir do arquivo para dentro dos seus
atributos privados
•
Isso se chama “deserializar” um objeto
• Então, para cada objeto que se quer recuperar, deve-se ler uma
linha do arquivo, instanciar dinamicamente o objeto e chamar o
método de deserialização
• Dica: O próprio método construtor pode fazer isso

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Pessoa
{
private:
    string nome;
    char sexo;
    int idade;
    float altura;

public:
    // Construtor que já deserializa
    Pessoa(string linha)
    {
        char separador;
        stringstream ss(linha);
        getline(ss, this->nome, ';');
        ss >> this->sexo;
        ss >> separador;
        ss >> this->idade;
        ss >> separador;
        ss >> this->altura;
    }
    void imprimir()
    {
        cout << "Nome:\t"
             << this->nome << endl
             << "Sexo:\t"
             << this->sexo << endl
             << "Idade:\t"
             << this->idade << endl
             << "Altura:\t"
             << this->altura << endl
             << endl;
    }
};

int main()
{
    string linha;
    vector<Pessoa *> familia;
    vector<Pessoa *>::iterator it;

    fstream fs("familia.txt", iostream::in);
    if (fs.is_open())
    {
        getline(fs, linha);
        while (getline(fs, linha)) // Enquanto nao for o fim do arquivo, continua lendo ate o arquivo acabar
        {
            familia.push_back(new Pessoa(linha));
        }
        fs.close();
        cout << familia.size() << " pessoas lidas do arquivo" << endl
             << endl;
        for (it = familia.begin(); it != familia.end(); it++)
            (*it)->imprimir();
    }

    for (it = familia.begin(); it != familia.end(); ++it){
        delete *it;
    }

    return 0;
}
