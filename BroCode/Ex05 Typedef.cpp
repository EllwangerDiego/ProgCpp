#include <iostream>
#include <vector>
using namespace std;

//Normalmente, usa o _t no final para identificar que eh um typedef
//typedef string text_t;
//typedef int number_t;

//Utilizar o 'using' ao inves do typedef, funciona da mesma maneira, porem melhorado
using text_t = string;
using number_t = int;

int main(){

    text_t first_name = "Diego";
    cout << first_name << endl;

    number_t age = 19;
    cout << age << endl;

    return 0;
}