/* 

Modifique o exercício anterior para mostrar em uma linha os elementos
com valor par e na linha abaixo os com valor ímpar. Os elementos pares
devem ser apresentados na ordem inversa a que foram digitados, e os
ímpares na ordem direta;

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int resposta;

    vector<int> v;
    vector<int> pares;
    vector<int> impares;

    do{
        cout << "Digite um numero, ou '0' para sair: ";
        cin >> resposta;
        //Verifica se o vetor está vazio (retorna true ou false):
        if(v.empty()){
            cout << "Nenhum numero foi digitado!" << endl;
        }
        else if(resposta == 0){
            break;
        }
        else{
            v.push_back(resposta);
        }
    }while (resposta!= 0);

    int menor = *v.begin();
    int maior = *v.begin();
    float soma = 0;

    vector<int>::reverse_iterator rit;
    vector<int>::iterator it;
    for(rit = v.rbegin(); rit != v.rend(); rit++){
        if(*rit < menor) menor = *rit;
        if(*rit > maior) maior = *rit;

        if(*rit % 2 == 0){
            pares.push_back(*rit);
        }
        else{
            impares.push_back(*rit);
        }

        soma += *rit;
    }

    cout << "Menor: " << menor << endl;
    cout << "Maior: " << maior << endl;
    cout << "Soma: " << soma << endl;
    cout << "Tamanho: " << v.size() << endl;
    cout << "Média: " << soma / v.size() << endl;

    cout << "Pares: ";
    for(it = pares.begin(); it != pares.end(); it++){
        cout << *it << ' ';
    }
    cout << endl;
    cout << "Impares: ";
    for(rit = impares.rbegin(); rit != impares.rend(); rit++){
        cout << *rit << ' ';
    }
    
    
    return 0;
}