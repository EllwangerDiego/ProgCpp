#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int tamanho = 0;
    float nota;
    float soma = 0;
    float maior = 0;
    float menor = 0;
    int maiorVezes = 0;
    int menorVezes = 0;

    // Contadores de faixas
    int faixa1 = 0, faixa2 = 0, faixa3 = 0, faixa4 = 0;
    int faixa5 = 0, faixa6 = 0, faixa7 = 0, faixa8 = 0;

    cout << "Digite o tamanho da turma: ";
    cin >> tamanho;

    float turma[tamanho];

    for (int i = 0; i < tamanho; i++) {
        cout << "Digite a nota: ";
        cin >> nota;
        turma[i] = nota;
    }

    menor = turma[0];

    for (int i = 0; i < tamanho; i++) {
        float n = turma[i];

        if (n > maior) {
            maior = n;
            maiorVezes = 0;
        }
        if (n < menor) {
            menor = n;
            menorVezes = 0;
        }

        if (n == maior) maiorVezes++;
        if (n == menor) menorVezes++;

        soma += n;

        // Histograma
        if (n >= 0.0 && n <= 3.0)
            faixa1++;
        else if (n > 3.0 && n <= 4.0)
            faixa2++;
        else if (n > 4.0 && n <= 5.0)
            faixa3++;
        else if (n > 5.0 && n <= 6.0)
            faixa4++;
        else if (n > 6.0 && n <= 7.0)
            faixa5++;
        else if (n > 7.0 && n <= 8.0)
            faixa6++;
        else if (n > 8.0 && n <= 9.0)
            faixa7++;
        else if (n > 9.0 && n <= 10.0)
            faixa8++;
    }

    // Resultados
    cout << "\n\nResultado da avaliacao da turma:\n";
    cout << fixed << setprecision(1);
    cout << "Menor nota: " << menor << " (" << menorVezes << "x)" << endl;
    cout << "Maior nota: " << maior << " (" << maiorVezes << "x)" << endl;
    cout << setprecision(2) << "Media da turma: " << soma / tamanho << endl;

    cout << "\nHistograma das notas:\n";
    cout << "0.0 ~ 3.0: " << string(faixa1, '*') << endl;
    cout << "3.1 ~ 4.0: " << string(faixa2, '*') << endl;
    cout << "4.1 ~ 5.0: " << string(faixa3, '*') << endl;
    cout << "5.1 ~ 6.0: " << string(faixa4, '*') << endl;
    cout << "6.1 ~ 7.0: " << string(faixa5, '*') << endl;
    cout << "7.1 ~ 8.0: " << string(faixa6, '*') << endl;
    cout << "8.1 ~ 9.0: " << string(faixa7, '*') << endl;
    cout << "9.1 ~ 10.0: " << string(faixa8, '*') << endl;

    return 0;
}
