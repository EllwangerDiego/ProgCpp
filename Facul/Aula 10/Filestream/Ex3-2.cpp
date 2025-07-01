/*

Crie a classe “Pessoa” com os atributos da atividade 1. Além dos métodos getter
e setter de cada atributo, crie o método “visualizar()”, que deverá mostrar na tela
os nomes e valores dos atributos no mesmo formato da atividade 2. Instancie
uma pessoa, defina seus atributos e visualize;

*/

#include <iostream>
#include <sstream>

using namespace std;

class Pessoa{
    private:
        string nome;
        char sexo;
        int idade;
        float altura;
        float peso;

    public:
        Pessoa(){
            nome = "";
            sexo =' ';
            idade = 0;
            altura = 0;
            peso = 0;
            
        }
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
            this-> nome = nome;
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
            cout << "\nNome: " << this->nome << endl;
            cout << "Sexo: " << this-> sexo << endl;
            cout << "Idade: " << this-> idade << endl;
            cout << "Altura: " << this-> altura << endl;
            cout << "Peso: " << this-> peso << endl;
        }
};

int main() {

    stringstream ss;

    string nome;
    char sexo;
    int idade;
    float altura;
    float peso;

    cout << "Digite seu nome: ";
    getline(cin, nome);

    cout << "Digite seu sexo (M-F): ";
    cin >> sexo;
    sexo = toupper(sexo);

    cout << "Digite sua idade: ";
    cin >> idade;

    cout << "Digite sua altura em metros: ";
    cin >> altura;

    cout << "Digite seu peso: ";
    cin >> peso;
    
    Pessoa pessoa1(nome, sexo, idade, altura, peso);
    pessoa1.visualizar();


    
    return 0;
}
