#include <iostream>
using namespace std;



struct Car{
    string model;
    int year;
    string color;
};

void printCar(Car &car);
void paintCar(Car &car, string color);

int main() {
    
    Car car1;
    Car car2;

    car1.model = "BMW";
    car1.year = 2025;
    car1.color = "Black";

    car2.model = "GTR";
    car2.year = 2018;
    car2.color = "Silver";

    paintCar(car1, "Blue");

    cout << &car1 << endl;
    printCar(car1);
    printCar(car2);

    
    return 0;
}
void printCar(Car &car){
    cout << car.model << endl;
    cout << car.year << endl;
    cout << car.color << endl;
    cout << &car << endl;
}
void paintCar(Car &car, string color){
    car.color = color;
}