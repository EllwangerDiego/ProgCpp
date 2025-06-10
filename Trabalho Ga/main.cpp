//Diego Ellwanger

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

//CARACTERES PERMITIDOS
const string alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 .";
const int tamanho_alfabeto = alfabeto.length();

//VARIAVEL GLOBAL PARA A CHAVE
string chave_global = "";

//MATRIZ DE VIGENERE
char matriz[66][66];

//DECLARACOES DAS FUNCOES
void mostrar_alfabeto();
void solicitar_chave();
void cifrar_texto(char matriz[66][66], const string& chave);
void decifrar_texto();
bool chave_valida(const string& chave);
void matriz_alfabeto(char matriz[66][66]);

int main() {
    matriz_alfabeto(matriz); //Preenche a matriz
    int opcao;

    while (true) {
        cout << "\nMENU VIGENERE\n";
        cout << "1 - Mostrar alfabeto\n";
        cout << "2 - Solicitar chave\n";
        cout << "3 - Cifrar\n";
        cout << "4 - Decifrar\n";
        cout << "5 - Sair\n";
        cout << "Escolha uma opção: ";

        cin >> opcao;

        //validacao do cin, caso nao seja valida a opcao, ele repete a acao
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada inválida! Por favor, digite um número entre 1 e 5.\n";
            continue;
        }

        switch (opcao) {
            case 1:
                mostrar_alfabeto();
                break;
            case 2:
                solicitar_chave();
                break;
            case 3:
                //verifica se foi informado uma chave
                if (!chave_global.empty()) {
                    cifrar_texto(matriz, chave_global);
                } else {
                //se nao tiver sido informada a chave, ele chama a funcao solicitar_chave()
                    cout << "Primeiro digite uma chave para poder cifrar.\n";
                    solicitar_chave();
                }
                break;

            case 4:
                decifrar_texto();
                break;
            case 5:
                cout << "Saindo do programa..." << endl;
                Sleep(1000);
                return 0;
            default:
                cout << "Opção inválida! Escolha um número entre 1 e 5.\n";
        }
    }

    return 0;
}

void mostrar_alfabeto() {
    cout << "Alfabeto permitido: " << alfabeto << endl;
    Sleep(1500);
}

void solicitar_chave() {
    string chave;
    cout << "Digite a chave (mínimo 4 caracteres, apenas caracteres válidos): ";
    cin.ignore();
    getline(cin, chave);

    //verifica se a chave eh maior que 4
    if (chave.length() < 4) {
        cout << "Chave muito curta! Tente novamente.\n";
        return;
    }

    //verifica se so tem caracteres validos
    if (!chave_valida(chave)) {
        cout << "A chave contém caracteres inválidos! Tente novamente.\n";
        return;
    }

    chave_global = chave;
    cout << "Chave armazenada com sucesso!\n";
    Sleep(1500);
}

//funcao para conferir se a chave eh valida dentro do alfabeto passado
bool chave_valida(const string& chave) {
    for (char c : chave) {
        if (alfabeto.find(c) == string::npos) {
            return false;
        }
    }
    return true;
}

//funcao para cifrar o texto
void cifrar_texto(char matriz[66][66], const string& chave) {
    string texto;
    cout << "Digite o texto a ser cifrado (mínimo 8 caracteres): ";
    cin.ignore();
    getline(cin, texto);

    //verifica se o texto eh maior que 8 caracteres
    if (texto.length() < 8) {
        cout << "Texto muito curto!" << endl;
        return;
    }

    //verifica se possui caracter invalido
    for (char c : texto) {
        if (alfabeto.find(c) == string::npos) {
            cout << "Texto contém caractere inválido!" << endl;
            return;
        }
    }

    //cria uma string vazia, que vai guardar o texto cifrado
    string resultado = "";
    //variavel para controlar qual caractere da chave sera usado no momento de cifrar
    int chave_index = 0;

    //for para percorrer cada caractere do texto original
    for (int i = 0; i < texto.length(); i++) {
        //garante que mesmo que o texto seja maior que a chave, ela recomece
        //busca a linha da matriz
        int linha = alfabeto.find(chave[chave_index % chave.length()]);
        //busca a coluna da matriz
        int coluna = alfabeto.find(texto[i]);
        //como a cifra de vigenere utiliza a tecnica de substituicao, ele pega a linha (chave) e coluna (texto) e
        // substitui com o caractere correspondete, que adiciona ao resultado final (resultado).
        resultado += matriz[linha][coluna];
        //ao usar um caractere da chave, eh avancado para o proximo
        chave_index++;
    }

    cout << "Texto cifrado: " << resultado << endl;
}

void decifrar_texto() {
    //verifica se a chave foi informada
    if (chave_global.empty()) {
        cout << "Primeiro digite uma chave para poder decifrar." << endl;
        solicitar_chave();
        if (chave_global.empty()) return;
    }

    //solicita ao usuario o texto que deseja cifrar
    string texto_cifrado;
    cout << "Digite o texto cifrado (mínimo 8 caracteres): ";
    cin.ignore();
    getline(cin, texto_cifrado);

    //verifica se o texto eh maior que 8 caracteres
    if (texto_cifrado.length() < 8) {
        cout << "Texto muito curto!" << endl;
        return;
    }

    //verifica se todos os caracteres do texto estao no alfabeto permitido
    for (char c : texto_cifrado) {
        if (alfabeto.find(c) == string::npos) {
            cout << "Texto contém caractere inválido!" << endl;
            return;
        }
    }

    //string vazia para armazenar o texto decifrado
    string resultado = "";
    int chave_index = 0;

    //laco para percorrer cada caractere do texto cifrado
    for (int i = 0; i < texto_cifrado.length(); i++) {
        //faz o calcuo de qual linha da matriz sera usada
        //pega a letra da chave e transforma no numero da linha da matriz
        int linha = alfabeto.find(chave_global[chave_index % chave_global.length()]);

        //faz o processo reverso da cifragem
        //procurar em qual coluna esta o caractere cifrado na linha da chave
        //a coluna diz qual era a letra original no alfabeto
        for (int j = 0; j < tamanho_alfabeto; j++) {
            if (matriz[linha][j] == texto_cifrado[i]) {
                resultado += alfabeto[j]; //pega o caractere original
                break;
            }
        }

        chave_index++;
    }

    cout << "Texto decifrado: " << resultado << endl;
}

//funcao que monta a matriz de vigenere
void matriz_alfabeto(char matriz[66][66]) {
    for (int i = 0; i < tamanho_alfabeto; i++) {
        for (int j = 0; j < tamanho_alfabeto; j++) {
            matriz[i][j] = alfabeto[(i + j) % tamanho_alfabeto];
        }
    }
}
