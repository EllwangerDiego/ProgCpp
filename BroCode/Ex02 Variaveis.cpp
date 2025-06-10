#include <iostream>
using namespace std;

int main(){

   //inteiro
   int x = 5;

   //double
   double a = 7.1;

   //float
   //por padrao, sem colocar o "f" no final, os numeros sao tratados como double
   //Maneira correta para usar o float
   float y = 7.1f;
   //Outra maneira incorreta: (tem que incluir o decimal para usar o f no final)
   //float h = 7f;

   //Maneira incorreta, porem funcional ainda
   float z = 7.1;

   //Single character
   //Use single quotes ' to store a single character
   char grade = 'A';
   char initial = 'B';
   //Exemplo de char overflow:
   //char overflow = 'AB';


    // boolean (only 2 states, true or false)
    bool student = true;
    bool pc_power = true;
    bool for_sale = false;

    //string (objects that represent a sequence of text)
    string name = "Diego";
    string day = "Friday";
    string food = "Pizza";

    cout << "Hello " << name << endl;
    


    return 0;
}