#include <stdio.h>
#include <stdlib.h>

void processaBuffer(int* buffer, int tamanho);

int main() {
    // Aloca dinamicamente o buffer para até 10 números inteiros
    int *buffer = (int*)malloc(10 * sizeof(int));
    if (buffer == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    int numero, i = 0;

    // Loop para ler números até atingir a capacidade do buffer ou até o usuário digitar 0
    while (i < 10) {
        printf("%d - Digite um número (0 para parar): ", i + 1);
        scanf("%d", &numero);

        if (numero == 0) {
            break;  // Interrompe a leitura se o número for 0
        }

        if (numero > 0) {
            buffer[i] = numero;  // Armazena o número no buffer
            i++;
        } else {
            printf("Por favor, insira um número positivo.\n");
        }
    }

    processaBuffer(buffer, i);  // Passa o buffer e o número de elementos preenchidos

    free(buffer);  // Libera o espaço de memória alocado
    return 0;
}

void processaBuffer(int* buffer, int tamanho) {
    if (tamanho == 0) {
        printf("Nenhum número foi digitado.\n");
        return;
    }

    int soma = 0;
    int menor = buffer[0];
    int maior = buffer[0];

    // Exibe os números digitados e calcula soma, menor e maior
    printf("a) Números digitados: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", buffer[i]);
        soma += buffer[i];
        if (buffer[i] < menor) {
            menor = buffer[i];
        }
        if (buffer[i] > maior) {
            maior = buffer[i];
        }
    }
    printf("\n");

    // Calcula e exibe a média com 3 casas decimais
    float media = (float)soma / tamanho;
    printf("b) Menor valor digitado: %d\n", menor);
    printf("c) Maior valor digitado: %d\n", maior);
    printf("d) Média dos valores: %.3f\n", media);
}

