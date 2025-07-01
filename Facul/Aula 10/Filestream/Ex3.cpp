/*

Crie a classe “Pessoa” com os atributos da atividade 1. Além dos métodos getter
e setter de cada atributo, crie o método “visualizar()”, que deverá mostrar na tela
os nomes e valores dos atributos no mesmo formato da atividade 2. Instancie
uma pessoa, defina seus atributos e visualize;

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Pessoa{
    private:
        string nome;
        char sexo;
        int idade;
        float altura;
        float peso; 

    public:
        Pessoa(string nome, char sexo, int idade, float altura, float peso){
            setNome(nome);
            setSexo(sexo);
            setIdade(idade);
            setAltura(altura);
            setPeso(peso);
        }
        string getNome(){
            return this-> nome;
        }
        char getSexo(){
            return this-> sexo;
        }
        int getIdade(){
            return this-> idade;
        }
        float getAltura(){
            return this-> altura;
        }
        float getPeso(){
            return this-> peso;
        }

        void setNome(string nome){
            this-> nome  = nome;
        }
        void setSexo(char sexo){
            this-> sexo = sexo;
        }
        void setIdade(int idade){
            this-> idade = idade;
        }
        void setAltura(float altura){
            this-> altura = altura;
        }
        void setPeso(float peso){
            this-> peso = peso;
        }

        void visualizar(){
            cout << "\nNome: " << getNome() << endl;
            cout << "Sexo: " << getSexo() << endl;
            cout << "Idade: " << getIdade() << endl;
            cout << "Altura: " << getAltura() << endl;
            cout << "Peso: " << getPeso() << "kg" << endl;
        }

};

int main() {

    vector<Pessoa*> pessoas;

    string nome;
    char sexo;
    int idade;
    float altura;
    float peso; 


    while(true){


        cout << "Digite seu nome (-1 para sair): ";
        getline(cin, nome);
        if(nome == "-1"){
            break;
        }

        cout << "\nDigite seu sexo (M-F): ";
        cin >> sexo;
        sexo = toupper(sexo);

        cout << "\nDigite sua idade: ";
        cin >> idade;

        cout << "\nDigite sua altura em metros: ";
        cin >> altura;

        cout << "\nDigite seu peso: ";
        cin >> peso;
        cout << "\n";

        cin.ignore();
        
        Pessoa* novaPessoa = new Pessoa(nome, sexo, idade, altura, peso);
        pessoas.push_back(novaPessoa);

    }


    cout << "Pessoas armazenadas no Vector: \n";
    for(Pessoa* c : pessoas){
        c->visualizar();
    }




    /* Se quisesse acessar diretamente um atributo, como faria?
    
    cout << pessoas[0]->getNome() << endl;
    cout << pessoas[0]->idade << endl;  // se fosse público

    
    */

    for(Pessoa* c : pessoas){
        delete c;
    }
    pessoas.clear();

    
    return 0;
}
