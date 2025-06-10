#include <iostream>
#include <vector>
using namespace std;

class Fruta {
private:
    int id;
    string nome;

public:
    Fruta(int id, string nome) : id(id), nome(nome) {}
    ~Fruta() { cout << "Destruindo " << nome << endl; }

    int getId() const { return id; }
    string getNome() const { return nome; }
};

int main() {
    vector<Fruta*> frutas;

    frutas.push_back(new Fruta(1, "Banana"));
    frutas.push_back(new Fruta(2, "Maçã"));
    frutas.push_back(new Fruta(3, "Melancia"));

    // Iterador para acessar os objetos
    vector<Fruta*>::iterator it;
    for (it = frutas.begin(); it != frutas.end(); ++it) {
        cout << (*it)->getId() << " - " << (*it)->getNome() << endl;
    }

    // Liberar memória
    for (it = frutas.begin(); it != frutas.end(); ++it) {
        delete *it;
    }

    frutas.clear(); // limpa os ponteiros (já deletados)
    cout << "Frutas liberadas. Tamanho: " << frutas.size() << endl;

    return 0;
}
