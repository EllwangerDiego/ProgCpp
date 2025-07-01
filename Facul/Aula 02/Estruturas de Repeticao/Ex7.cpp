/*

Desenvolva um programa que solicite uma quantidade
indeterminada de números positivos ao usuário, e ao digitar o
número zero, calcule e informe:
• A quantidade de números digitados
• A quantidade de pares
• A quantidade de ímpares
• A soma destes números
• A média aritmética
• O maior número
• O menor número

*/

#include <iostream>
using namespace std;

int main() {
    int num;
    int pares = 0;
    int impares = 0;
    int soma = 0;
    int quantidade = 0;
    int maior, menor;
    bool primeiro = true;

    while (true) {
        cout << "Digite um numero positivo (0 para sair): ";
        cin >> num;

        if (num == 0)
            break;

        if (num < 0) {
            cout << "Numero invalido! Digite apenas positivos ou 0 para sair.\n";
            continue;
        }

        // Contagem
        quantidade++;
        soma += num;

        // Par ou ímpar
        if (num % 2 == 0)
            pares++;
        else
            impares++;

        // Maior e menor
        if (primeiro) {
            maior = menor = num;
            primeiro = false;
        } else {
            if (num > maior)
                maior = num;
            if (num < menor)
                menor = num;
        }
    }

    // Resultados
    if (quantidade > 0) {
        float media = (float)soma / quantidade;

        cout << "\nQuantidade de numeros digitados: " << quantidade << endl;
        cout << "Quantidade de pares: " << pares << endl;
        cout << "Quantidade de impares: " << impares << endl;
        cout << "Soma dos numeros: " << soma << endl;
        cout << "Media aritmetica: " << media << endl;
        cout << "Maior numero: " << maior << endl;
        cout << "Menor numero: " << menor << endl;
    } else {
        cout << "\nNenhum numero valido foi digitado.\n";
    }

    return 0;
}
