#include <iostream>
using namespace std;

int main(){

    char x = 100;
    //No 100 na tabela ASCII sai como letra 'd'
    cout << x << endl;
    cout << (char) 100 << endl;

    int correct = 8;
    int questions = 10;
    double score = correct/(double)questions * 100;

    cout << score <<"%" << endl;


    return 0;
}