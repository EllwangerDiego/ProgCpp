#include <iostream>
using namespace std;

int main() {
    
    int matriz[5][5] = {
        0,1,2,3,4,
        1,1,1,1,1,
        0,1,2,3,4,
        0,1,2,3,4,
        0,1,2,3,4};
    
        for(int i = 1; i <= 1; i++){
            cout << endl;
            for(int j = 0; j < 5; j++){
                cout << matriz[i][j] << "  ";
            }
        }
    
    return 0;
}
