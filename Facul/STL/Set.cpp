#include <iostream>
#include <set>
using namespace std;

int main()
{
    //typedef faz apelido, nesse caso, chamado IntSet;
    typedef set<int> IntSet;
    //greater<> para ordem decrescente
    //Ex com greater
    // typedef set<int, greater<int>> IntSet;

    //Insere e organiza em ordem crescente
    
    //declaração do objeto coll, do tipo IntSet. Ela serve para criar a estrutura de dados
    IntSet coll;
    coll.insert(3);
    coll.insert(1);
    coll.insert(5);
    coll.insert(4);
    //Ele ignora duplicatas, como esse:
    coll.insert(1);
    coll.insert(6);
    coll.insert(2);

    IntSet::const_iterator pos;

    for (pos = coll.begin(); pos != coll.end(); ++pos)
        cout << *pos << ' ';

    cout << endl;

    return 0;
}