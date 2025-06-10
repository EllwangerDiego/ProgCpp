/*

(3,0 pontos) Crie uma função chamada "contaPalavras" que recebe como parâmetro um número
inteiro "n" seguido de uma frase "f". A função deve devolver a quantidade de palavras contidas na
frase "f" com "n" letras ou menos. Considere o separador de palavras como sendo um único espaço.
No main, peça para o usuário digitar uma frase e um número. Em seguida, chame a função de
contagem de palavras passando ambos os parâmetros. Ainda no main, imprima: "A frase possui "X"
palavras com "n" letras ou menos.", onde "x" é o valor retornado pela função.
Exemplo: Frase = "Uma simples frase com diversas palavras aqui" e letras = 5
Saída: A frase informada possui 4 palavras com 5 letras ou menos.

*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int contaPalavras(int n, const string& frase) {
    stringstream ss(frase);
    string palavra;
    int contador = 0;

    while (ss >> palavra) {
        if ((int)palavra.length() <= n) {
            contador++;
        }
    }

    return contador;
}

int main() {
    string frase;
    int n;

    cout << "Digite uma frase: ";
    getline(cin, frase);

    cout << "Digite um número inteiro: ";
    cin >> n;

    int resultado = contaPalavras(n, frase);

    cout << "A frase informada possui " << resultado << " palavras com " << n << " letras ou menos." << endl;

    return 0;
}
