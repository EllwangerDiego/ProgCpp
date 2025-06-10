#include <iostream>
using namespace std;

int main() {

    // cars[linhas][colunas]
    string cars[3][3] = {{"Mustang", "Escaper", "F=150"},
                        {"Covette", "Equinox", "Silverado"},
                        {"Challenger", "Durango", "Ram 1500"}};

    int rows = sizeof(cars)/sizeof(cars[0]);
    int columns = sizeof(cars[0])/sizeof(cars[0][0]);

    cout << endl;

    for(int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout << cars[i][j] << " ";
        }
        cout << endl;
        
    }
    cout << endl;
    
    return 0;
}