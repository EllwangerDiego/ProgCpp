/*

(5,0 pontos). Um benchmark foi realizado para identificar o desempenho geral de um mesmo algoritmo
implementado em diferentes linguagens de programação. Durante os testes, foram registradas diversas
métricas em um arquivo no formato CSV, como: uso de cpu, memória e tempo de execução, além da quantidade
de linhas de código necessárias para implementar o algoritmo em cada uma das linguagens. O desempenho
geral foi calculado através da fórmula: desempenho = 106 / (cpu * 100 + memória + tempo + linhas). Com base
nesses dados, crie a classe “Linguagem” que represente as linguagens com seus respectivos atributos e
métodos. No “main”, leia o arquivo CSV contendo os dados obtidos no benchmark, converta cada linha do
arquivo em um objeto e os armazene em um vector. Em seguida, analise os objetos armazenados no vector e
mostre na tela:
a. Listagem apresentando os nomes das linguagens e seus respectivos desempenhos, com duas casas decimais;
b. Nome das métricas e valor médio de cada métrica entre todas as linguagens, com três casas decimais;
c. Nome e desempenho da linguagem com o menor desempenho;
d. Todos os dados da linguagem com o maior desempenho, inclusive o desempenho calculado;

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

class Linguagem
{
private:
    string linguagem;
    int cpu;
    float memoria;
    int tempo;
    int linhas;

public:
    float getCPU()
    {
        return this->cpu;
    }
    float getMemoria()
    {
        return this->memoria;
    }
    float getTempo()
    {
        return this->tempo;
    }
    float getLinhas()
    {
        return this->linhas;
    }
    string getLinguagem()
    {
        return this->linguagem;
    }

    Linguagem(string linha)
    {
        char separador;
        stringstream ss(linha);
        getline(ss, this->linguagem, ',');
        ss >> this->cpu;
        ss >> separador;
        ss >> this->memoria;
        ss >> separador;
        ss >> this->tempo;
        ss >> separador;
        ss >> this->linhas;
    }

    float desempenho()
    {
        // desempenho = 106 / (cpu * 100 + memória + tempo + linhas)

        float desempenho = pow(10, 6) / (cpu * 100 + memoria + tempo + linhas);
        return desempenho;
    }

    void imprimir()
    {

        cout << setprecision(2) << fixed;
        cout << "Linguagem: " << this->linguagem << endl;
        /*
        cout << "Tempo de CPU: " << this->cpu << endl;
        cout << "Memoria: " << this->memoria << endl;
        cout << "Tempo: " << this->tempo << endl;
        cout << "Linhas: " << this->linhas << endl;
        */
        cout << "Desempenho: " << desempenho() << endl;
        cout << "*************************************" << endl;
    }

        void imprimirInteiro()
    {

        cout << setprecision(2) << fixed;
        cout << "Linguagem: " << this->linguagem << endl;
        cout << "Tempo de CPU: " << this->cpu << endl;
        cout << "Memoria: " << this->memoria << endl;
        cout << "Tempo: " << this->tempo << endl;
        cout << "Linhas: " << this->linhas << endl;
        cout << "Desempenho: " << desempenho() << endl;
        cout << "*************************************" << endl;
    }
};

int main()
{

    vector<Linguagem *> linguagens;
    vector<Linguagem *>::iterator it;
    string linha;
    Linguagem* linguagem_menor = nullptr;
    Linguagem* linguagem_maior = nullptr;

    float soma_cpu = 0;
    float soma_memoria = 0;
    float soma_tempo = 0;
    float soma_linhas = 0;
    float menor_desempenho = INFINITY;
    float maior_desempenho = -1;

    fstream fs;
    fs.open("benchmark.csv", fstream::in);
    if (fs.is_open())
    {
        getline(fs, linha);
        while (getline(fs, linha))
        {
            linguagens.push_back(new Linguagem(linha));
        }
        fs.close();
        cout << linguagens.size() << " linguagens lidas do arquivo\n"
             << endl;
        int tamanho = linguagens.size();

        for (it = linguagens.begin(); it != linguagens.end(); it++)
        {
            (*it)->imprimir();
        }
    }

    for (it = linguagens.begin(); it != linguagens.end(); it++)
    {
        soma_cpu += (*it)->getCPU();
        soma_memoria += (*it)->getMemoria();
        soma_tempo += (*it)->getTempo();
        soma_linhas += (*it)->getLinhas();
    }
    float tamanho = linguagens.size();

    float media_cpu = soma_cpu / tamanho;
    float media_memoria = soma_memoria / tamanho;
    float media_tempo = soma_tempo / tamanho;
    float media_linhas = soma_linhas / tamanho;

    cout << setprecision(3) << fixed;
    cout << "\nMedia de tempo de CPU: " << media_cpu << endl;
    cout << "Media de memoria: " << media_memoria << endl;
    cout << "Media de tempo: " << media_tempo << endl;
    cout << "Media de linhas: " << media_linhas << endl
         << endl;

    // Questao c

    for (it = linguagens.begin(); it != linguagens.end(); it++)
    {
        float temp = (*it)->desempenho();
        if(temp < menor_desempenho){
            menor_desempenho = temp;
            linguagem_menor = *it;
        }

    }

    if(linguagem_menor != nullptr){
        cout << "\n*************************************" << endl;
        cout << setprecision(2) << fixed;
        cout << "Linguagem com menor desempenho: " << endl;
        cout << linguagem_menor->getLinguagem() << ": " << menor_desempenho << endl;
    }


    for (it = linguagens.begin(); it != linguagens.end(); it++)
    {
        float temp = (*it)->desempenho();
        if(temp > maior_desempenho){
            maior_desempenho = temp;
            linguagem_maior = *it;
        }

    }

    if(linguagem_maior != nullptr){
        cout << "\n*************************************" << endl;
        cout << "Linguagem com maior desempenho: " << endl;
        linguagem_maior->imprimirInteiro();
    }

    for (it = linguagens.begin(); it != linguagens.end(); it++)
    {
        delete *it;
    }

    return 0;
}