#include <iostream>
#include <cstring>

using namespace std;

void exercicio(char palavra1[100], char palavra2[100]);
void tamanho(char palavra1[100], char palavra2[100]);

int main(){
    char palavra1[100], palavra2[100];

    cout << "Digite uma palavra: ";
    cin.getline(palavra1,100);
    cout << endl;

    cout << "Digite outra palavra: ";
    cin.getline(palavra2,100);
    cout << endl;

    exercicio(palavra1,palavra2);
    tamanho(palavra1, palavra2);




    return 0;
}

void exercicio(char palavra1[100], char palavra2[100]){

    int resultado = strcmp(palavra1, palavra2);

    if (resultado == 0){
        cout << "As palavras sao iguais" << endl;
    }
    else if (resultado < 0){
        cout << "A primeira palavra eh anterior a segunda na ordem alfabetica" << endl;
    }
    else {
        cout << "A primeira palavra eh posterior a segunda na ordem alfabetica" << endl;
    }
}

void tamanho(char palavra1[100], char palavra2[100]){
    cout << "Palavra 1" << endl;
    //cout << "Tamanho do array: " << sizeof(palavra1) << endl;
    cout << "Tamanho da palavra: " << strlen(palavra1);
    cout << endl;

    cout << "Palavra 2" << endl;
    //cout << "Tamanho do array: " << sizeof(palavra2) << endl;
    cout << "Tamanho da palavra: " << strlen(palavra2) << endl;
}