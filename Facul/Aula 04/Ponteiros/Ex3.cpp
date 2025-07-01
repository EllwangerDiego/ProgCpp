/*

Converta o método desenvolvido anteriormente para uma função, para
que devolva o texto como uma string sem modificar o parâmetro de
entrada. Ex: “char *ajustaTexto(char *txtIN)”

*/

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
using namespace std;

char *ajustaTexto (const char *txtIN);

int main() {
    
    char texto[] = "hoje eu Vou dormir bem";



    char* resultado = ajustaTexto(texto);

    cout << "Texto ajustado: " << resultado << endl;

    free(resultado);
    
    return 0;
}
char* ajustaTexto(const char* txtIN){
    int tamanho = strlen(txtIN);

    // Aloca espaço dinâmico para a cópia + '\0'
    char* copia = (char*) malloc((tamanho + 1) * sizeof(char));
    if (copia == nullptr) {
        cout << "Erro de alocação!" << endl;
        return nullptr;
    }

    // Copia o texto de entrada para o espaço alocado
    strcpy(copia, txtIN);

    // Ajusta as letras: primeira maiúscula, resto minúsculo
    copia[0] = toupper(copia[0]);
    for (int i = 1; i < tamanho; i++){
        copia[i] = tolower(copia[i]);
    }

    return copia;
}