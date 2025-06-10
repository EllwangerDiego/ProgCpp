#include <iostream>
using namespace std;

// ternary operator ?: = replacement to an if/else statement
// condition ? expression1 : expression2;

int main(){

    
    int grade = 75;
    //                      True       :           False
    grade >=60 ? cout << "You pass!\n" : cout << "You fail!\n";
    

    int number = 9;  
    //                           True        :             False     
    number % 2 == 0 ? cout << "Numero par\n" : cout << "Numero impar\n";


    bool hungry = true;

    hungry ? cout << "You are hungry\n" : cout << "You are full\n";
    //Outra forma de escrever
    cout << (hungry ? "2You are hungry" : "2You are full");

    return 0;
}