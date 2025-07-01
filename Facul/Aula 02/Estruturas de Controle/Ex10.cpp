/*

Tendo como dados de entrada a altura e o sexo de uma pessoa,
construa um algoritmo que calcule seu peso ideal, utilizando as
seguintes fórmulas:
• Para homens: (72.7*h) - 58 (h = altura)
• Para mulheres: (62.1*h) - 44.7 (h = altura)
• Após calcular o peso ideal para a pessoa, solicite o seu peso e
informe se ela está dentro da faixa ideal (peso +/- 5%), acima ou
abaixo do peso ideal.

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    float altura;
    char sexo;
    float pesoIdeal;
    float media;
    
    cout << "Digite sua altura: ";
    cin >> altura;

    cout << "\nDigite seu sexo (M - F): ";
    cin >> sexo;

    cout << setprecision(2) << fixed;

    if(sexo == 'M' || sexo == 'm'){
        pesoIdeal = (72.7 * altura) - 58;
        cout << "Peso ideal: " << pesoIdeal << endl;
    }
    else if(sexo == 'F' || sexo == 'f'){
        pesoIdeal = (62.1 * altura) - 44.7;
        cout << "Peso ideal: " << pesoIdeal << endl;
    }
    
    media = (0.05 * pesoIdeal);

    float peso;
    cout << "Digite seu peso: ";
    cin >> peso;

    if (peso > pesoIdeal){
        cout << "Voce esta acima do peso ideal" << endl;
    }
    else if(peso < pesoIdeal){
        cout << "Voce esta abaixo do peso ideal" << endl;
    }
    else{
        cout << "Voce esta no peso ideal" << endl;
    }
    
    return 0;
}
