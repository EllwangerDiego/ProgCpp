#include <iostream>
using namespace std;

//Variavel global (fora das funcoes no inicio)
int myNum = 1;

void printNum(int myNum);

int main() {
    
    cout << "Print variavel global dentro da main: " << myNum << endl;
    //Variavel local do main
    int myNum = 2;
    printNum(myNum);
    cout << "Print variavel local do main: " << myNum << endl;
    
    
    return 0;
}
void printNum(int myNum){
    //Variavel local da funcao
    myNum = 3;
    cout << "Print variavel local da funcao: " <<myNum << endl;
}