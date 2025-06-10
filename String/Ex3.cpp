#include <iostream>
#include <cstdio>

using namespace std;

int main() {

    const char* nome = "Joao";
    const char* cidade = "Novo Hamburgo";
    const char* profissao = "Medico";

    char frase[200];

    sprintf(frase, "%s eh um %s que atua em %s!", nome, profissao, cidade);
    cout << frase << endl;

    return 0;
}