#include <iostream>
#include <windows.h>

using namespace std;


int main(){


    int matriz[10] = { 1,2,3,4,105,6,7,8,9,10};

    matriz[2] = 333;

    cout << "Tamanho do Array: " << sizeof(matriz) / sizeof(matriz[0]) << endl;

    for (int i = 0;i < 10; i++)
        cout << matriz[i] << endl;

    return 0;
}


/*
int main(){


    char matriz[11] = {"Curso de C"};

    //matriz[2] = 333;

    for (int i = 0;i < 10; i++)
        cout << matriz[i] << endl;

    return 0;
}
*/