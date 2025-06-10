#include <iostream>
#include <ctime>
using namespace std;

int main(){

    srand(time(0));

    int randNum = (rand() % 5) + 1;

    switch (randNum){
        case 1:
            cout << "Numero 1" << endl;
            break;
        case 2:
            cout << "Numero 2" << endl;
            break;
        case 3:
            cout << "Numero 3" << endl;
            break;
        case 4:
            cout << "Numero 4" << endl;
            break;
        case 5:
            cout << "Numero 5" << endl;
            break;
        default:
            cout << "Error" << endl;
    }


    //Se quiser fazer com que ganhe todos, depois de um dos casos:
    //Tire o break
    switch (randNum){
        case 1:
            cout << "2Numero 1" << endl;
            
        case 2:
            cout << "2Numero 2" << endl;
            
        case 3:
            cout << "3Numero 3" << endl;
            
        case 4:
            cout << "4Numero 4" << endl;
            
        case 5:
            cout << "5Numero 5" << endl;
            

    }

    return 0;
}