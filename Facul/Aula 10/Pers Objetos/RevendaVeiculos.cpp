/*

Elabore um diagrama de classes simplificado conforme descrição abaixo
• Defina a classe “Veiculo” com os atributos código, fabricante, modelo, ano, cor,
motor (1.0, 1.6, 2.0, etc) e preço. Implemente uma função de serialização e outra
de deserialização usando <tab> como separador dos dados
• Crie uma classe “Revenda” com um atributo privado do tipo vector de ponteiros
para veículos e demais métodos para manipulação dos dados
• Faça um programa com o seguinte menu:
1. Cadastrar: pede todos os dados do veículo e cria um objeto
2. Listar: mostra todos os veículos de um modelo específico
3. Remover: remove do vector o veículo com um código específico
4. Salvar: varre o vector e salva todos os veículos em um arquivo
5. Carregar: limpa o vector e instancia um veículo para cada linha do arquivo

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

class Veiculo
{
private:
    int codigo;
    string fabricante;
    string modelo;
    int ano;
    string cor;
    float motor;
    float preco;

public:
    Veiculo(string linha)
    {
        stringstream ss(linha);
        string temp;

        try
        {
            getline(ss, temp, '\t');
            this->codigo = stoi(temp);

            getline(ss, this->fabricante, '\t');
            getline(ss, this->modelo, '\t');

            getline(ss, temp, '\t');
            this->ano = stoi(temp);

            getline(ss, this->cor, '\t');

            getline(ss, temp, '\t');
            this->motor = stof(temp);

            getline(ss, temp, '\t');
            this->preco = stof(temp);
        }
        catch (const exception &e)
        {
            cerr << "Erro ao desserializar linha: " << linha << endl;
            cerr << "Detalhes: " << e.what() << endl;

            // Valores padrão (opcional) para evitar estado inconsistente
            this->codigo = -1;
            this->fabricante = "ERRO";
            this->modelo = "ERRO";
            this->ano = 0;
            this->cor = "ERRO";
            this->motor = 0;
            this->preco = 0;
        }
    }

    string serializar(){
        stringstream ss;
        ss << this-> codigo << '\t'
            << this-> fabricante << '\t'
            << this-> modelo << '\t'
            << this-> ano << '\t'
            << this-> cor << '\t'
            << this-> motor << '\t'
            << this-> preco << '\t';
        return ss.str();
    }

    string getModelo(){
        return modelo;
    }

    int getCodigo(){
        return codigo;
    }

    void imprimir() {

        cout << "\nCodigo:     " << codigo << endl;
        cout << "Fabricante: " << fabricante << endl;
        cout << "Modelo:     " << modelo << endl;
        cout << "Ano:        " << ano << endl;
        cout << "Cor:        " << cor << endl;
        cout << "Motor:      " << motor << endl;
        cout << "Preco:      " << fixed << setprecision(2) << preco << endl;
        cout << "-------------------------------" << endl;
    }
};

// Crie uma classe “Revenda” com um atributo privado do tipo vector de ponteiros
//para veículos e demais métodos para manipulação dos dados

class Revenda
{
private:
    vector<Veiculo*> veiculos;

public:

    void Cadastrar(){
        
        int codigo;
        string fabricante;
        string modelo;
        int ano;
        string cor;
        float motor;
        float preco;

        cout << "\nDigite o codigo do veiculo: ";
        cin >> codigo;
        cin.ignore();

        cout << "\nDigite o fabricante do veiculo: ";
        getline(cin, fabricante);
        
        cout << "\nDigite o modelo do veiculo: ";
        getline(cin, modelo);

        cout << "\nDigite o ano do veiculo: ";
        cin >> ano;
        cin.ignore();

        cout << "\nDigite a cor do veiculo: ";
        getline(cin, cor);

        cout << "\nDigite o motor do veiculo: ";
        cin >> motor;
        cin.ignore();

        cout << "\nDigite o preco do veiculo: ";
        cin >> preco;
        cin.ignore();

        stringstream ss;
        ss << codigo << '\t'
        << fabricante << '\t'
        << modelo << '\t'
        << ano << '\t'
        << cor << '\t'
        << motor << '\t'
        << preco;

        Veiculo* novo = new Veiculo(ss.str());

        veiculos.push_back(novo);

        cout << "\nVeiculo cadastrado com sucesso!\n";
    }

    void Listar(){
        string modeloBusca;
        cin.ignore();
        cout << "\nQual modelo do veiculo voce quer listar?: ";
        getline(cin, modeloBusca);

        bool encontrado = false;

        vector<Veiculo*>::iterator it;
        for(it = veiculos.begin(); it != veiculos.end(); it++){
            Veiculo* v = *it; // obtem o ponteiro do veiculo
            if( v->getModelo() == modeloBusca){
                v->imprimir();
                encontrado = true;
            }
        }

        if(!encontrado){
            cout << "Nenhum veiculo com o modelo \"" << modeloBusca << "\" foi encontrado." << endl;
        }

    }

    void Remover(){
        int codigoBusca;
        cout << "\nQual codigo de busca?: ";
        cin >> codigoBusca;

        bool encontrado = false;

        vector<Veiculo*>::iterator it;
        for(it = veiculos.begin(); it != veiculos.end(); it++){
            Veiculo* v = *it;
            if(v->getCodigo() == codigoBusca){
                delete v;
                veiculos.erase(it);
                encontrado = true;
                cout << "\nVeiculo removido com sucesso!" << endl;
                break;
            }
        }

        if(!encontrado){
            cout << "Veiculo com codigo: " << codigoBusca << " nao encontrado.";
        }
    }

    void Salvar(){
        vector<Veiculo*>::iterator it;

        fstream fs;
        fs.open("Revenda.txt", fstream::out | fstream::trunc);
        if(fs.is_open()){
            fs << "codigo\tfabricante\tmodelo\tano\tcor\tmotor\tpreco" << endl;
            for(it = veiculos.begin(); it != veiculos.end(); it++){
                fs << (*it)->serializar() << endl;
            }
            fs.close();
            cout << veiculos.size() << " veiculos adicionados no arquivo." << endl;
        }
        else{
            cout << "Erro ao abrir o arquivo para salvamento!" << endl;
        }
    }

    void Carregar(){
        //Apaga o vector
        vector<Veiculo*>::iterator it;
        for(it = veiculos.begin(); it != veiculos.end(); it++){
            delete *it;
        }
        veiculos.clear();

        //instancia um veículo para cada linha do arquivo
        fstream fs;
        fs.open("Revenda.txt", fstream::in);
        if(fs.is_open()){
            string linha;

            getline(fs, linha);

            while(getline(fs, linha)){
                Veiculo* novo = new Veiculo(linha);
                veiculos.push_back(novo);
            }
            fs.close();
            cout << veiculos.size() << " veiculos carregados do arquivo." << endl;
        }
        else{
            cout << "Erro ao abrir o arquivo para leitura!" << endl;
        }

        
    }

    ~Revenda() {
    for (Veiculo* v : veiculos) {
        delete v;
    }
    veiculos.clear(); // opcional aqui, mas é boa prática
    cout << "\nDestrutor da Revenda executado. Memória liberada.\n";
}


};

int main() {
    Revenda loja;
    int opcao;

    do {
        cout << "\n************** MENU **************\n";
        cout << "1. Cadastrar\n";
        cout << "2. Listar\n";
        cout << "3. Remover\n";
        cout << "4. Salvar\n";
        cout << "5. Carregar\n";
        cout << "0. Sair\n";
        cout << "**********************************\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                loja.Cadastrar();
                break;
            case 2:
                loja.Listar();
                break;
            case 3:
                loja.Remover();
                break;
            case 4:
                loja.Salvar();
                break;
            case 5:
                loja.Carregar();
                break;
            case 0:
                cout << "Encerrando o programa...\n";
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);

    return 0;
}
