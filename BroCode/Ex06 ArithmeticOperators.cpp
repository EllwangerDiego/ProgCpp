#include <iostream>
using namespace std;

//Return the result of a specific arithmetic operation (+  -  *  /)
int main(){

    int students = 20;

    students += 1;
    // ++ e -- Usado mais em loops
    students++;

    cout << students << endl;

    students *= 2;
    cout << students << endl;

    int restante = students % 3;
    cout << restante << endl;

    //Maneira para identificar se o numero eh par:
    int par = students % 2;
    //se retornar 0, significa que o numero eh par.

    //Maneira para identificar se o numero eh impar:
    int impar = students % 3;
    //se nao retornar 0, significa que o numero eh impar.

    return 0;
}