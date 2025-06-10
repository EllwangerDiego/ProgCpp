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
#include <sstream>
#include <string>
using namespace std;

class IPv4 {
private:
    int octetos[4]; // Array para armazenar os 4 octetos do IP

    // Função para validar se um octeto está entre 0 e 255
    bool validarOcteto(int val) {
        return val >= 0 && val <= 255;
    }

    // Função para validar uma string no formato "x.x.x.x"
    // Retorna true se a string for um IP válido, e armazena os octetos
    bool validarStringIP(const string& ip) {
        int nums[4];
        char c;
        stringstream ss(ip);

        // Tenta ler 4 números separados por '.'
        for (int i = 0; i < 4; ++i) {
            if (!(ss >> nums[i])) return false;  // Falha ao ler um número
            if (!validarOcteto(nums[i])) return false; // Número fora do intervalo válido
            if (i < 3) {
                // Espera o caractere '.' entre os números
                if (!(ss >> c) || c != '.') return false;
            }
        }
        // Verifica se não existem caracteres extras após o quarto número
        if (ss >> c) return false;

        // Se passou em todas as validações, armazena os valores nos octetos
        for (int i = 0; i < 4; ++i) {
            octetos[i] = nums[i];
        }
        return true;
    }

public:
    // Construtor padrão: inicializa todos os octetos com 0 (IP 0.0.0.0)
    IPv4() {
        for (int i = 0; i < 4; ++i) octetos[i] = 0;
    }

    // Sobrecarga do construtor que recebe 4 inteiros
    // Armazena os valores se todos forem válidos; senão, inicializa com 0.0.0.0
    IPv4(int o1, int o2, int o3, int o4) {
        if (validarOcteto(o1) && validarOcteto(o2) && validarOcteto(o3) && validarOcteto(o4)) {
            octetos[0] = o1;
            octetos[1] = o2;
            octetos[2] = o3;
            octetos[3] = o4;
        } else {
            cout << "IP inválido passado ao construtor de 4 inteiros. Inicializando com 0.0.0.0\n";
            for (int i = 0; i < 4; ++i) octetos[i] = 0;
        }
    }

    // Sobrecarga do construtor que recebe uma string com o IP
    // Tenta validar e armazenar; se inválido, inicializa com 0.0.0.0
    IPv4(const string& ip) {
        if (!validarStringIP(ip)) {
            cout << "IP inválido passado ao construtor de string. Inicializando com 0.0.0.0\n";
            for (int i = 0; i < 4; ++i) octetos[i] = 0;
        }
    }

    // Getter para um octeto específico (1 a 4)
    // Retorna -1 se a posição for inválida
    int getOcteto(int pos) {
        if (pos >= 1 && pos <= 4) return octetos[pos - 1];
        cout << "Posição inválida para getOcteto: " << pos << endl;
        return -1; // valor inválido para indicar erro
    }

    // Setter para um octeto específico (1 a 4)
    // Só atualiza se o valor for válido (0 a 255)
    void setOcteto(int pos, int val) {
        if (pos < 1 || pos > 4) {
            cout << "Posição inválida para setOcteto: " << pos << endl;
            return;
        }
        if (!validarOcteto(val)) {
            cout << "Valor inválido para octeto: " << val << endl;
            return;
        }
        octetos[pos - 1] = val;
    }

    // Método para retornar o IP como string formatada "x.x.x.x"
    string getIP() {
        stringstream ss;
        ss << octetos[0] << '.' << octetos[1] << '.' << octetos[2] << '.' << octetos[3];
        return ss.str();
    }

    // Destrutor: não faz nada especial aqui, apenas exemplo
    ~IPv4() {
        // cout << "Destrutor chamado para IP " << getIP() << endl;
    }
};

int main() {
    // Instancia usando construtor padrão
    IPv4 ip1;
    cout << "IP1 (padrão): " << ip1.getIP() << endl;

    // Instancia usando construtor com 4 octetos válidos
    IPv4 ip2(192, 168, 0, 1);
    cout << "IP2 (4 octetos válidos): " << ip2.getIP() << endl;

    // Instancia usando construtor com string válida
    IPv4 ip3("10.0.0.255");
    cout << "IP3 (string válida): " << ip3.getIP() << endl;

    // Testes com IP inválido usando construtor com 4 ints
    IPv4 ip4(300, -1, 10, 5);
    cout << "IP4 (4 octetos inválidos): " << ip4.getIP() << endl;

    // Testes com IP inválido usando construtor com string
    IPv4 ip5("256.100.50.25");
    cout << "IP5 (string inválida): " << ip5.getIP() << endl;

    // Teste dos setters: tenta valores válidos e inválidos
    ip1.setOcteto(2, 255); // válido
    ip1.setOcteto(5, 10);  // inválido: posição inválida
    ip1.setOcteto(3, -5);  // inválido: valor fora do intervalo
    cout << "IP1 após setOcteto inválido e válido: " << ip1.getIP() << endl;

    return 0;
}
