/*

(3,0 pontos). Em uma estrutura de repetição, solicite que o usuário informe números inteiros positivos e os
armazene em um vector. Quando o usuário digitar 0 (zero), deve encerrar a solicitação dos números e não deve
armazenar o zero no vector. Após a entrada dos dados, use um iterador para percorrer o vector do primeiro ao
último elemento, somando os números pares e subtraindo os ímpares. Mostre na tela toda a sequência de
operações realizadas e o resultado final obtido.
Ex 1: Se digitar 1 3 2 4 3 5 4 6 0, deve ser impresso na tela: - 1 - 3 + 2 + 4 - 3 - 5 + 4 + 6 = 4
Ex 2: Se digitar 4 2 3 1 4 5 3 1 0, deve ser impresso na tela: + 4 + 2 - 3 - 1 + 4 - 5 - 3 - 1 = -3

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    vector<int> meuvetor;

    int somaTotal = 0;

    do{
        cout << "Digite um numero inteiro (0 para sair): ";
        cin >> num;
        if(num != 0 && num > 0){
            meuvetor.push_back(num);
        }
        else{
            break;
        }
    

    }while(num != 0);

    vector<int>::iterator it;
    cout << "********************************" << endl;
    for (it = meuvetor.begin(); it != meuvetor.end(); it++){
        if(*it != 0){
           if(*it % 2 == 0){
            cout << "+ " << *it << ' ';
            somaTotal += *it;
            }
            else if(*it % 2 != 0){
                cout << "- " << *it << ' ';
                somaTotal -= *it;
            } 
        }

        
    }
    cout << " = " << somaTotal << endl;
    cout << "********************************" << endl;
    
    
    return 0;
}