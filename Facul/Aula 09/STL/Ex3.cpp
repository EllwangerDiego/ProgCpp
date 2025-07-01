/*

Peça para o usuário digitar uma frase qualquer, com diversas palavras. Em seguida, crie uma
estrutura map<char,int> e armazene na parte char as letras da frase, sem repetição. Na parte int
correspondente a cada letra, armazene a quantidade de vezes que a letra aparece na frase.

*/
#include <iostream>
#include <map>
using namespace std;

int main() {

    typedef map<char, int> CharIntMap;
    CharIntMap lista;
    string frase;

    cout << "Digite uma frase: ";
    getline(cin, frase);

    cout << endl;

    for(int i = 0; i < frase.length(); i++ ){
        char letra = frase[i];
        if (isalpha(letra)){
            letra = tolower(letra);
            lista[letra]++;
        }
    }
    
    CharIntMap::iterator it;
    for(it = lista.begin(); it != lista.end(); it++){
        cout << "Letra: \"" << it->first << "\" "
        << "Quantidade de vezes: " << it->second << endl;
    }
    
    
    return 0;
}
