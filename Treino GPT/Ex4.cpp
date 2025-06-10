#include <iostream>
#include <windows.h>
using namespace std;

int main(){

    for (int i = 1; i <= 10; i++){
        cout << "Numero: " << i << endl;
        Sleep(300);
    }

    int num;

    do{
        cout << "Digite um numero: ";
        cin >> num;
        cout << endl;
    } while (num != 0);
    return 0;
}