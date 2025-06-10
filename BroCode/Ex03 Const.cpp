#include <iostream>
using namespace std;

int main(){

    // The const keyword specifies that a variable's value is constant
    // it tells the compiler to prevent anything from modifying it (read-only)

    const float pi = 3.14159;
    //pi = 15;

    float radius = 10;
    float circumference = 2 * pi * radius;

    cout << "Circunferencia: " << circumference << "cm" << endl;

    return 0;
}