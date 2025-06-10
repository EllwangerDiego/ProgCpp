#include <iostream>
using namespace std;

// do while loop = do some block of code first,
//                 THEN repeat again if condition is true

int main(){

    int number;

    //Nunca vai rodar, pq o numero que passamos eh zero
    while(number < 0 ){
        cout << "Enter a positive number: ";
        cin >> number;
    }

    cout << "The number is: " << number << endl;


    //Aqui vai rodar, pois ele roda primeiro, e depois verifica se a condicao eh verdadeira, e ai vem o laco (sempre vai rodar uma vez)
    do{
        cout << "Do While" << endl;
        cout << "Enter a positive number: ";
        cin >> number;

    }while(number < 0 );
    cout << "2The number is: " << number << endl;

    //Um exemplo de uso do Do While
    //Roda um jogo, e no final, pergunta se o usuario quer jogar novamente e dai repete o jogo

    return 0;
}