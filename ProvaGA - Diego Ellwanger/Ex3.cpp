#include <iostream>
#include <iomanip> // para setprecision

using namespace std;

void processaBuffer(int* buffer, int tamanho) {
    if (tamanho == 0) {
        cout << "Nenhum número foi digitado." << endl;
        return;
    }

    // a) Mostrar todos os números
    cout << "Números digitados: ";
    for (int i = 0; i < tamanho; i++) {
        cout << buffer[i] << " ";
    }
    cout << endl;

    // b) Encontrar menor valor
    int menor = buffer[0];
    // c) Encontrar maior valor
    int maior = buffer[0];
    // Para soma (média)
    double soma = 0;

    for (int i = 0; i < tamanho; i++) {
        if (buffer[i] < menor) menor = buffer[i];
        if (buffer[i] > maior) maior = buffer[i];
        soma += buffer[i];
    }

    cout << "Menor valor: " << menor << endl;
    cout << "Maior valor: " << maior << endl;
    cout << fixed << setprecision(3);
    cout << "Média: " << (soma / tamanho) << endl;
}

int main() {
    const int capacidade = 10;
    int* buffer = new int[capacidade];

    int count = 0;
    cout << "Digite até 10 números inteiros positivos (0 para parar):" << endl;

    while (count < capacidade) {
        int num;
        cin >> num;

        if (num == 0) {
            // Para entrada e não armazena o zero
            break;
        }

        if (num < 0) {
            cout << "Número inválido, digite um inteiro positivo ou zero para parar." << endl;
            continue;
        }

        buffer[count] = num;
        count++;
    }

    processaBuffer(buffer, count);

    delete[] buffer; // libera memória

    return 0;
}
