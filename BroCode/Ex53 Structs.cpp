#include <iostream>
using namespace std;

struct student{
    string name;
    double gpa;
    bool enrolled;

};

struct teste{
    string name;
    double gpa;
    bool enrolled = true;
};

int main() {
    
    // struct = A structure group related variables under one name
    //          structs can contain many different data types (string, int, double, bool, etc.)
    //          variables iun a struct are know as "members"
    //          members can be accessed with . "Class Member Acces Operator"
    

    student student1;
    student1.name = "Spongebob";
    student1.gpa = 3.2;
    student1.enrolled = true;

    student student2;
    student2.name = "Patrick";
    student2.gpa = 2.1;
    student2.enrolled = true;

    student student3;
    student3.name = "Squidward";
    student3.gpa = 1.5;
    student3.enrolled = false;

    cout << student1.name << endl;
    cout << student1.gpa << endl;
    cout << student1.enrolled << endl;
    cout << endl;

    cout << student2.name << endl;
    cout << student2.gpa << endl;
    cout << student2.enrolled << endl;
    cout << endl;

    cout << student3.name << endl;
    cout << student3.gpa << endl;
    cout << student3.enrolled << endl;
    cout << endl;



    return 0;
}
