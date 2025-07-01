/*

Faça um procedimento chamado “raizes”, que recebe 3 parâmetros
e calcule as raízes conforme a fórmula de Baskara. A partir do
“main”, deverá imprimir na tela as raízes calculadas, ou informar
que não existem raízes. Utilizar a função “ehPositivo” para verificar
se o delta da fórmula de Baskara é positivo;

*/

#include <iostream>
#include <cmath>
using namespace std;

bool ehPositivo(float x);

int main()
{

    float a;
    float b;
    float c;

    cout << "Digite o primeiro numero (a): ";
    cin >> a;

    cout << "\nDigite o segundo numero (b): ";
    cin >> b;

    cout << "\nDigite o terceiro numero (c): ";
    cin >> c;

    float delta = (b * b) - (4 * a * c);

    if (ehPositivo(delta))
    {
        float raiz1 = (-b + sqrt(delta)) / (2 * a);
        float raiz2 = (-b - sqrt(delta)) / (2 * a);
        // Imprimir ou retornar raízes
    }
    else if (delta == 0)
    {
        float raiz = -b / (2 * a);
        // Imprimir ou retornar raiz única
    }
    else
    {
        cout << "não existem raízes reais" << endl;
    }

    return 0;
}

bool ehPositivo(float x)
{
    if (x >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

float raizes(int a, int b, int c)
{
}