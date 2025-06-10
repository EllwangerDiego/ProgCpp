#include <iostream>
#include <ctime>

using namespace std;

int main(){

    // pseudo-random = NOT truly random (but close)

    srand(time(NULL));

    //Num entre 1 e 6 (dado de 6 lados)
    int num = (rand() % 6) + 1;

    //Num entre 1 e 20 (dado de 20 lados)
    int num2 = (rand() % 20) + 1;


    cout << "Dado de 6 lados: " << num << endl;
    cout << "Dado de 20 lados: " << num2 << endl;

    return 0;
}