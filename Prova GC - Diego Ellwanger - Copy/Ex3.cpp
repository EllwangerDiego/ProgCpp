/*

(4,0 pontos). O risco de um ativo de tecnologia é obtido a partir da multiplicação da probabilidade deste ser
comprometido em um ataque pelo impacto que a perda deste ativo causa ao processo de negócio em que ele é
utilizado, ou seja: R = P * I * 100, em que R é o risco, P é a probabilidade e I o impacto. Com base nessas
informações, defina a classe “Ativo”, que recebe no seu construtor uma linha de um arquivo, interprete e
armazene os dados nos seus respectivos atributos, e calcule o risco através de uma função. Desenvolva um
programa orientado a objetos que carregue os dados de ativos a partir do arquivo CSV de exemplo, e apresente
ao usuário as seguintes informações:
a. Listagem com o nome de cada ativo e seu risco, com duas casas decimais;
b. Risco médio de todos os ativos, com duas casas decimais;
c. Nome, probabilidade e risco do ativo com maior risco;
e. Nome, impacto e risco do ativo com menor impacto ao processo de negócio.
No final, não esqueça de liberar os objetos instanciados

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>


using namespace std;

class Ativo{
    private:
        string ativo;
        float probabilidade;
        float impacto;

    public:
        string getAtivo(){
            return this-> ativo;
        }
        float getProbabilidade(){
            return this-> probabilidade;
        }
        float getImpacto(){
            return this-> impacto;
        }

        Ativo(string linha){
            char separador;
            stringstream ss(linha);
            getline(ss, this->ativo, ',');
            ss >> this-> probabilidade;
            ss >> separador;
            ss >> this-> impacto;
        }

        float Risco(){
            // R = P * I * 100, em que R é o risco, 
            //P é a probabilidade e I o impacto.
            return this->probabilidade * this-> impacto * 100;

        }

        void imprimir(){
            cout << setprecision(2) << fixed;
            cout << "Ativo: " << this->ativo << endl;
            cout << "Risco: " << Risco() << endl;
            cout << "*********************************" << endl;
        }


        void imprimirNomeProbRisco(){
            cout << setprecision(2) << fixed;
            cout << "Ativo: " << this->ativo << endl;
            cout << "Probabilidae: " << this->probabilidade << endl;
            cout << "Risco: " << Risco() << endl;
            //cout << "*********************************" << endl;
        }

        //Nome, impacto e risco
        void imprimirNomeImpactoRisco(){
            cout << setprecision(2) << fixed;
            cout << "Ativo: " << this->ativo << endl;
            cout << "Impacto: " << this->impacto << endl;
            cout << "Risco: " << Risco() << endl;
            cout << "*********************************" << endl;

        }

};

int main(){

    vector<Ativo*> ativos;
    vector<Ativo*>::iterator it;
    string linha;
    float somaRisco = 0;
    float maiorRisco = 0;
    float menorImpacto = INFINITY;  
    Ativo* ativoMaiorRisco = nullptr;
    Ativo* ativoMenorImpacto = nullptr;


    fstream fs;
    fs.open("arquivo.csv", fstream::in);
    if(fs.is_open()){
        getline(fs, linha);
        while(getline(fs, linha)){
            ativos.push_back(new Ativo(linha));
        }
        fs.close();
        cout << "\n";
        cout << ativos.size() << " ativos lidos do arquivo" << endl;
        cout << "*********************************" << endl;
    }

    for(it = ativos.begin(); it != ativos.end();it++){
        (*it)->imprimir();
    }

    for(it = ativos.begin(); it != ativos.end();it++){
        somaRisco += (*it)->Risco();

    }
    float riscoMedio = somaRisco / ativos.size();
    cout << setprecision(2) << fixed;
    cout << "Risco médio de todos os ativos: " << riscoMedio << endl << endl;

    for(it = ativos.begin(); it != ativos.end(); it++){
        float temp = (*it)->Risco();
        if(temp > maiorRisco){
            maiorRisco = temp;
            ativoMaiorRisco = *it;

        }
    }

    if(ativoMaiorRisco != nullptr){
        cout << "*********************************" << endl;
        cout << "Ativo com maior risco: " << endl;
        ativoMaiorRisco->imprimirNomeProbRisco();


    }
    //Nome, impacto e risco do ativo com menor impacto ao processo de negócio.
    for(it = ativos.begin(); it != ativos.end(); it++){
        float temp = (*it)->getImpacto();
        if(temp < menorImpacto){
            menorImpacto = temp;
            ativoMenorImpacto = *it;
        }
    }

    if(ativoMenorImpacto != nullptr){
        cout << "*********************************" << endl;
        cout << "Ativo com menor impacto: " << endl;
        ativoMenorImpacto->imprimirNomeImpactoRisco();


    }

    for(it = ativos.begin(); it != ativos.end(); it++){
        delete *it;
    }

    return 0;
}