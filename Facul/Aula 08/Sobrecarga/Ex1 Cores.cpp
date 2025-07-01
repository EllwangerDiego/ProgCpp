/*

Crie a classe “Cor” com as seguintes definições:
– Atributos R, G e B, que aceitam números inteiros entre 0 e 255
– Métodos de acesso Getter e Setter dos atributos, gerando mensagem de
valores fora da faixa
– Método construtor padrão, inicializando os atributos com o valor 0
– Método construtor sobrecarregado, que recebe e armazena os 3 atributos
aplicando as restrições
– Método getCorHex(), que retorna uma string no formato RGB hexadecimal
(#RRGGBB)
– Para testar a classe, instancie um objeto “Cor”, defina valores para os
atributos e imprima na tela o código hexadecimal da cor
– Faça testes com cores inválidas

*/

#include <iostream>
#include <vector>
using namespace std;

class Cor
{
private:
    int R, G, B;

public:
    Cor()
    {
        this->R = 0;
        this->G = 0;
        this->B = 0;
    }

    Cor(int R = 0, int G = 0, int B = 0)
    {
        setR(R);
        setG(G);
        setB(B);
    }

    int getR()
    {
        return this->R;
    }
    int getG()
    {
        return this->G;
    }
    int getB()
    {
        return this->B;
    }

    void setR(int R)
    {
        if (R >= 0 && R <= 255)
        {
            this->R = R;
        }
    }

    void setG(int G)
    {
        if (G >= 0 && G <= 255)
        {
            this->G = G;
        }
    }

    void setB(int B)
    {
        if (B >= 0 && B <= 255)
        {
            this->B = B;
        }
    }

    string intToHex(int value)
    {
        char hexDigits[] = "0123456789ABCDEF";
        string hex = "";
        hex += hexDigits[value / 16];
        hex += hexDigits[value % 16];
        return hex;
    }

    string getCorHex()
    {
        return "#" + intToHex(this->R) + intToHex(this->G) + intToHex(this->B);
    }
};

int main() {
    vector<Cor*> cores; // Vetor de ponteiros

    while (true) {
        int R, G, B;
        cout << "\nDigite R (ou -1 para sair): ";
        cin >> R;
        if (R == -1)
            break;

        cout << "Digite G: ";
        cin >> G;
        cout << "Digite B: ";
        cin >> B;

        Cor* novaCor = new Cor(R, G, B); // Alocação dinâmica
        cores.push_back(novaCor);        // Armazenando no vector

        cout << "Hex: " << novaCor->getCorHex() << endl;
    }

    // Exibindo todas as cores salvas
    cout << "\nCores armazenadas:\n";
    for (Cor* c : cores) {
        cout << c->getCorHex() << endl;
    }

    // Limpando memória alocada
    for (Cor* c : cores) {
        delete c; // libera a memoria de cada objeto
    }
    cores.clear(); // limpa o vector

    return 0;
}
