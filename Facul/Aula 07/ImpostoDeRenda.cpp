#include <iostream>
#include <iomanip>
using namespace std;

class Contribuinte{
    private:
        string nome;
        int ano_nascimento;
        float renda_mensal;
        int num_dependentes;
    public:
        Contribuinte(string nome, int ano_nascimento, float renda_mensal, int num_dependentes){
            this-> nome = nome;
            this-> ano_nascimento = ano_nascimento;
            this-> renda_mensal = renda_mensal;
            this-> num_dependentes = num_dependentes;
        }


        int idade(){
            int ano_atual = 2025;
            return ano_atual - this-> ano_nascimento;
        }
        float renda_anual(){
            return this-> renda_mensal * 12;
        }
        float renda_per_capita_mensal(){
            return this-> renda_mensal / ( 1 + num_dependentes);
        }
        float base_de_calculo(){
            return this-> renda_mensal - (this->num_dependentes * 189.59);

        }
        float aliquota_ir(){
            if(this->base_de_calculo() >= 0 && this->base_de_calculo() <= 1903.98){
                return 0;
            }
            else if(this->base_de_calculo() >= 1903.99 && this->base_de_calculo() <= 2826.65){
                return 7.5 / 100;
            }
            else if(this->base_de_calculo() >= 2826.66 && this->base_de_calculo() <= 3751.05){
                return 15 / 100;
            }
            else if(this->base_de_calculo() >= 3751.06 && this->base_de_calculo() <= 4664.68){
                return 22.5 / 100;
            }
            else if(this->base_de_calculo() >= 4664.69){
                return 27.5 / 100;
            }
            else{
                cout << "Valor da renda mensal invalida" << endl;
                return 0;
                
            }
        }
        float deducao(){
            if(this->base_de_calculo() >= 0 && this->base_de_calculo() <= 1903.98){
                return 0;
            }
            else if(this->base_de_calculo() >= 1903.99 && this->base_de_calculo() <= 2826.65){
                return 142.8;
            }
            else if(this->base_de_calculo() >= 2826.66 && this->base_de_calculo() <= 3751.05){
                return 354.8;
            }
            else if(this->base_de_calculo() >= 3751.06 && this->base_de_calculo() <= 4664.68){
                return 636.13;
            }
            else if(this->base_de_calculo() >= 4664.69){
                return 869.36;
            }
            else{
                cout << "Valor da renda mensal invalida" << endl;
                return 0;
                
            }

        }

        float valor_ir_devido(){
            return this->base_de_calculo() * this->aliquota_ir() - this->deducao();
        }

        float aliquiota_ir_efetiva(){
            return this->valor_ir_devido() / this->renda_anual();
        }
        void imprimir(){
            cout << setprecision(2) << fixed;
            cout << "Nome: " << this-> nome << endl;
            cout << "Nascimento: " << this-> ano_nascimento << endl;
            cout << "Idade: " << this->idade() << endl;
            cout << "Numero de dependentes: " << this->num_dependentes << endl;
            cout << "Renda mensal: " << this-> renda_mensal << endl;
            cout << "Renda per capita mensal: " << this->renda_per_capita_mensal() << endl;
            cout << "Renda anual: " << this-> renda_anual() << endl;
            cout << "Aliquota IR: " << this-> aliquota_ir() << endl;
            cout << "Aliquota IR efetiva: " << this-> aliquiota_ir_efetiva() << endl;
            cout << "Base de Calculo: " << this-> base_de_calculo() << endl;
            cout << "Valor IR devido: " << this-> valor_ir_devido() << endl;
        }
};


int main() {


    string nome;
    int ano_nascimento;
    float renda_mensal;
    int num_dependentes;


    cout << "\nDigite seu nome: ";
    getline(cin, nome);

    cout << "\nDigite seu ano de nascimento: ";
    cin >> ano_nascimento;

    cout << "\nDigite sua renda mensal: R$ ";
    cin >> renda_mensal;

    cout << "\nDigite o numero de dependentes: ";
    cin >> num_dependentes;

    Contribuinte c = Contribuinte(nome, ano_nascimento, renda_mensal, num_dependentes);
    c.imprimir();


    return 0;
}
