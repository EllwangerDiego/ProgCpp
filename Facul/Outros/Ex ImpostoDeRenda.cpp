#include <iostream>
#include <iomanip>
using namespace std;

class Contribuinte{
    public:
        string nome;
        int ano_nascimento;
        float renda_mensal;
        int num_dependentes;
        float aliquota;
        float deducao;



    Contribuinte(string nome, int ano_nascimento, float renda_mensal, int num_dependentes){
        this->nome = nome;
        this->ano_nascimento = ano_nascimento;
        this->renda_mensal = renda_mensal;
        this->num_dependentes = num_dependentes;


    }

        int idade(){
            int ano_atual = 2025;
            return ano_atual - ano_nascimento;
        }
        float rendaAnual(){
            return renda_mensal * 12;
        }
        float rendaPerCapitaMensal(){

            return renda_mensal / (1 + num_dependentes);
        }
        float baseDeCalculo(){
            return renda_mensal - (num_dependentes * 189.59);
        }
        double aliquotaIR(){

            if (renda_mensal <= 1903.98){
                aliquota = 0;
                deducao = 0;
            }
            else if(renda_mensal >= 1903.99 && renda_mensal <= 2826.65){
                aliquota = 7.5;
                deducao = 142.80;
            }
            else if(renda_mensal >= 2826.66 && renda_mensal <= 3751.05){
                aliquota = 15;
                deducao = 354.80;
            }
            else if(renda_mensal >= 3751.06 && renda_mensal <= 4664.68){
                aliquota = 22.5;
                deducao = 636.13;
            }
            else if(renda_mensal >= 4664.69){
                aliquota = 27.5;
                deducao = 869.36;
            }

            return aliquota;

        }
        float aliquotaIREfetivo(){
            return valorIRDevido() / rendaAnual();
        }
        float valorIRDevido(){
            aliquotaIR();
            return (baseDeCalculo() * (aliquota/100)) - deducao;
        }
        void imprimir(){
            cout << "Nome: " << nome << endl;
            cout << "Idade: " << idade() << endl;
            cout << "Renda mensal: " << renda_mensal << endl;
            cout << "Renda anual: " << rendaAnual() << endl;
            cout << "Numero de dependentes: " << num_dependentes << endl;
            cout << "Renda per capita: " << rendaPerCapitaMensal() << endl;
            cout << "Base de calculo: " << baseDeCalculo() << endl;
            cout << "Aliquota aplicada: " << aliquotaIR() << endl;
            cout << "Valor do IR devido: " << setprecision(2) << fixed << valorIRDevido() << endl;
            cout << "Aliquota efetiva: " << aliquotaIREfetivo() << endl;
        }
};

int main() {
    // Contribuinte(string nome, int ano_nascimento, float renda_mensal, int num_dependentes)

    string nome;
    int ano_nascimento;
    float renda_mensal;
    int num_dependentes;


    cout << "Digite aqui seu nome: ";
    getline(cin, nome);
    

    cout << "\nDigite seu ano de nascimento: ";
    cin >> ano_nascimento;


    cout << "\nDigite aqui sua renda mensal: ";
    cin >> renda_mensal;


    cout <<"\nDigite aqui seu numero de dependentes: ";
    cin >> num_dependentes;


    Contribuinte contribuinte1(nome, ano_nascimento, renda_mensal, num_dependentes);
    
    contribuinte1.imprimir();

    return 0;
}
