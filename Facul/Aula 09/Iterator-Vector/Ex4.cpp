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
    cout << "\n";


    // Verifica par e imprime
    cout << "Numeros pares: ";
    vector<int>::reverse_iterator rit;
    for(rit = meuvetor.rbegin(); rit != meuvetor.rend(); rit++){
        if(*rit % 2 == 0){
            cout << *rit << "  ";
        }
    }
    cout << "\n";

    // Verificar impar e imprime
    cout << "Numeros impares: ";
    for(it = meuvetor.begin(); it != meuvetor.end(); it++){
        if(*it % 2 != 0){
            cout << *it << "  ";
        }
    }
    cout << "\n";
    
    
    return 0;
}