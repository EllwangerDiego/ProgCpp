/*

Altere o programa da atividade 3 adicionando os métodos “carregar(string
nomeArquivo)” e “salvar(string nomeArquivo)”. Instancie uma pessoa, carregue
seus atributos a partir de um arquivo e visualize. Depois, altere o valor de alguns
atributos e salve;

*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

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
            cout << setprecision(2) << fixed;
            cout << "\nNome: " << this->nome << endl;
            cout << "Sexo: " << this-> sexo << endl;
            cout << "Idade: " << this-> idade << endl;
            cout << "Altura: " << this-> altura << endl;
            cout << "Peso: " << this-> peso << endl;
        }

        void carregar(string nomeArquivo){
            fstream fs;
            fs.open(nomeArquivo, fstream::in);
            if(fs.is_open()){
                getline(fs, nome);
                fs >> sexo;
                fs >> idade;
                fs >> altura;
                fs >> peso;
                fs.close();
                cout << "Pessoa carregada do arquivo: " << nomeArquivo << endl;
            }
            else{
                cout << "Erro ao carregar pessoas do arquivo: " << nomeArquivo << endl;
            }
        }

        void salvar(string nomeArquivo){
            fstream fs;
            fs.open(nomeArquivo, fstream::out | fstream::trunc);
            if(fs.is_open()){
                fs << nome << endl;
                fs << sexo << endl;
                fs << idade << endl;
                fs << altura << endl;
                fs << peso << endl;
                fs.close();
                cout << "Pessoa salva no arquivo: " << nomeArquivo << endl;
            }
            else{
                cout << "Erro ao salvar pessoa no arquivo: " << nomeArquivo << endl;
            }
        }
};

int main() {

    stringstream ss;
    string nomeArquivo = "arq12.txt";

    string nome;
    char sexo;
    int idade;
    float altura;
    float peso;

    Pessoa pessoa1(nome, sexo, idade, altura, peso);
    pessoa1.carregar(nomeArquivo);
    pessoa1.visualizar();


    
    cout << "\nDigite seu nome: ";
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

    Pessoa pessoa2(nome, sexo, idade, altura, peso);
    pessoa2.salvar(nomeArquivo);
    pessoa2.carregar(nomeArquivo);
    pessoa2.visualizar();
    


    
    return 0;
}
