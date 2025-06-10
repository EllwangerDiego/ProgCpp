#include <iostream>
using namespace std;

    // sizeof() = determines the size in bytes of a:
    //            variable, data type, class, objects, etc.

int main() {
    
    double gpa = 2.5;
    string name = "Diego";
    char grade = 'F';
    bool student = true;
    char grades[] = {'A', 'B', 'C', 'D', 'F'};
    string students[] = {"Spongebob", "Patrick", "Squidward", "Sandy"};

    cout << "Data type sizes: \n" << endl;
    cout << "double: " << sizeof(gpa) << " bytes" << endl;
    //cout << "double: " << sizeof(double) << " bytes" << endl;
    cout << "string: " << sizeof(name) << " bytes" << endl;
    cout << "char: " << sizeof(grade) << " bytes" << endl;
    cout << "bool: " << sizeof(student) << " bytes" << endl;
    cout << "grades array (5 characters): " << sizeof(grades) << " bytes" << endl; // 1 byte per character
    cout << "string students array: " << sizeof(students) << " bytes" << endl;
    cout << "string students array: " << sizeof(students)/sizeof(string) << " elements" << endl; // 128 bytes / 32 bytes = 4 elements
    cout << "string size: " << sizeof(string) << " bytes" << endl;
    
    return 0;
}