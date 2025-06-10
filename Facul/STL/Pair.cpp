#include <utility>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    pair<string, double> product1;
    pair<string, double> product2("Tomate", 2.35);
    pair<string, double> product3(product2);

    product1 = make_pair("Cebola", 0.99);
    product2.first = "Batata";
    product2.second = 3.98;

    cout << product1.first << " = $" << product1.second << '\n';
    cout << product2.first << " = $" << product2.second << '\n';
    cout << product3.first << " = $" << product3.second << '\n';

    return 0;
}