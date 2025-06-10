#include <iostream>
using namespace std;

int main() {
    const int n = 3;
    int mat[n][n] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Diagonal principal: ";
    for (int i = 0; i < n; i++) {
        cout << mat[i][i] << " ";
    }
    cout << endl;
    
    return 0;
}
