/*

Desenvolva o método “void ajustaTexto(char *txtIN)” que recebe um
texto como referência e garanta que somente a primeira letra desse
texto seja maiúscula e as demais sejam minúsculas. Retorne o texto
ajustado para o chamador no mesmo parâmetro de entrada

*/

#include <iostream>
#include <cctype>
using namespace std;

void ajustaTexto (char *txtIN);

int main() {
    
    char texto[] = "hoje eu Vou dormir bem";



    ajustaTexto(&texto[0]);

    cout << "Texto ajustado: " << texto << endl;
    
    return 0;
}
void ajustaTexto (char *txtIN){
    txtIN[0] = toupper(txtIN[0]);
    for(int i = 1; txtIN[i] != '\0'; i++){
        txtIN[i] = tolower(txtIN[i]);
    }
}