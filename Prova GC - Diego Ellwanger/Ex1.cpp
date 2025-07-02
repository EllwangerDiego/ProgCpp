/*

(3,0 pontos). Faça um programa que solicite ao usuário que ele informe um nome completo, e em seguida,
imprima na tela a quantidade total de letras do nome (sem contar os espaços), a quantidade de vogais e a
quantidade de consoantes do nome. Não deve diferenciar maiúsculas de minúsculas, nem eliminar da contagem
as letras duplicadas. Para facilitar o algoritmo, ao digitar o nome, não informe acentos.

*/

#include <iostream>
#include <string>
using namespace std;

int contaVogais(const char s[]);
int contaLetras(const char s[]);
int contaConsoantes(const char s[]);

int main()
{
    string frase;
    cout << "Informe seu nome completo: ";
    getline(cin, frase);
    cout << "Frase contem " << contaLetras(frase.c_str()) << " letras" << endl;
    cout << "Frase contem " << contaVogais(frase.c_str()) << " vogais" << endl;
    cout << "Frase contem " << contaConsoantes(frase.c_str()) << " consoantes" << endl;
    

    return 0;
}

int contaLetras(const char s[])
{
    int numLetras = 0, i, j;
    char letras[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (i = 0; s[i] != '\0'; i++)
        for (j = 0; letras[j]; j++)
            if (letras[j] == s[i])
            {
                numLetras++;
                break;
            }
    return numLetras;
}

int contaVogais(const char s[])
{
    int numVogais = 0, i, j;
    char vogais[] = "aeiouAEIOU";
    for (i = 0; s[i] != '\0'; i++)
        for (j = 0; vogais[j]; j++)
            if (vogais[j] == s[i])
            {
                numVogais++;
                break;
            }
    return numVogais;
}


int contaConsoantes(const char s[])
{
    int numConsoantes = 0, i, j;
    char consoantes[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    for (i = 0; s[i] != '\0'; i++)
        for (j = 0; consoantes[j]; j++)
            if (consoantes[j] == s[i])
            {
                numConsoantes++;
                break;
            }
    return numConsoantes;
}