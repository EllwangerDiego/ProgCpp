#include <iostream>
#include <ctime>
using namespace std;

int main(){

    srand(time(NULL));

    int randNum = rand() % 6 + 1;
    int guess;
    int index = 1;
    int tries = 3;

    

    do{
        cout << "Digite um numero entre 1 e 6: ";
        cin >> guess;
        tries--;

        if(tries == 0){
            cout << "You are out of tries :(" << endl;
        }
        else if(guess > randNum){
            cout << "Too High " << endl;
        }
        else if(guess < randNum){
            cout << "Too Low " << endl;
        }
        else if(guess == randNum){
            cout << "Voce acertou! " << endl;
            index = 0;
        }
        else if(guess != randNum){
            cout << "Voce errou, tente novamente!\n" << endl;
        }
        else{
            cout << "Error" << endl;
        }
        
    }while(index != 0 && tries != 0);
    cout << "O numero era: " << randNum << endl;

    return 0;
}