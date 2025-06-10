#include <iostream>
using namespace std;

    // object = A collection of atributes and methods
    //          they can have characteristics and could perform actions    
    //          Can be used to mimic real world items (ex. Phone, Book, Dog)
    //          Created from a class which acts as a "blue-print"

// Classe serve como uma blue-print para criar outros objetos, como por exemplo, um Humano chamado Diego
class Human{
    public:
    // Atributos (caracteristicas de um humano nesse caso)
        string name;
        string occupation;
        int age;

    // Metodos, funcoes que pertencem a uma classe (acoes que o objeto pode fazer)
        void eat(){
            cout << "This person is eating" << endl;
        }
        void drink(){
            cout << "This person in drinking" << endl;
        }
        void sleep(){
            cout << "This person is sleeping" << endl;
        }
};

int main() {
    
    Human human1;
    Human human2;

    human1.name = "Rick";
    human1.occupation = "Scientist";
    human1.age = 70;

    human2.name = "Morty";
    human2.occupation = "Student";
    human2.age = 15;

    cout << human1.name << endl;
    cout << human1.occupation << endl;
    cout << human1.age << endl;

    human1.eat();
    human1.drink();
    human1.sleep();
    cout << endl;

    cout << human2.name << endl;
    cout << human2.occupation << endl;
    cout << human2.age << endl;

    human2.eat();
    human2.drink();
    human2.sleep();
    cout << endl;

    
    return 0;
}
