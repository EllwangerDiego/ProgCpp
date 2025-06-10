#include <iostream>
#include <vector>
using namespace std;

// Definição da classe Objeto
class Objeto {
    int id; // Atributo privado

public:
    // Construtor com parâmetro
    Objeto(int id) {
        this->id = id;
        cout << "Construtor: id = " << this->id << endl;
    }

    // Destrutor
    ~Objeto() {
        cout << "Destrutor: id = " << this->id << endl;
    }

    // Método para acessar o ID
    int getId() const {
        return this->id;
    }
};

int main() {
    // Criação de um vector de ponteiros para Objeto
    vector<Objeto*> lista;

    // Adiciona objetos dinamicamente com new (alocação na memória heap)
    lista.push_back(new Objeto(10));
    lista.push_back(new Objeto(20));
    lista.push_back(new Objeto(30));

    cout << "\nObjetos armazenados no vector:\n";

    // Usa iterator para percorrer os ponteiros e acessar os objetos
    vector<Objeto*>::iterator it;
    for (it = lista.begin(); it != lista.end(); it++) {
        cout << "Objeto com id = " << (*it)->getId() << endl;
    }

    cout << "\nLiberando memória alocada:\n";

    // Libera a memória de cada objeto alocado com delete
    for (it = lista.begin(); it != lista.end(); it++) {
        delete *it; // Chama o destrutor de cada Objeto
    }

    // Limpa o vector (remove os ponteiros agora inválidos)
    lista.clear();

    cout << "\nTamanho atual do vector: " << lista.size() << endl;

    return 0;
}
