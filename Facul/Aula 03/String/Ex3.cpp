/*

Declare 3 variáveis e as inicialize com um nome, uma cidade e uma
profissão. Em seguida, declare e alimente uma quarta variável montando
uma nova frase com esses 3 elementos. Por fim, imprima a frase. Utilize a
função strcat. Experimente também a função sprintf

*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    
    string nome = "Diego";
    string cidade = "Novo Hamburgo";
    string profissao = "Cybersecurity";
    
    string frase;

    frase.append(nome);
    frase.append(" ");
    frase.append(cidade);
    frase.append(" ");
    frase.append(profissao);
    cout << frase;
    
    return 0;
}
