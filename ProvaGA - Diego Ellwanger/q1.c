#include <stdio.h>
#include <string.h>

int contaPalavras(int n, char f[])
{
    int contaLetras = 0;
    int contaPalavras = 0;
    int tamFrase = strlen(f);
    for(int i = 0; i < tamFrase; i++)
        if(f[i] == ' ' || i == tamFrase - 1)
        {
            if(contaLetras <= n)
                contaPalavras++;
            contaLetras = 0;
        }
        else
            contaLetras++;

    return contaPalavras;
}

int main()
{
    int letras;
    char frase[100];

    puts("Informe uma frase:");
    fgets(frase, 100, stdin);
    puts("Informe a quantidade de letras:");
    scanf("%d", &letras);
    printf("A frase possui %d palavras com %d letras ou menos.", contaPalavras(letras, frase), letras);
    return 0;
}

