/*

Declare uma estrutura list que armazena números inteiros e a alimente com 10 números
informados pelo usuário. Em seguida, realize as operações utilizando métodos da própria STL:
a) Mostre o menor valor;
b) Mostre o maior valor;
c) Ordene a lista em ordem crescente e mostre na tela, em uma única linha;
d) Ordene a lista em ordem decrescente e mostre na tela, em uma única linha;
e) Peça para o usuário digitar um número e o remova da lista. Mostre a lista em uma única linha;
f) Elimine elementos duplicados e mostre a lista em uma única linha;


*/
#include <iostream>
#include <list>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int cont = 0;
    int usuario = 0;
    list<int> numeros = {5, 3, 8, 3, 1, 6, 7, 3, 2, 4};
    
    do{
        /*
        cout << "Digite um numero: ";
        cin >> usuario;
        numeros.push_back(usuario);
        */
        
        cont++;

    }while(cont != 10);
    cout << endl;

    list<int>::const_iterator it;
    for(it = numeros.begin(); it != numeros.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    list<int>::iterator pos;
    pos = min_element(numeros.begin(), numeros.end());
    cout << "Min: " << *pos << endl;

    pos = max_element(numeros.begin(), numeros.end());
    cout << "Max: " << *pos << endl;

    cout << "Numeros em ordem crescente: ";
    numeros.sort();
    for (pos = numeros.begin(); pos != numeros.end(); pos++){
        cout << *pos << " ";
    }

    cout << "\nNumeros em ordem decrescente: ";
    numeros.sort(greater<int>());
    for(pos = numeros.begin(); pos != numeros.end(); pos++){
        cout << *pos << " ";
    }
    cout << endl;

    int remover;
    cout << "Digite um numero para remover: ";
    cin >> remover;

    numeros.remove(remover);

    cout << "\nNumeros apos remover: ";
    for(pos = numeros.begin(); pos != numeros.end(); pos++){
        cout << *pos << " ";
    }

    //Unique so remove numeros iguais consecutivos
    numeros.sort();
    numeros.unique();
    cout << "\nNumeros apos remover duplicatas: ";
    for(pos = numeros.begin(); pos != numeros.end(); pos++){
        cout << *pos << " ";
    }


    //Remove todos numeros que aparecem mais de uma vez, nao apenas as copias
    numeros = {5, 3, 8, 3, 1, 6, 7, 3, 2, 4};
    map<int, int> contagem;
    for (int n : numeros){
        contagem[n]++;
    }

    for(it = numeros.begin(); it != numeros.end(); ){
        if (contagem[*it] > 1){
            it = numeros.erase(it);
        }
        else{
            it++;
        }
    }
    cout << endl;

    for(it = numeros.begin(); it != numeros.end(); it++){
        cout << *it << " ";
    }
    cout << endl;


    
    
    return 0;
}
