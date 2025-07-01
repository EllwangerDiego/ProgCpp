/*

Altere o programa da atividade 3 adicionando os métodos “carregar(string
nomeArquivo)” e “salvar(string nomeArquivo)”. Instancie uma pessoa, carregue
seus atributos a partir de um arquivo e visualize. Depois, altere o valor de alguns
atributos e salve;

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Pessoa
{
private:
    string nome;
    char sexo;
    int idade;
    float altura;
    float peso;

public:
    Pessoa(){
        nome = "";
        sexo = ' ';
        idade = 0;
        altura = 0.0;
        peso = 0.0;
    }
    Pessoa(string nome, char sexo, int idade, float altura, float peso)
    {
        setNome(nome);
        setSexo(sexo);
        setIdade(idade);
        setAltura(altura);
        setPeso(peso);
    }
    string getNome()
    {
        return this->nome;
    }
    char getSexo()
    {
        return this->sexo;
    }
    int getIdade()
    {
        return this->idade;
    }
    float getAltura()
    {
        return this->altura;
    }
    float getPeso()
    {
        return this->peso;
    }

    void setNome(string nome)
    {
        this->nome = nome;
    }
    void setSexo(char sexo)
    {
        this->sexo = sexo;
    }
    void setIdade(int idade)
    {
        this->idade = idade;
    }
    void setAltura(float altura)
    {
        this->altura = altura;
    }
    void setPeso(float peso)
    {
        this->peso = peso;
    }

    void visualizar()
    {
        cout << "\nNome: " << getNome() << endl;
        cout << "Sexo: " << getSexo() << endl;
        cout << "Idade: " << getIdade() << endl;
        cout << "Altura: " << getAltura() << endl;
        cout << "Peso: " << getPeso() << "kg" << endl;
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
            cout << "Dados carregados com sucesso do arquivo!" << endl;

        }
        else{
            cout << "Erro ao abrir o arquivo para leitura.\n";
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
            cout << "\nDados salvos com sucesso!" << endl;
        }
        else {
        cout << "Erro ao abrir o arquivo para escrita.\n";
        }
    }
};

int main()
{
    string nomeArquivo = "Ex4N.txt";

    string nome;
    char sexo;
    int idade;
    float altura;
    float peso;

    cout << "Digite seu nome (-1 para sair): ";
    getline(cin, nome);

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

    Pessoa pessoa1(nome, sexo, idade, altura, peso);
    pessoa1.visualizar();

    //Salva no arquivo
    //Pessoa pessoa2("Teste", 'F', 20, 1.74, 90);
    //pessoa2.visualizar();

    //pessoa2.setNome("Alterado");
    //pessoa2.setIdade(99);

    //pessoa2.salvar(nomeArquivo);


    // Carrega do arquivo
    Pessoa pessoa2;
    pessoa2.carregar(nomeArquivo);

    pessoa2.visualizar();

    return 0;
}
