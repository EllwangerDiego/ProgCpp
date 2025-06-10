#include <iostream>
using namespace std;

int main(){

    int temp;
    bool sunny = false;

    cout << "Enter the temperature: ";
    cin >> temp;

    //AND (e) todas condicoes devem ser verdadeiras
    if(temp > 0 && temp <30){
        cout << "The temperature is good" << endl;
    }
    else{
        cout << "The temperature is bad" << endl;
    }

    //OR (OU), apenas uma dessas condicoes devem ser verdadeiras
    if(temp <= 0 || temp >= 30){
        cout << "2The temperature is bad" << endl;
    }
    else{
        cout << "2The temperature is good" << endl;
    }

    //! = Reverse
    //Pode escrever sunny == true ou entao, apenas sunny, por estar tratando de true ou false
    if(!sunny){
        cout << "It is cloudy outside" << endl;
    }
    else{
        cout << "It is sunny outside" << endl;
    }



    return 0;
}