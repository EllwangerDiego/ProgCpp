#include <iostream>
using namespace std;

int main() {
    
    int matriz[5][5] = {
        0,1,2,3,4,
        0,1,2,3,4,
        0,1,2,3,4,
        0,1,2,3,4,
        0,1,2,3,4};
    
        for(int i = 0; i < 5; i++){
            cout << endl;
            for(int j = 0; j < 5; j++){
                cout << matriz[i][j] << "  ";
            }
        }
    
    return 0;
}
