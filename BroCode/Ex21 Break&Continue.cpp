#include <iostream>
using namespace std;

// break = break out of a loop
// continue = skip current iteration

int main(){

    for(int i = 1; i <=20; i++){
        // Passa a vez (nao da print no 13)
        if(i == 13){
            continue;
        }
        // Quebra o loop (vai parar quando i for igual a 18)
        else if(i == 18){
            break;
        }
        cout << i << endl;
    }

    return 0;
}