#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    //A diferença é que no map cada chave é única, enquanto no multimap uma chave pode aparecer várias vezes.
    typedef multimap<int, string> IntStringMMap;
    IntStringMMap coll;

    coll.insert(make_pair(5, "tagged"));
    coll.insert(make_pair(2, "a"));
    //chave com 2 valores #1:
    coll.insert(make_pair(1, "this"));
    coll.insert(make_pair(4, "of"));
    coll.insert(make_pair(6, "strings"));
    //chave com 2 valores #2:
    coll.insert(make_pair(1, "is"));
    coll.insert(make_pair(3, "multimap"));

    IntStringMMap::iterator pos;

    for (pos = coll.begin(); pos != coll.end(); ++pos)
        cout << pos->second << ' ';

    cout << endl;

    return 0;
}