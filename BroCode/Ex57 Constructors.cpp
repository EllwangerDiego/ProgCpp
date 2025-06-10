#include <iostream>
using namespace std;

class Student{
    public:
        string name;
        int age;
        double gpa;

    Student(string name, int age, double gpa){
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    }
};

class Car{
    public:
        string make;
        string model;
        int year;
        string color;

    Car(string make, string model, int year, string color){
        this->make = make;
        this->model = model;
        this->year = year;
        this->color = color;
    };
};

int main() {
    
    // constructor = special method that is automatically called when an object is instantiated
    //               usefull for assigning values to attributes as arguments

    // STUDENT CLASS
    Student student1("Spongebob", 25, 3.2);
    Student student2("Patrick", 40, 1.5);

    cout << student1.name << endl;
    cout << student1.age << endl;
    cout << student1.gpa << endl;

    cout << student2.name << endl;
    cout << student2.age << endl;
    cout << student2.gpa << endl;
    cout << endl;
    

    // CAR CLASS
    Car car1("Chevy", "Corvette", 2022, "Blue");
    Car car2("Ford", "Mustang", 2023, "Red");

    cout << car1.make << endl;
    cout << car1.model << endl;
    cout << car1.year << endl;
    cout << car1.color << endl;
    cout << endl;

    cout << car2.make << endl;
    cout << car2.model << endl;
    cout << car2.year << endl;
    cout << car2.color << endl;

    return 0;
}
