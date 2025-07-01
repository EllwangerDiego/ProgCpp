// Diego Ellwanger

#include <iostream>
#include <sstream>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cctype>
#include <algorithm>

using namespace std;

// struct para guardar informacoes de filtros do usuario
struct Filtro
{
    string campo;
    string valor1;
    string valor2;
    bool isIntervalo = false;
    bool isNumerico = false;
};

class Registro
{
private:
    string dataHora; // (YYYY-MM-DD hh:mm:ss)
    string codigo;
    string mensagem;
    string classificacao;
    int prioridade;
    string protocolo;
    string origemIP;
    int origemPorta;
    string destinoIP;
    int destinoPorta;

    // Converte o nome do mes para numero para montar o (YYYY-MM-DD)
    string mesParaNumero(const string &mes)
    {
        const vector<string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                      "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        for (int i = 0; i < (int)meses.size(); i++)
        {
            if (mes == meses[i])
                return (i < 9 ? "0" : "") + to_string(i + 1);
        }
        return "00"; // erro
    }

    // verifica se a string recebida eh um numero
    // campos podem vir vazios ou texto invalido
    // melhor o programa conferir antes de converter
    bool ehNumero(const string &s)
    {
        if (s.empty())
            return false;
        for (char c : s)
        {
            if (!isdigit((unsigned char)c))
                return false;
        }
        return true;
    }

    // Converte uma string numerica para numero inteiro para trabalhar em cima de int e nao de string
    int stringParaInt(const string &s)
    {
        int resultado = 0;
        for (char c : s)
        {
            resultado = resultado * 10 + (c - '0');
        }
        return resultado;
    }

public:
    // Construtor da classe
    Registro(string linha)
{
    istringstream iss(linha);
    string mes, dia, hora;
    string prioridadeStr, origemPortaStr, destinoPortaStr;

    // le mes, dia e hora, primeiras 3 colunas do log
    getline(iss, mes, '\t');
    getline(iss, dia, '\t');
    getline(iss, hora, '\t');

    // Montar dataHora com ano atual:
    time_t t = time(nullptr);
    tm *now = localtime(&t);
    int ano = now->tm_year + 1900;

    // Converte o nome do mes para numero
    string mesNum = mesParaNumero(mes);
    // Adiciona zero a esquerda do dia ex: (7 vira 07)
    if (dia.size() == 1)
        dia = "0" + dia;
        //Monta a string dataHora
    dataHora = to_string(ano) + "-" + mesNum + "-" + dia + " " + hora;

    //Le os campos restantes do log
    getline(iss, codigo, '\t');
    getline(iss, mensagem, '\t');
    getline(iss, classificacao, '\t');

    // Le o restante dos campos e se necessario, converte para numero ou converte para string
    getline(iss, prioridadeStr, '\t');
    prioridade = ehNumero(prioridadeStr) ? stringParaInt(prioridadeStr) : 0;

    getline(iss, protocolo, '\t');
    getline(iss, origemIP, '\t');

    getline(iss, origemPortaStr, '\t');
    origemPorta = ehNumero(origemPortaStr) ? stringParaInt(origemPortaStr) : 0;

    getline(iss, destinoIP, '\t');

    getline(iss, destinoPortaStr, '\t');
    destinoPorta = ehNumero(destinoPortaStr) ? stringParaInt(destinoPortaStr) : 0;
}

    //Imprime um registro formatado para ler melhor
    void mostrar()
    {
        //setw() da biblioteca iomanip, define a largura que a informacao vai ocupar
        //left faz com que fique alinhado a esquerda
        cout << left << setw(20) << dataHora
             << setw(12) << codigo
             << setw(30) << (mensagem.length() > 30 ? mensagem.substr(0, 27) + "..." : mensagem)
             << setw(20) << classificacao
             << setw(10) << prioridade
             << setw(10) << protocolo
             << setw(18) << origemIP
             << setw(8) << origemPorta
             << setw(18) << destinoIP
             << setw(8) << destinoPorta
             << endl;
    }

    //Metodo que transforma os dados do registro em uma unica linha de texto (stringstream) para salvar no arquivo
    //utilizado na funcao de exportar dados, para salvar em um arquivo de texto
    string toExportString()
    {
        ostringstream oss;
        oss << dataHora << "\t" << codigo << "\t" << mensagem << "\t" << classificacao << "\t"
            << prioridade << "\t" << protocolo << "\t" << origemIP << "\t"
            << origemPorta << "\t" << destinoIP << "\t" << destinoPorta;
        return oss.str();
    }

    // Getters para ler
    string getDataHora() { return dataHora; }
    string getCodigo() { return codigo; }
    string getMensagem() { return mensagem; }
    int getPrioridade() { return prioridade; }
    string getProtocolo() { return protocolo; }
    string getOrigemIP() { return origemIP; }
    int getOrigemPorta() { return origemPorta; }
    string getDestinoIP() { return destinoIP; }
    int getDestinoPorta() { return destinoPorta; }
    string getClassificacao() { return classificacao; }
};

class Sistema
{
private:
    vector<Registro *> logs; // Vector que guarda todos os registros lidos do arquivo
    vector<Filtro> filtros; // Vector que guarda os filtros ativos

    // Funcao que verifica se um registro atende aos registros aplicados
    bool atendeFiltros(Registro *reg)
    {
        // Verifica cada filtro que esta no vector de filtros
        for (const auto &filtro : filtros)
        {
            // para comparação case insensitive, convertendo para minusculo
            auto minusculo = [](const string &s)
            {
                string res = s;
                transform(res.begin(), res.end(), res.begin(), ::tolower);
                return res;
            };

            // Filtros que fazem as comparacoes, ex: (data e hora, codigo, mensagem, prioridade etc.)
            if (filtro.campo == "dataHora")
            {
                string valor = reg->getDataHora();
                if (valor < filtro.valor1 || valor > filtro.valor2)
                    return false;
            }
            else if (filtro.campo == "codigo")
            {
                string cod = minusculo(reg->getCodigo());
                string val = minusculo(filtro.valor1);
                if (cod.find(val) == string::npos)
                    return false;
            }
            else if (filtro.campo == "mensagem")
            {
                string msg = minusculo(reg->getMensagem());
                string val = minusculo(filtro.valor1);
                if (msg.find(val) == string::npos)
                    return false;
            }
            else if (filtro.campo == "classificacao")
            {
                string cls = minusculo(reg->getClassificacao());
                string val = minusculo(filtro.valor1);
                if (cls.find(val) == string::npos)
                    return false;
            }
            else if (filtro.campo == "prioridade")
            {
                int valor = reg->getPrioridade();
                int v1 = stoi(filtro.valor1);
                if (filtro.isIntervalo)
                {
                    int v2 = stoi(filtro.valor2);
                    if (valor < v1 || valor > v2)
                        return false;
                }
                else
                {
                    if (valor != v1)
                        return false;
                }
            }
            else if (filtro.campo == "protocolo")
            {
                string p = minusculo(reg->getProtocolo());
                string val = minusculo(filtro.valor1);
                if (p.find(val) == string::npos)
                    return false;
            }
            else if (filtro.campo == "origemIP")
            {
                string ip = minusculo(reg->getOrigemIP());
                string val = minusculo(filtro.valor1);
                if (ip.find(val) == string::npos)
                    return false;
            }
            else if (filtro.campo == "origemPorta")
            {
                int valor = reg->getOrigemPorta();
                int v1 = stoi(filtro.valor1);
                if (filtro.isIntervalo)
                {
                    int v2 = stoi(filtro.valor2);
                    if (valor < v1 || valor > v2)
                        return false;
                }
                else
                {
                    if (valor != v1)
                        return false;
                }
            }
            else if (filtro.campo == "destinoIP")
            {
                string ip = minusculo(reg->getDestinoIP());
                string val = minusculo(filtro.valor1);
                if (ip.find(val) == string::npos)
                    return false;
            }
            else if (filtro.campo == "destinoPorta")
            {
                int valor = reg->getDestinoPorta();
                int v1 = stoi(filtro.valor1);
                if (filtro.isIntervalo)
                {
                    int v2 = stoi(filtro.valor2);
                    if (valor < v1 || valor > v2)
                        return false;
                }
                else
                {
                    if (valor != v1)
                        return false;
                }
            }
        }
        return true; // passou por todos os filtros, entao siginifica que o registro eh valido, recebe true
    }

public:
    //Construtor da classe
    //Recebe o nome do arquivo e carrega todos os registros na memoria
    Sistema(const string &nomeArquivo)
    {
        ifstream arquivo(nomeArquivo);
        if (!arquivo.is_open())
        {
            cout << "Erro ao abrir arquivo: " << nomeArquivo << endl;
            return;
        }

        string linha;
        getline(arquivo, linha); // Pular cabecalho

        while (getline(arquivo, linha))
        {
            if (linha.empty())
                continue;

            Registro *reg = new Registro(linha); // Cria um novo objeto Registro com os dados da linha
            logs.push_back(reg); // Adiciona o registro no vector de logs
        }

        arquivo.close(); // Fecha o arquivo
    }

    // teste
    void mostrarPrimeiros(int n)
    {
        int limite = (n < (int)logs.size()) ? n : (int)logs.size();
        for (int i = 0; i < limite; i++)
        {
            cout << "Registro #" << i + 1 << ":" << endl;
            logs[i]->mostrar();
            cout << "-------------------------" << endl;
        }
    }
        

    void adicionarFiltro()
    {
        Filtro novoFiltro; // Cria um novo filtro vazio

        cout << "\nEscolha o campo para filtrar:" << endl;
        cout << "1 - Data/Hora" << endl;
        cout << "2 - Codigo" << endl;
        cout << "3 - Mensagem" << endl;
        cout << "4 - Classificacao" << endl;
        cout << "5 - Prioridade" << endl;
        cout << "6 - Protocolo" << endl;
        cout << "7 - Origem IP" << endl;
        cout << "8 - Origem Porta" << endl;
        cout << "9 - Destino IP" << endl;
        cout << "10 - Destino Porta" << endl;
        cout << "\nDigite a opcao: ";

        int campo;
        cin >> campo;
        cin.ignore();

        // switch case com a opcao do usuario
        switch (campo)
        {
        case 1:
            novoFiltro.campo = "dataHora";
            novoFiltro.isIntervalo = true;
            novoFiltro.isNumerico = false;
            cout << "Digite a data/hora inicial (YYYY-MM-DD hh:mm:ss): ";
            getline(cin, novoFiltro.valor1);
            cout << "Digite a data/hora final (YYYY-MM-DD hh:mm:ss): ";
            getline(cin, novoFiltro.valor2);
            break;
        case 2:
            novoFiltro.campo = "codigo";
            break;
        case 3:
            novoFiltro.campo = "mensagem";
            break;
        case 4:
            novoFiltro.campo = "classificacao";
            break;
        case 5:
            novoFiltro.campo = "prioridade";
            novoFiltro.isNumerico = true;
            break;
        case 6:
            novoFiltro.campo = "protocolo";
            break;
        case 7:
            novoFiltro.campo = "origemIP";
            break;
        case 8:
            novoFiltro.campo = "origemPorta";
            novoFiltro.isNumerico = true;
            break;
        case 9:
            novoFiltro.campo = "destinoIP";
            break;
        case 10:
            novoFiltro.campo = "destinoPorta";
            novoFiltro.isNumerico = true;
            break;
        default:
            cout << "Opcao invalida!" << endl;
            return;
        }

        if ((campo >= 2 && campo <= 4) || campo == 6 || campo == 7 || campo == 9)
        {
            cout << "Digite o valor para filtro (substring, case-insensitive): ";
            getline(cin, novoFiltro.valor1);
            novoFiltro.isIntervalo = false;
            novoFiltro.isNumerico = false;
        }

        if (novoFiltro.isNumerico && campo != 1)
        {
            cout << "Digite 1 para filtrar por valor exato ou 2 para intervalo: ";
            int tipo;
            cin >> tipo;
            cin.ignore();

            if (tipo == 1) // Filtro por valor exato
            {
                cout << "Digite o valor exato: ";
                getline(cin, novoFiltro.valor1);
                novoFiltro.isIntervalo = false;
            }
            else if (tipo == 2) // filtro por intervalo de valorers
            {
                cout << "Digite o valor inicial: ";
                getline(cin, novoFiltro.valor1);
                cout << "Digite o valor final: ";
                getline(cin, novoFiltro.valor2);
                novoFiltro.isIntervalo = true;
            }
            else
            {
                cout << "Tipo de filtro invalido." << endl;
                return;
            }
        }

        filtros.push_back(novoFiltro); // Adiciona o filtro no vector de filtros
        cout << "Filtro adicionado com sucesso!" << endl;
    }

    // mostra os filtros ativos
    void visualizarFiltros()
    {
        cout << "\n=== Filtros Ativos ===" << endl;
        // se estiver vazio, fala que nao tem filtro
        if (filtros.empty())
        {
            cout << "Nenhum filtro ativo." << endl;
            return;
        }

        // percorre os filtros e mostra os dados deles
        for (size_t i = 0; i < filtros.size(); i++)
        {
            cout << "Filtro #" << i + 1 << ": Campo = " << filtros[i].campo
                 << ", Valor1 = " << filtros[i].valor1;

                // verifica se o filtro eh um intervalo e mostra o segundo valor
            if (filtros[i].isIntervalo)
                cout << ", Valor2 = " << filtros[i].valor2;

            cout << endl;
        }
    }

    // Limpa os filtros ativos
    void limparFiltros()
    {
        filtros.clear(); // apaga todos os filtros do vector
        cout << "Todos os filtros foram removidos." << endl;
    }

    //Mostra na tela os registros apos verificar os filtros
    void visualizarDados()
    {
        int contador = 0; // variavel que conta quantos filtros foram exibidos
        //percorre todos os registros armazenados no vector logs
        for (auto reg : logs)
        {
            //Verifica se o registro atende aos filtros ativos
            if (atendeFiltros(reg))
            {
                cout << "Registro #" << contador + 1 << ":" << endl;
                reg->mostrar(); // mostra os dados do registro
                cout << "---------------------------" << endl;
                contador++;
            }
        }
        //Avisa se nenhum foi exibido
        if (contador == 0)
            cout << "Nenhum registro encontrado com os filtros atuais." << endl;

        cout << "\nTotal de registros exibidos: " << contador << endl;
        //mostra os filtros que foram usados na busca
        visualizarFiltros();
    }

    // funcao que exporta os registros filtrados para um arquivo de texto
    void exportarDados()
{
    cout << "Digite o nome do arquivo para salvar os registros filtrados: ";
    string nomeArquivo;
    getline(cin, nomeArquivo);

    ofstream arquivoSaida(nomeArquivo); // abre o arquivo para escrita
    if (!arquivoSaida.is_open())
    {
        cout << "Erro ao abrir o arquivo para escrita." << endl;
        return;
    }

    // Cabecalho
    arquivoSaida << "DataHora\tCodigo\tMensagem\tClassificacao\tPrioridade\tProtocolo\tOrigemIP\tOrigemPorta\tDestinoIP\tDestinoPorta\n";

    int contador = 0;
    //Percorre os registros e exporta os que passaram pelo filtro
    for (auto reg : logs)
    {
        if (atendeFiltros(reg))
        {
            arquivoSaida << reg->toExportString() << "\n"; // Escreve a linha formatada no arquivo
            contador++;
        }
    }

    // Escreve o rodape com o total de registros exportados e os filtros que foram aplicados
    arquivoSaida << "\n# Total de registros exportados: " << contador << "\n";
    arquivoSaida << "# Filtros aplicados:\n";
    for (const auto &f : filtros)
    {
        arquivoSaida << "# Campo: " << f.campo
                     << " | Valor1: " << f.valor1;
        if (f.isIntervalo)
            arquivoSaida << " | Valor2: " << f.valor2;
        arquivoSaida << "\n";
    }

    arquivoSaida.close(); // fecha o arquivo

    cout << contador << " registros exportados para o arquivo '" << nomeArquivo << "'." << endl;
}

    // imprime o cabecalho da tabela na tela
    void mostrarCabecalho()
    {
        cout << left << setw(20) << "DataHora"
             << setw(12) << "Codigo"
             << setw(30) << "Mensagem"
             << setw(20) << "Classificacao"
             << setw(10) << "Prioridade "
             << setw(10) << "Protocolo"
             << setw(18) << "OrigemIP"
             << setw(8) << "OrigPort "
             << setw(18) << "DestinoIP"
             << setw(8) << "DestPort"
             << endl;
        cout << string(154, '-') << endl;
    }

    //Destrutor da classe
    ~Sistema()
    {
        for (auto reg : logs)
        {
            delete reg; // libera a memoria alocada para cada registro
        }
        logs.clear(); // limpa o vector
    }
};

int main()
{
    Sistema sistema("snortsyslog");
    /*
    Funcoes teste
    sistema.mostrarCabecalho();
    sistema.mostrarPrimeiros(20);
    */

    int opcao;

    //Manipulacao do menu
    do
    {
        cout << "\n===== MENU =====" << endl;
        cout << "1 - Adicionar Filtro" << endl;
        cout << "2 - Limpar Filtros" << endl;
        cout << "3 - Visualizar Filtros" << endl;
        cout << "4 - Visualizar Dados" << endl;
        cout << "5 - Exportar Dados" << endl;
        cout << "0 - Sair" << endl;

        cout << "\nDigite a sua opcao: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao)
        {
        case 1:
            sistema.adicionarFiltro();
            break;
        case 2:
            sistema.limparFiltros();
            break;
        case 3:
            sistema.visualizarFiltros();
            break;
        case 4:
            cout << endl;
            sistema.mostrarCabecalho();
            sistema.visualizarDados();
            break;
        case 5:
            sistema.exportarDados();
            break;
        case 0:
            cout << "Saindo do programa." << endl;
            Sleep(500);
            break;
        default:
            cout << "Opcao invalida! Digite um numero entre 0 e 5." << endl;
            break;
        }

    } while (opcao != 0); // repete ate o usuario escolher sair

    return 0;
}
