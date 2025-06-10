#include <iostream>
#include <ctime>
#include <limits>
#include <windows.h>
using namespace std;

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);



int main() {
    char UserChoice;
    char ComputerChoice;

    UserChoice = getUserChoice();
    cout << "Your choice was ";
    showChoice(UserChoice);
    Sleep(1000);

    ComputerChoice = getComputerChoice();
    cout << "Computer choice was ";
    showChoice(ComputerChoice);
    Sleep(1000);

    cout << endl;
    chooseWinner(UserChoice, ComputerChoice);
    Sleep(1000);


    return 0;
}

char getUserChoice(){
        char UserChoice;

    do{
        cout << "*******************" << endl;
        cout << "1. Rock" << endl;
        cout << "2. Paper" << endl;
        cout << "3. Scissor" << endl;
        cout << "*******************" << endl;
        cout << "Enter your choice: ";
        cin >> UserChoice;

        if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        UserChoice = '0'; // força repetir o loop
        }

    }while(UserChoice != '1' && UserChoice != '2' && UserChoice != '3');
    return UserChoice;
}

char getComputerChoice(){
    int ComputerChoice;
    srand(time(NULL));
    ComputerChoice = rand() % 3 + 1;
    
    switch(ComputerChoice){
        case 1:
            return '1';
            
        case 2:
            return '2';

        case 3:
            return '3';
            
        default:
            return 0;

    }

}

void showChoice(char choice){
    
    switch (choice)
    {
    case '1':
        cout << "ROCK! " << endl;
        break;
    case '2':
        cout << "PAPER! " << endl;
        break;
    case '3':
        cout << "SCISSOR! " << endl;
        break;

    default:
        cout << "Error" << endl;
        break;
    }


}

void chooseWinner(char player, char computer){

    if((player == '1' && computer == '3') || (player == '2' && computer == '1') || (player == '3' && computer == '2')){
        cout << "YOU WON!!!!" << endl;
    }
    else if(player == computer){
        cout << "THAT'S A DRAW!" << endl;
    }
    else{
        cout << "YOU LOST :(" << endl;
    }

}
