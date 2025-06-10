#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Veiculo {
private:
    int codigo;
    string fabricante;
    string modelo;
    int ano;
    string cor;
    string motor;
    float preco;

public:
    Veiculo() : codigo(0), ano(0), preco(0.0f) {}

    Veiculo(int cod, const string& fab, const string& mod, int a, const string& c, const string& mot, float p)
        : codigo(cod), fabricante(fab), modelo(mod), ano(a), cor(c), motor(mot), preco(p) {}

    int getCodigo() const { return codigo; }
    string getModelo() const { return modelo; }

    string serializar() const {
        stringstream ss;
        ss << codigo << "\t"
           << fabricante << "\t"
           << modelo << "\t"
           << ano << "\t"
           << cor << "\t"
           << motor << "\t"
           << preco;
        return ss.str();
    }

    bool desserializar(const string& linha) {
        stringstream ss(linha);
        string campo;

        // Ler codigo
        if (!getline(ss, campo, '\t')) return false;
        stringstream scod(campo);
        scod >> codigo;

        // fabricante
        if (!getline(ss, fabricante, '\t')) return false;

        // modelo
        if (!getline(ss, modelo, '\t')) return false;

        // ano
        if (!getline(ss, campo, '\t')) return false;
        stringstream sano(campo);
        sano >> ano;

        // cor
        if (!getline(ss, cor, '\t')) return false;

        // motor
        if (!getline(ss, motor, '\t')) return false;

        // preco
        if (!getline(ss, campo, '\t')) return false;
        stringstream spreco(campo);
        spreco >> preco;

        return true;
    }

    void mostrar() const {
        cout << "Codigo: " << codigo << "\n"
             << "Fabricante: " << fabricante << "\n"
             << "Modelo: " << modelo << "\n"
             << "Ano: " << ano << "\n"
             << "Cor: " << cor << "\n"
             << "Motor: " << motor << "\n"
             << "Preco: " << preco << "\n";
    }
};

class Revenda {
private:
    vector<Veiculo*> veiculos;

public:
    ~Revenda() {
        for (auto v : veiculos) delete v;
    }

    void adicionar(Veiculo* v) {
        veiculos.push_back(v);
    }

    void listarPorModelo(const string& modeloBusca) const {
        bool achou = false;
        for (auto v : veiculos) {
            if (v->getModelo() == modeloBusca) {
                v->mostrar();
                cout << "----------------------\n";
                achou = true;
            }
        }
        if (!achou) cout << "Nenhum veículo encontrado para o modelo: " << modeloBusca << "\n";
    }

    bool removerPorCodigo(int codigoBusca) {
        for (auto it = veiculos.begin(); it != veiculos.end(); ++it) {
            if ((*it)->getCodigo() == codigoBusca) {
                delete *it;
                veiculos.erase(it);
                return true;
            }
        }
        return false;
    }

    bool salvar(const string& nomeArquivo) const {
        ofstream arquivo(nomeArquivo);
        if (!arquivo.is_open()) return false;

        for (auto v : veiculos) {
            arquivo << v->serializar() << "\n";
        }

        arquivo.close();
        return true;
    }

    bool carregar(const string& nomeArquivo) {
        ifstream arquivo(nomeArquivo);
        if (!arquivo.is_open()) return false;

        for (auto v : veiculos) delete v;
        veiculos.clear();

        string linha;
        while (getline(arquivo, linha)) {
            Veiculo* v = new Veiculo();
            if (v->desserializar(linha)) {
                veiculos.push_back(v);
            } else {
                delete v;
                cout << "Linha inválida ignorada: " << linha << endl;
            }
        }

        arquivo.close();
        return true;
    }
};

int main() {
    Revenda revenda;
    int opcao;

    do {
        cout << "\nMenu:\n";
        cout << "1. Cadastrar\n";
        cout << "2. Listar por modelo\n";
        cout << "3. Remover por código\n";
        cout << "4. Salvar em arquivo\n";
        cout << "5. Carregar de arquivo\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore();

        if (opcao == 1) {
            int codigo, ano;
            string fabricante, modelo, cor, motor;
            float preco;

            cout << "Informe o código: ";
            cin >> codigo;
            cin.ignore();

            cout << "Informe o fabricante: ";
            getline(cin, fabricante);

            cout << "Informe o modelo: ";
            getline(cin, modelo);

            cout << "Informe o ano: ";
            cin >> ano;
            cin.ignore();

            cout << "Informe a cor: ";
            getline(cin, cor);

            cout << "Informe o motor (ex: 1.0, 1.6): ";
            getline(cin, motor);

            cout << "Informe o preço: ";
            cin >> preco;
            cin.ignore();

            Veiculo* v = new Veiculo(codigo, fabricante, modelo, ano, cor, motor, preco);
            revenda.adicionar(v);

            cout << "Veículo cadastrado com sucesso!\n";
        } 
        else if (opcao == 2) {
            string modeloBusca;
            cout << "Informe o modelo a buscar: ";
            getline(cin, modeloBusca);
            revenda.listarPorModelo(modeloBusca);
        } 
        else if (opcao == 3) {
            int codigoBusca;
            cout << "Informe o código do veículo a remover: ";
            cin >> codigoBusca;
            cin.ignore();

            if (revenda.removerPorCodigo(codigoBusca))
                cout << "Veículo removido com sucesso.\n";
            else
                cout << "Veículo não encontrado.\n";
        } 
        else if (opcao == 4) {
            if (revenda.salvar("veiculos.txt"))
                cout << "Veículos salvos com sucesso!\n";
            else
                cout << "Erro ao salvar arquivo.\n";
        } 
        else if (opcao == 5) {
            if (revenda.carregar("veiculos.txt"))
                cout << "Veículos carregados com sucesso!\n";
            else
                cout << "Erro ao carregar arquivo.\n";
        }
        else if (opcao == 0) {
            cout << "Saindo...\n";
        } 
        else {
            cout << "Opção inválida!\n";
        }

    } while (opcao != 0);

    return 0;
}
