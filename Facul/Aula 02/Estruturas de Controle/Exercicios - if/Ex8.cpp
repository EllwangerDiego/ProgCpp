/*

Utilizando a equação do MRU (distância = velocidade * tempo),
desenvolva um programa que solicite os 3 dados, mas receba
apenas 2 e calcule o terceiro. Os dados devem ser números
fracionários, e o dado a ser calculado deve ser informado como
zero.

*/

#include <iostream>
#include <ctime>
using namespace std;

int main() {
    
    float distancia;
    float velocidade;
    float tempo;
    int opcao;
    int controle = 0;

    for(int i = 0; i < 2; i++){
        cout << "1. Distancia" << endl;
        cout << "2. Velocidade" << endl;
        cout << "3. Tempo" << endl;

        cout << "\nDigite sua opcao: ";
        cin >> opcao;


        if(opcao == 1 && controle != opcao){
            cout << "Digite a distancia: ";
            cin >> distancia;
        }
        else if(opcao == 2 && controle != opcao){
            cout << "Digite a velocidade: ";
            cin >> velocidade;
        }
        else if(opcao == 3 && controle != opcao){
            cout << "Digite o tempo: ";
            cin >> tempo;
        }

        controle = opcao;

    }

    if(distancia == 0){
        distancia = velocidade * tempo;
        cout << "Distancia: " << distancia << endl;
    }
    else if(velocidade == 0){
        velocidade = distancia / tempo;
        cout << "Velocidade: " << velocidade << endl;
    }
    else if(tempo == 0){
        tempo = distancia / velocidade;
        cout << "Tempo: " << tempo << endl;
    }
    else{
        cout << "Error 2" << endl;
    }


    return 0;
}
