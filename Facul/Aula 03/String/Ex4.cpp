/*

A partir de dois textos armazenados nas variáveis “frase” e “palavra”,
identifique se “palavra” está contida na “frase”

*/

#include <iostream>
using namespace std;

int main() {
    
    string frase = "hoje eu vou comer churrasco";
    string palavra;
    
    cout << "Digite uma palvra para procurar na frase: ";
    cin >> palavra;

    cout << "Posicao da palavra na frase: " << frase.find(palavra) << endl;

    if(frase.find(palavra) != string::npos){
        cout << "Palavra encontrada na frase" << endl;
    }
    else{
        cout << "Palavra nao encontrada na frase" << endl;
    }
    
    return 0;
}
