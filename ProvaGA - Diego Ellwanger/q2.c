#include <stdio.h>
#include <ctype.h> // Para usar a função toupper e tolower

int isVogal(char c)
{
    char vogais[] = "aeiouAEIOU";
    for (int i = 0; vogais[i]; i++)
        if (c == vogais[i])
            return 1;
    return 0;
}

int main()
{
    char matriz[4][6];

    // Solicita ao usuário para digitar os caracteres da primeira linha
    printf("Digite 6 caracteres para a primeira linha (somente letras):\n");
    for (int i = 0; i < 6; i++)
    {
        do
        {
            printf("Digite o caractere %d: ", i + 1);
            scanf(" %c", &matriz[0][i]); // O espaço antes de %c ignora caracteres de nova linha
        } while (!isalpha(matriz[0][i])); // Garante que o usuário insira apenas letras
    }

    // a) A segunda linha é uma cópia da primeira, mas com a ordem invertida
    for (int i = 0; i < 6; i++)
        matriz[1][i] = matriz[0][5 - i];

    // b) A terceira linha inverte a caixa das letras
    for (int i = 0; i < 6; i++)
        if (isupper(matriz[0][i]))
            matriz[2][i] = tolower(matriz[0][i]); // Converte para minúscula
        else
            matriz[2][i] = toupper(matriz[0][i]); // Converte para maiúscula

    // c) A quarta linha deve conter as vogais seguidas das consoantes
    int idx = 0;

    // Vogais
    for (int i = 0; i < 6; i++)
        if (isVogal(matriz[0][i]))
            matriz[3][idx++] = matriz[0][i];

    // Consoantes
    for (int i = 0; i < 6; i++)
        if (!isVogal(matriz[0][i]))
            matriz[3][idx++] = matriz[0][i];
    
    // d) Imprime a matriz normal
    printf("\nMatriz Normal:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
            printf("%c ", matriz[i][j]);
        printf("\n");
    }

    // Imprimir a matriz transposta
    printf("\nMatriz Transposta:\n");
    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 4; i++)
            printf("%c ", matriz[i][j]);
        printf("\n");
    }

    return 0;
}
