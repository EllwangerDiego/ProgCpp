#include <iostream>
#include <fstream>
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
    ifstream arquivo("frase.txt"); // abre o arquivo para leitura
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    string frase;

    // Lê a frase inteira (uma linha) do arquivo
    getline(arquivo, frase);

    arquivo.close();

    int n;
    cout << "Digite um número inteiro: ";
    cin >> n;

    int resultado = contaPalavras(n, frase);

    cout << "A frase lida do arquivo possui " << resultado << " palavras com " << n << " letras ou menos." << endl;

    return 0;
}
