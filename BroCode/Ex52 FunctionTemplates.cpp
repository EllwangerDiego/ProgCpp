#include <iostream>
using namespace std;

    // function template = describes what a function looks like.
    //                     Can be used to generate as many overloaded functions
    //                     as needed, each using different data types

template <typename T, typename U>

//Pode colocar auto para retornar, entao o compilador deduz o que retornar
// ou colocar U, nesse caso, para retornar o double
auto maximo(T x, U y){
    return (x > y) ? x : y;
}


int main() {
    
    cout << maximo(1, 2) << endl;
    cout << maximo(1, 2.1) << endl;
    
    return 0;
}
