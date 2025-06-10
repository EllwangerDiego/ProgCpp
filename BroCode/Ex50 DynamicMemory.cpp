#include <iostream>
using namespace std;

    // dynamic memory = Memory that is allocated after the program
    //                  is already compiled & running.
    //                  Use the 'new' operator to allocate
    //                  memory in the heap rather than the stack

    //                  Useful when we don't know how much memory
    //                  we will need. Makes our programs more flexible,
    //                  especially when accepting user input.

int main() {
    
    char *pGrades = NULL;
    int size;
    cout << "Enter a size: ";
    cin >> size;

    pGrades = new char[size];

    for(int i = 0; i < size ; i++){
        cout << "Enter grade #" << i + 1 << ": ";
        cin >> pGrades[i];
    }

    for(int i = 0; i < size; i++){
        cout << pGrades[i] << " ";
    }

    delete[] pGrades;
    
    
    return 0;
}
