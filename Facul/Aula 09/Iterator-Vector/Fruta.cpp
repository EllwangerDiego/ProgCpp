#include <iostream>
#include <vector>

using namespace std;

class Fruta
{
private:
    int id;
    string nome;
public:
    Fruta(int id, string nome)
    {
        this->id = id;
        this->nome = nome;
    }
    ~Fruta()
    {
        cout << "Liberando " << this->nome << endl;
    }
    int getId()
    {
        return this->id;
    }
    string getNome()
    {
        return this->nome;
    }
};

int main()
{
    vector<Fruta*> lst;
    vector<Fruta*>::iterator it;

// Alimenta o vector com objetos
    lst.push_back(new Fruta(1, "Banana"));
    lst.push_back(new Fruta(2, "Abacate"));
    lst.push_back(new Fruta(3, "Laranja"));

    cout << "Quantidade: " << lst.size() << endl;

// Percorre o vector e acessa os objetos
    for(it = lst.begin(); it != lst.end(); it++)
        cout << (*it)->getId() << " - " << (*it)->getNome() << endl;

// Percorre o vector e libera os objetos
    for(it = lst.begin(); it != lst.end(); it++)
        delete *it;

    cout << "Quantidade: " << lst.size() << endl;

// Limpa o vector
    lst.clear();

    cout << "Quantidade: " << lst.size() << endl;
    return 0;
}