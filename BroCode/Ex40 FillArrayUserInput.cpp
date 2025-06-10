#include <iostream>
using namespace std;

int main() {
    int usersize;
    cout << "Quantas comidas: ";
    cin >> usersize;

    string foods[usersize];
    int size = sizeof(foods)/sizeof(foods[0]);
    string temp;

    cin.ignore();
    for(int i = 0; i < size; i++){
        cout << "Enter a food you like or 'q' to quit #" << i + 1 << ": ";
        getline(cin, temp);
        if(temp == "q"){
            break;
        }
        else{
            foods[i] = temp;
        }
    }

    cout << "\nYou like the following food: " << endl;

    for(int i = 0; !foods[i].empty(); i++){
        cout << i + 1 << ". " << foods[i] << endl;
    }
    
    return 0;
}