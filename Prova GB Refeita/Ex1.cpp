/*

(5,0 pontos). Uma empresa tem como política atualizar equipamentos com 24 meses ou mais e substituir
equipamentos com 48 meses ou mais. Crie uma classe “Equipamento” com os atributos privados “nome” (string),
“mes” e “ano” de aquisição (inteiro). O construtor deve receber e armazenar esses 3 dados. 
Crie um método “idade” que calcula e retorna quantos meses o equipamento tem, e outro método “status” que retorna o status
dele, podendo ser “em dia”, “atualizar” ou “substituir” de acordo com a idade. Ainda na classe, crie o método
“serializar”, que retorna uma string com os 3 atributos, idade e status separados por “tab”. Para calcular a idade
de um equipamento, use a equação: meses = (anoAtual - anoAquisicao) * 12 + mesAtual - mesAquisicao. Crie um
programa que solicite ao usuário os dados de diversos equipamentos, instancie dinamicamente cada um deles e
os armazene em um vector. Quando for informado “nome” = “fim”, salve todos os dados dos equipamentos no
arquivo “equipamentos.txt”, sobrescrevendo o arquivo caso ele já exista. Inclua um cabeçalho no arquivo
indicando o nome de cada coluna. No final, garanta a liberação dos recursos alocados.

*/

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

class Equipamento{
    private:
        string nome;
        int mes_aquisicao;
        int ano_aquisicao;

    public:
        Equipamento(string nome, int mes_aquisicao, int ano_aquisicao){
            this->nome = nome;
            this->mes_aquisicao = mes_aquisicao;
            this->ano_aquisicao = ano_aquisicao;
        }
        int Idade(){
            int mes_atual = 7;
            int ano_atual = 2025;
            return (ano_atual - ano_aquisicao) * 12 + (mes_atual - mes_aquisicao);
        }
        string Status(){
            int idade = Idade();
            if( idade >= 24 && idade < 48){
                //cout << "O equipamento precisa ser atualizado." << endl;
                return "atualizar";
            }
            else if(idade >= 48){
                //cout << "O equipamento precisa ser substituido." << endl;
                return "substituir";
            }
            else{
                //cout << "O equipamento esta em dia." << endl;
                return "em dia";
            }
        }

        string serializar(){
            stringstream ss;

            ss << nome << "\t" << mes_aquisicao << "\t" << ano_aquisicao << "\t" << Idade() << "\t" << Status();
            return ss.str();
        }
};

int main() {
    
    vector<Equipamento*>equipamentos;
    vector<Equipamento*>::iterator it;
    
    string nome;
    int mes_aquisicao;
    int ano_aquisicao;


    do{
        cout << "*******************************************************" << endl;
        cout << "\nDigite o nome do equipamento ('fim' para sair): ";
        getline(cin, nome);
        if(nome == "fim"){
            break;
        }

        cout << "\nDigite o mes de aquisicao do equipamento (0-12): ";
        cin >> mes_aquisicao;

        cout << "\nDigite o ano de aquisicao do equipamento: ";
        cin >> ano_aquisicao;
        cin.ignore();

        equipamentos.push_back(new Equipamento(nome, mes_aquisicao, ano_aquisicao));

    }while(nome != "fim");

    fstream fs;
    fs.open("equipamentos.txt", fstream::out | fstream::trunc);
    if(fs.is_open()){
        fs << "nome\tmes_aquisicao\tano_aquisicao\tidade\tstatus" << endl;
        for(it = equipamentos.begin(); it != equipamentos.end(); it++){
            fs << (*it)->serializar() << endl;
        }
        fs.close();
        cout << equipamentos.size() << " equipamentos adicionados no arquivo" << endl;

    }
    else{
        cout << "Erro ao abrir arquivo." << endl;
    }

    for(it = equipamentos.begin(); it != equipamentos.end(); it++){
        delete *it;
    }

 
    return 0;
}
