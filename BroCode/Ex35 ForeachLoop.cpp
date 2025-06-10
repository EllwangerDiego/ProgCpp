#include <iostream>
using namespace std;

// foreach loop = loop that eases the traversal over an
//                iterable data set

int main() {
    
    string students[] = {"Spongebob", "Patrick", "Squidward", "Sandy"};
    int grades[] = {65, 72, 81, 93};
    
    for(string student : students){
        cout << student << endl;
    }
    cout << endl;

    for(int grade : grades){
        cout << grade << endl;
    }

    return 0;
}