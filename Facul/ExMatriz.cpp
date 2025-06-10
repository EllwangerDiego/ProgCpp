#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    int i, j;
    int B[2][10] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 10; j++) {
            //B[i][j] = i * 10 + j;
            cout << B[i][j] << "\t";
            Sleep(500);
        }
        cout << endl;
    }

    return 0;
}
