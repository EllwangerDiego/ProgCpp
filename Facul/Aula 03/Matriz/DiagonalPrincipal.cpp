#include <iostream>
using namespace std;

int main() {
    
    int matriz[5][5] = {
        1,1,2,3,4,
        0,1,2,3,4,
        0,1,1,3,4,
        0,1,2,1,4,
        0,1,2,3,1};

    
        for(int i = 0; i < 5; i++){
            cout << matriz[i][i] << "  ";
            }
    
    return 0;
}
