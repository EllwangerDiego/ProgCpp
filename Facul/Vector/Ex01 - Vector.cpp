/* 

Solicite ao usuário uma quantidade indeterminada de números inteiros. A
cada solicitação, adicione o número em um vector. Quando o usuário
digitar 0 (zero), deve varrer o vector usando iterator e listar todos os seus
elementos um ao lado do outro, separados por um espaço. Não deve listar
o zero;

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int resposta;
    vector<int> v = {};
    do{
        cout << "Digite um numero ou '0' para parar: ";
        cin >> resposta;
        if(resposta == 0){
            break;
        }
        else{
            v.push_back(resposta);
        }

    }while(resposta != 0);   
    vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    return 0;
}
