#include <iostream>
#include <windows.h>

using namespace std;

int main(){


    for (int i = 0; i < 3; i++){
        cout << "---" << endl;
        for (int j = 3; j > i; j--){
            cout << "O";
        }
        Sleep(1500);
        cout << endl;
    }
    cout << "---" << endl;
    cout << "GO!" << endl;

    return 0;
}