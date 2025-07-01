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
    int num;
    vector<int> meuvetor;

    do{
        cout << "Digite um numero inteiro: ";
        cin >> num;
        if(num != 0){
            meuvetor.push_back(num);
        }
        else{
            break;
        }
    

    }while(num != 0);

    vector<int>::iterator it;
    for (it = meuvetor.begin(); it != meuvetor.end(); it++){
        if(*it != 0){ // ignora o 0
           cout << *it << ' '; 
        }
        
    }
    
    
    return 0;
}
