/*

Modifique o exercício anterior para varrer o vector e mostrar o menor
número, o maior número e a média aritmética;

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int resposta;

    vector<int> v = {};

    do{
        cout << "Digite um numero, ou '0' para sair: ";
        cin >> resposta;
        if(resposta == 0){
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
    for(rit = v.rbegin(); rit != v.rend(); rit++){
        if(*rit < menor) menor = *rit;
        if(*rit > maior) maior = *rit;
        soma += *rit;
    }

    cout << "Menor: " << menor << endl;
    cout << "Maior: " << maior << endl;
    cout << "Soma: " << soma << endl;
    cout << "Tamanho: " << v.size() << endl;
    cout << "Média: " << soma / v.size() << endl;
    
    
    return 0;
}
