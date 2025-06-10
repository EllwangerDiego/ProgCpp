#include <iostream>
using namespace std;

double square(double length);
double cube(double length);
string fullName(string firstName, string lastName);

int main(){

    // return = return a value back to the spot
    //          where you called the encompassing function

    double length = 5.0;
    double area = square(length);
    double volume = cube(length);
    cout << "Area: " << area << " cm2" << endl;
    cout << "Volume: " << volume << " cm3" << endl;


    string firstName = "Diego";
    string lastName = "Ellwanger";
    string Name = fullName(firstName, lastName);
    cout << "Full name: " << Name << endl;

    

    return 0;
}

double square(double length){
    double result = length * length;
    //Funcao deve retornar o mesmo tipo de valor, entao nesse caso double
    return result;
}

double cube(double length){
    return length * length *length;
    //Funcao deve retornar o mesmo tipo de valor, entao nesse caso double
}
//Concatenar o primeiro e ultimo nome
string fullName(string firstName, string lastName){
    return firstName + ' ' + lastName;
}