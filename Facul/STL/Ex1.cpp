/*

1) Declare uma estrutura list que armazena números inteiros e a alimente com 10 números
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
using namespace std;

int main() {
    list<int> numeros;
    int num;

    cout << "Digite 10 números inteiros:\n";
    for (int i = 0; i < 10; ++i) {
        cin >> num;
        numeros.push_back(num);
    }

    // a) Menor valor
    int menor = *min_element(numeros.begin(), numeros.end());
    cout << "Menor valor: " << menor << endl;

    // b) Maior valor
    int maior = *max_element(numeros.begin(), numeros.end());
    cout << "Maior valor: " << maior << endl;

    // c) Ordenar crescente e mostrar
    numeros.sort();
    cout << "Ordem crescente: ";
    for (int x : numeros) cout << x << " ";
    cout << endl;

    // d) Ordenar decrescente e mostrar
    numeros.reverse();
    cout << "Ordem decrescente: ";
    for (int x : numeros) cout << x << " ";
    cout << endl;

    // e) Remover número digitado e mostrar
    cout << "Digite um número para remover: ";
    cin >> num;
    numeros.remove(num);
    cout << "Lista após remoção: ";
    for (int x : numeros) cout << x << " ";
    cout << endl;

    // f) Eliminar duplicados e mostrar
    numeros.sort();
    numeros.unique();
    cout << "Lista sem duplicatas: ";
    for (int x : numeros) cout << x << " ";
    cout << endl;

    return 0;
}

