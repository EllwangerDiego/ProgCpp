#include <iostream>
using namespace std;

int main() {
    
    int matriz[5][5] = {
        0,1,2,3,1,
        0,1,2,1,4,
        0,1,1,3,4,
        0,1,2,3,4,
        1,1,2,3,4};

        int temp = 0;

    
        for(int i = 4; i > 0; i--){
            cout << matriz[temp][i] << "  ";
            temp++;
            }
    
    return 0;
}
