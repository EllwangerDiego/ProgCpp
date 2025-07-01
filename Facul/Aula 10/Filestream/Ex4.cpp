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
    Pessoa()
    {
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
    string getNome() const
    {
        return nome;
    }
    char getSexo() const
    {
        return sexo;
    }
    int getIdade() const
    {
        return idade;
    }
    float getAltura() const
    {
        return altura;
    }
    float getPeso() const
    {
        return peso;
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

    bool carregarLinhaCSV(const string &linha)
    {
        stringstream ss(linha);
        string nomeLido, sexoStr, idadeStr, alturaStr, pesoStr;

        if (!getline(ss, nomeLido, ','))
            return false;
        if (!getline(ss, sexoStr, ','))
            return false;
        if (!getline(ss, idadeStr, ','))
            return false;
        if (!getline(ss, alturaStr, ','))
            return false;
        if (!getline(ss, pesoStr, ','))
            return false;

        nome = nomeLido;
        if (sexoStr.size() > 0)
            sexo = sexoStr[0];
        else
            sexo = ' ';

        idade = stoi(idadeStr);
        altura = stof(alturaStr);
        peso = stof(pesoStr);

        return true;
    }
};

// Salva todas as pessoas em formato CSV com cabeçalho
void salvarTodasPessoasCSV(const vector<Pessoa *> &pessoas, const string &nomeArquivo)
{
    fstream fs;
    fs.open(nomeArquivo, fstream::out | fstream::trunc); // sobrescreve arquivo
    if (fs.is_open())
    {
        // Cabeçalho
        fs << "nome,sexo,idade,altura,peso\n";
        // Dados
        for (const Pessoa *p : pessoas)
        {
            fs << p->getNome() << ','
               << p->getSexo() << ','
               << p->getIdade() << ','
               << p->getAltura() << ','
               << p->getPeso() << '\n';
        }
        fs.close();
        cout << "\nTodas as pessoas salvas com sucesso em formato CSV em " << nomeArquivo << endl;
    }
    else
    {
        cout << "Erro ao abrir arquivo para escrita" << endl;
    }
}

// Carrega todas as pessoas do arquivo CSV, ignorando cabeçalho
void carregarTodasPessoasCSV(vector<Pessoa *> &pessoas, const string &nomeArquivo)
{
    fstream fs;
    fs.open(nomeArquivo, fstream::in);
    if (fs.is_open())
    {
        pessoas.clear();
        string linha;

        // Ignora a primeira linha (cabeçalho)
        getline(fs, linha);

        // Lê linhas de dados
        while (getline(fs, linha))
        {
            Pessoa *p = new Pessoa();
            if (p->carregarLinhaCSV(linha))
            {
                pessoas.push_back(p);
            }
            else
            {
                delete p;
            }
        }
        fs.close();
        cout << "\nPessoas carregadas com sucesso de " << nomeArquivo << endl;
    }
    else
    {
        cout << "Erro ao abrir arquivo para leitura" << endl;
    }
}

int main()
{

    vector<Pessoa *> pessoas;
    string nomeArquivo = "Ex4.csv";

    string nome;
    char sexo;
    int idade;
    float altura;
    float peso;

    while (true)
    {
        cout << "Digite seu nome (-1 para sair): ";
        getline(cin, nome);
        if (nome == "-1")
        {
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

        Pessoa *novaPessoa = new Pessoa(nome, sexo, idade, altura, peso);
        pessoas.push_back(novaPessoa);
    }

    cout << "Pessoas armazenadas no Vector: \n";
    for (Pessoa *p : pessoas)
    {
        p->visualizar();
    }

    // SALVA AS PESSOAS NO ARQUIVO CSV
    salvarTodasPessoasCSV(pessoas, nomeArquivo);

    // Limpar vetor para testar carregamento
    for (Pessoa *p : pessoas)
        delete p;
    pessoas.clear();

    // Carregar todas pessoas do CSV
    carregarTodasPessoasCSV(pessoas, nomeArquivo);

    cout << "\nPessoas carregadas do arquivo CSV:\n";
    for (Pessoa *p : pessoas)
    {
        p->visualizar();
    }

    // Limpar memória
    for (Pessoa *p : pessoas)
        delete p;
    pessoas.clear();

    return 0;
}
