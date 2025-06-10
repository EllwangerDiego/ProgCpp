#include <iostream>
using namespace std;

int main(){

    double temp;
    char unit;

    cout << "*****TEMPERATURE CONVERSION*****" << endl;
    cout << "F = Fahrenheit" << endl;
    cout << "C = Celsius" << endl;
    cout << "********************************" << endl;
    cout << "What unit do you want to convert to? ";
    cin >> unit;

    if(unit == 'F' || unit == 'f'){
        cout << "Type the temperature in Celsius: ";
        cin >> temp;

        temp = (1.8 *temp) + 32;   
        cout << "The temperature is " << temp << "F" << endl;
    }
    else if(unit == 'C' || unit == 'c'){
        cout << "Type the temperature in Fahrenheit: ";
        cin >> temp;

        temp = ((temp - 32) / 1.8);
        cout << "The temperature is " << temp << "C" << endl;

    }
    else{
        cout << "Please enter only C or F" << endl;
    }


    return 0;
}