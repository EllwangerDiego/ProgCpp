/*

Crie uma classe que representa um endereço IPv4, tendo como
atributos privados, os 4 octetos inteiros na faixa entre 0 e 255
– Implemente os métodos de acesso Getter e Setter, com as validações e
mensagens necessárias
– O construtor padrão deve inicializar os 4 octetos com o valor 0
– Uma sobrecarga do construtor deve receber como parâmetro os 4 octetos
numéricos e armazená-los apenas se forem válidos
– Outra sobrecarga do construtor deve receber como parâmetro uma string
contendo o endereço IP. Avalie o IP informado e o armazene apenas se for
válido
– Método getIP(), que retorna uma string representando o IP com seus 4 octetos
– No main, instancie 3 objetos IP usando os 3 construtores e os visualize usando
o método getIP()
– Faça testes com IPs inválidos

*/
#include <iostream>
using namespace std;

class ip
{
private:
    int a;
    int b;
    int c;
    int d;

public:
    ip()
    {
        this->a = 0;
        this->b = 0;
        this->c = 0;
        this->d = 0;
    }
    ip(int a, int b, int c, int d)
    {
        setA(a);
        setB(b);
        setC(c);
        setD(d);
    }
    ip(string endereco)
    {
        // Avalie o IP informado e o armazene apenas se for válido
        int a, b, c, d;

        size_t p1 = endereco.find('.');
        size_t p2 = endereco.find('.', p1 + 1);
        size_t p3 = endereco.find('.', p2 + 1);

        if (p1 == string::npos || p2 == string::npos || p3 == string::npos)
        {
            setA(0);
            setB(0);
            setC(0);
            setD(0);
            return;
        }

        try
        {
            a = stoi(endereco.substr(0, p1));
            b = stoi(endereco.substr(p1 + 1, p2 - p1 - 1));
            c = stoi(endereco.substr(p2 + 1, p3 - p2 - 1));
            d = stoi(endereco.substr(p3 + 1));
        }
        catch (...)
        {
            setA(0);
            setB(0);
            setC(0);
            setD(0);
            return;
        }

        if (a >= 0 && a <= 255 && b >= 0 && b <= 255 &&
            c >= 0 && c <= 255 && d >= 0 && d <= 255)
        {
            setA(a);
            setB(b);
            setC(c);
            setD(d);
        }
        else
        {
            setA(0);
            setB(0);
            setC(0);
            setD(0);
        }
    }
    int getA()
    {
        return this->a;
    }
    int getB()
    {
        return this->b;
    }
    int getC()
    {
        return this->c;
    }
    int getD()
    {
        return this->d;
    }

    void setA(int a)
    {
        if (a >= 0 && a <= 255)
        {
            this->a = a;
        }
    }
    void setB(int b)
    {
        if (b >= 0 && b <= 255)
        {
            this->b = b;
        }
    }
    void setC(int c)
    {
        if (c >= 0 && c <= 255)
        {
            this->c = c;
        }
    }
    void setD(int d)
    {
        if (d >= 0 && d <= 255)
        {
            this->d = d;
        }
    }

    string getIP()
    {
        string endereco = to_string(this->a) + "." + to_string(this->b) + "." + to_string(this->c) + "." + to_string(this->d);
        return endereco;
    }
};

int main()
{
    int a, b, c, d;
    char ponto = '.';
    string endereco = "192.168.1.108";

    cout << "Digite o endereco ip (x.x.x.x): ";
    cin >> a >> ponto >> b >> ponto >> c >> ponto >> d;

    ip x = ip(a, b, c, d);
    ip y = ip();
    ip z = ip(endereco);

    cout << "\n4 parametros: " << x.getIP();
    cout << "\n0 parametros: " << y.getIP();
    cout << "\nstring: " << z.getIP();

    return 0;
}
