#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){

    char frase[200] = "Hoje vou comer pizza";
    char palavra[20] = "jogar";

    char resultado[100];

    if (strstr(frase, palavra) != nullptr) {
        sprintf(resultado, "A palavra %s esta na frase.",palavra);
        cout << resultado << endl;
    }
    else {
        sprintf(resultado, "A palavra %s nao esta na frase.",palavra);
        cout << resultado << endl;
    }
    return 0;
}