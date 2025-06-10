#include <iostream>
using namespace std;

int main(){

    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    //Pegar o tamanho da string
    if(name.length() > 12){
        cout << "Your name can't be over 12 characters" << endl;
    }
    else{
        cout << "Welcome to Rust " << name << endl;
    }

    //Metodo que retorna se a string esta vazia ou nao
    //Retorna bool (true ou false)
    if(name.empty()){
        cout << "You didn't enter your name" << endl;
    }
    else{
        cout << "Hello " << name << endl;
    }

    //Limpa a string
    //name.clear();
    cout << "2Hello " << name << endl;


    //Append, adiciona a string em outra string
    name.append("@gmail.com");
    cout << "Your username is now: " << name << endl;


    //Return a character at a given position in a string
    cout << "Caracter 0 do nome: " << name.at(0) << endl;


    //Insert a character at a given position, does not replace it, kinda like append but in a certain position
    name.insert(0, "@");
    cout << "Nome att: " << name << endl;


    //Find a certain character
    //Nesse caso, vai retornar a posicao do primeiro espaco
    cout << "Posicao do primeiro espaco: " << name.find(' ') << endl;


    //Apaga os caracteres name.erase(comeco, fim)
    name.erase(2,4);
    cout <<"Caracteres especificados deletados: " << name << endl;

    return 0;
}