/*

Modifique o exercício anterior e mostre os elementos do vector na ordem
inversa a que foram digitados, usando iterator reverso;

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

    vector<int>::reverse_iterator rit;
    for (rit = meuvetor.rbegin(); rit != meuvetor.rend(); rit++){
        if(*rit != 0){ // ignora o 0
           cout << *rit << ' '; 
        }
        
    }
    
    
    return 0;
}
