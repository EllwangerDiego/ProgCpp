#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<char> coll;
    for (char c='a'; c<='z'; ++c)
        coll.push_back(c);

    while (!coll.empty())
    {
        cout << coll.front() << ' ';
        coll.pop_front();
    }
    cout << endl;
}
/*

#include <list>
list<int> l;
l.push_back(10);
l.push_front(5);
auto it = l.begin();
advance(it, 1);
l.insert(it, 7); // Inserção eficiente no meio

*/