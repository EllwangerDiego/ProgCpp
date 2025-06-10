/*

Modifique o exercício anterior e mostre os elementos do vector na ordem
inversa a que foram digitados, usando iterator reverso;

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

    vector<int>::reverse_iterator rit;
    for(rit = v.rbegin(); rit != v.rend(); rit++){
        cout << *rit << ' ';
    }
    
    return 0;
}
