/*

(3,0 pontos) Crie uma matriz de caracteres com dimensão 4 linhas por 6 colunas e peça para
usuário informar apenas os valores da primeira linha. Em seguida, realize os procedimentos:
a. A segunda linha deve ser uma cópia da primeira, em ordem inversa das colunas.
b. A terceira linha deve inverter cada letra - trocar maiúsculas por minúsculas e vice-versa.
c. A quarta linha deve conter as vogais digitadas, seguido das consoantes.
d. Imprima a matriz normal e a transposta.
Dica: Use os métodos "isupper", "islower", "toupper" e "tolower" da biblioteca "cctype" ou "ctype.h"

*/

#include <iostream>
#include <cctype>  // para isupper, islower, toupper, tolower

using namespace std;

bool ehVogal(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    const int linhas = 4;
    const int colunas = 6;
    char matriz[linhas][colunas];

    cout << "Digite 6 caracteres para a primeira linha:" << endl;
    for (int j = 0; j < colunas; j++) {
        cin >> matriz[0][j];
    }

    // a) Segunda linha = primeira linha invertida
    for (int j = 0; j < colunas; j++) {
        matriz[1][j] = matriz[0][colunas - 1 - j];
    }

    // b) Terceira linha = troca maiúsculas por minúsculas e vice-versa da primeira linha
    for (int j = 0; j < colunas; j++) {
        if (isupper(matriz[0][j])) {
            matriz[2][j] = tolower(matriz[0][j]);
        } else if (islower(matriz[0][j])) {
            matriz[2][j] = toupper(matriz[0][j]);
        } else {
            // Se não for letra, mantém o caractere
            matriz[2][j] = matriz[0][j];
        }
    }

    // c) Quarta linha = vogais primeiro, depois consoantes da primeira linha
    int pos = 0;
    // Primeiro as vogais
    for (int j = 0; j < colunas; j++) {
        if (ehVogal(matriz[0][j])) {
            matriz[3][pos++] = matriz[0][j];
        }
    }
    // Depois as consoantes
    for (int j = 0; j < colunas; j++) {
        if (!ehVogal(matriz[0][j])) {
            matriz[3][pos++] = matriz[0][j];
        }
    }

    // Imprime matriz normal
    cout << "\nMatriz normal:" << endl;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << matriz[i][j] << ' ';
        }
        cout << endl;
    }

    // Imprime matriz transposta
    cout << "\nMatriz transposta:" << endl;
    for (int j = 0; j < colunas; j++) {
        for (int i = 0; i < linhas; i++) {
            cout << matriz[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
