/*

Modifique o exercício anterior para varrer o vector e mostrar o menor
número, o maior número e a média aritmética;

*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int num;
    vector<int> meuvetor;



    do{
        cout << "Digite um numero inteiro: ";
        cin >> num;
        if(num != 0){
            meuvetor.push_back(num);
        }
        else{
            break;
        }
    

    }while(num != 0);

    vector<int>::iterator it;
    for (it = meuvetor.begin(); it != meuvetor.end(); it++){
        if(*it != 0){ // ignora o 0
           cout << *it << ' '; 
           
        }
        
    }
    int menor = meuvetor[0];
    int maior = meuvetor[0];
    int soma = 0;
    int cont = 0;

    for(it = meuvetor.begin(); it != meuvetor.end(); it++){
        if(*it < menor){
            menor = *it;
        }
        if(*it > maior){
            maior = *it;
        }
        soma += *it;
        cont++;
    }

    float media = soma / (float)cont;

    cout << setprecision(2) << fixed;
    cout << "\nMenor: " << menor << endl;
    cout << "Maior : " << maior << endl;
    cout << "Media: " << media << endl;

    
    return 0;
}
