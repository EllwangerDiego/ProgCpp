#include <iostream>
using namespace std;


// Loop inside a loop
int main(){

    /*
        loop(){
            loop(){
            
            }
        }

    */

    int rows;
    int columns;
    char symbol;

    cout << "Quantas linhas: ";
    cin >> rows;

    cout << "Quantas colunas: ";
    cin >> columns;

    cout << "Enter a symbol to use: ";
    cin >> symbol;
    cout << endl;

    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            cout << symbol << ' ';
        
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}