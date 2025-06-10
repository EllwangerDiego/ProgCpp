#include <iostream>
using namespace std;

int main() {
    


    string students[] = {"Spongebob", "Patrick", "Squidward", "Sandy"};
    cout << endl;
    int j = sizeof(students)/sizeof(string); // Calcula quantos elementos tem no array

    //Vai dar loop pelo array, para todos os seus elementos
    for(int i = 0; i < j; i++){
        cout << students[i] << endl;
    }

    return 0;
}