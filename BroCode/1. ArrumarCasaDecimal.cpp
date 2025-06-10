#include <iostream>
//Biblioteca necessaria
#include <iomanip>
using namespace std;

int main() {

    double balance = 10;
    
    cout << "Your balance is: $" << setprecision(2) << fixed << balance << endl;
    
    return 0;
}

