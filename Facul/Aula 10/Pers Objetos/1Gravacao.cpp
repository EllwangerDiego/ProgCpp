/*

Cada objeto deve ter uma função que retorne seus atributos no
formato do arquivo, ou seja, uma lista com os valores dos
atributos separados por um separador padrão
•
Isso se chama “serializar” um objeto
• Então, para cada objeto que se quer salvar, deve-se chamar o
método de serialização e gravar seus dados no arquivo

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
    Pessoa(string nome, char sexo,
           int idade, float altura)
    {
        this->nome = nome;
        this->sexo = sexo;
        this->idade = idade;
        this->altura = altura;
    }
    string serializar()
    {
        stringstream ss;
        ss << this->nome << ';'
           << this->sexo << ';'
           << this->idade << ';'
           << this->altura;
        return ss.str();
    }
};

int main()
{
    vector<Pessoa *> familia;
    vector<Pessoa *>::iterator it;

    familia.push_back(new Pessoa("Pedro", 'M', 42, 1.76));
    familia.push_back(new Pessoa("Maria", 'F', 39, 1.63));
    familia.push_back(new Pessoa("Roberto", 'M', 11, 1.49));

    fstream fs("familia.txt", iostream::out | iostream::trunc);
    if (fs.is_open())
    {
        fs << "nome;sexo;idade;altura";
        for (it = familia.begin(); it != familia.end(); it++)
            fs << endl << (*it)->serializar();
        fs.close();
        cout << familia.size() << " pessoas adicionadas ao arquivo" << endl;
    }

    for (it = familia.begin(); it != familia.end(); ++it) {
        delete *it;
    }


    return 0;
}
