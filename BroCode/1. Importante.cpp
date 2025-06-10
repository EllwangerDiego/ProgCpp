//Formatar: Shift + Alt + F
#include <iostream>
using namespace std;
// Passar algo para uma funcao como valor, nao modifica o valor original, ele cria uma copia
// Passar algo como referencia, modifica o original

int main() {
    char guess = 'a';
    //Funcao para passar de minusculo para maiusculo
    //Implementado no Ex42 QuizGame.cpp
    guess = toupper(guess);
    cout << guess << endl;

    
    return 0;
}