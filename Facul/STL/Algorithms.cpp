#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> coll;
    vector<int>::iterator pos;

    coll.push_back(2);
    coll.push_back(5);
    coll.push_back(4);
    coll.push_back(1);
    coll.push_back(6);
    coll.push_back(3);

    pos = min_element(coll.begin(), coll.end());
    cout << "min: " << *pos << endl;

    pos = max_element(coll.begin(), coll.end());
    cout << "max: " << *pos << endl;
    
    // Ordena os elementos de um intervalo, ordem crescente
    sort(coll.begin(), coll.end());
    cout << "Vetor ordenado: ";
    for (pos = coll.begin(); pos != coll.end(); ++pos)
        cout << *pos << ' ';
    cout << endl;

    // Conta quantas vezes o número 3 aparece no vetor
    int qtd_3 = count(coll.begin(), coll.end(), 3);
    cout << "O número 3 aparece " << qtd_3 << " vez(es) no vetor." << endl;

    // Procura o primeiro elemento igual a um valor dentro de um intervalo.
    pos = find(coll.begin(), coll.end(), 3);
    reverse(pos, coll.end());
    cout << "Vetor após reversão parcial a partir do 3: ";
    for (pos = coll.begin(); pos != coll.end(); ++pos)
        cout << *pos << ' ';
    cout << endl;

    return 0;
}
