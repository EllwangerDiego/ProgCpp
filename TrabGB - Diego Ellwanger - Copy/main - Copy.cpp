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
    Registro(string linha)
    {
        istringstream iss(linha);
        string mes, dia, hora, codigoTemp;
        iss >> mes >> dia >> hora >> codigoTemp;
        codigo = codigoTemp;

        // Montar dataHora com ano atual:
        time_t t = time(nullptr);
        tm *now = localtime(&t);
        int ano = now->tm_year + 1900;
        string mesNum = mesParaNumero(mes);
        if (dia.size() == 1)
            dia = "0" + dia;
        dataHora = to_string(ano) + "-" + mesNum + "-" + dia + " " + hora;

        vector<string> restoTokens;
        string token;
        while (iss >> token)
        {
            restoTokens.push_back(token);
        }

        // Extrair classificacao e prioridade (se existirem)
        int prioridadeIndex = -1;
        for (int i = 0; i < (int)restoTokens.size(); i++)
        {
            if (restoTokens[i].find("[Classification:") != string::npos)
            {
                string temp = restoTokens[i];
                while (temp.back() != ']')
                {
                    i++;
                    if (i < (int)restoTokens.size())
                        temp += " " + restoTokens[i];
                    else
                        break;
                }
                size_t start = temp.find(":") + 1;
                size_t end = temp.find("]");
                classificacao = temp.substr(start, end - start);
                classificacao.erase(0, classificacao.find_first_not_of(" "));
            }

            if (restoTokens[i].find("[Priority:") != string::npos)
            {
                size_t start = restoTokens[i].find(":") + 1;
                size_t end = restoTokens[i].find("]");
                string prioridadeStr = restoTokens[i].substr(start, end - start);
                prioridade = stringParaInt(prioridadeStr);
                prioridadeIndex = i;
                break;
            }
        }

        if (prioridadeIndex == -1)
            prioridade = 0;

        mensagem.clear();
        for (int i = 0; i < prioridadeIndex; i++)
        {
            mensagem += restoTokens[i];
            if (i < prioridadeIndex - 1)
                mensagem += " ";
        }

        for (int i = prioridadeIndex; i < (int)restoTokens.size(); i++)
        {
            if (restoTokens[i][0] == '{' && restoTokens[i].back() == '}')
            {
                protocolo = restoTokens[i].substr(1, restoTokens[i].length() - 2); // remove { }
                if (i + 3 < (int)restoTokens.size() && restoTokens[i + 2] == "->")
                {
                    origemIP = restoTokens[i + 1];
                    destinoIP = restoTokens[i + 3];

                    // Tentar extrair portas se existirem (IP:PORTA)
                    size_t posOrig = origemIP.find(':');
                    if (posOrig != string::npos)
                    {
                        origemPorta = stringParaInt(origemIP.substr(posOrig + 1));
                        origemIP = origemIP.substr(0, posOrig);
                    }

                    size_t posDest = destinoIP.find(':');
                    if (posDest != string::npos)
                    {
                        destinoPorta = stringParaInt(destinoIP.substr(posDest + 1));
                        destinoIP = destinoIP.substr(0, posDest);
                    }
                }
                break;
            }
        }

        origemPorta = 0;
        if (prioridadeIndex + 3 < (int)restoTokens.size() && ehNumero(restoTokens[prioridadeIndex + 3]))
            origemPorta = stringParaInt(restoTokens[prioridadeIndex + 3]);

        int destinoIPIndex = (origemPorta == 0) ? prioridadeIndex + 3 : prioridadeIndex + 4;
        destinoIP = (destinoIPIndex < (int)restoTokens.size()) ? restoTokens[destinoIPIndex] : "";

        destinoPorta = 0;
        int destinoPortaIndex = destinoIPIndex + 1;
        if (destinoPortaIndex < (int)restoTokens.size() && ehNumero(restoTokens[destinoPortaIndex]))
            destinoPorta = stringParaInt(restoTokens[destinoPortaIndex]);
    }

    void mostrar()
    {
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

    string toExportString()
    {
        ostringstream oss;
        oss << dataHora << "\t" << codigo << "\t" << mensagem << "\t" << classificacao << "\t"
            << prioridade << "\t" << protocolo << "\t" << origemIP << "\t"
            << origemPorta << "\t" << destinoIP << "\t" << destinoPorta;
        return oss.str();
    }

    // Getters
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
    vector<Registro *> logs;
    vector<Filtro> filtros;

    bool atendeFiltros(Registro *reg)
    {
        for (const auto &filtro : filtros)
        {
            // para comparação case insensitive, converta os campos para minúsculo
            auto minusculo = [](const string &s)
            {
                string res = s;
                transform(res.begin(), res.end(), res.begin(), ::tolower);
                return res;
            };

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
        return true; // passou por todos os filtros
    }

public:
    Sistema(const string &nomeArquivo)
    {
        ifstream arquivo(nomeArquivo);
        if (!arquivo.is_open())
        {
            cout << "Erro ao abrir arquivo: " << nomeArquivo << endl;
            return;
        }

        string linha;
        getline(arquivo, linha); // Pular cabeçalho

        while (getline(arquivo, linha))
        {
            if (linha.empty())
                continue;

            Registro *reg = new Registro(linha);
            logs.push_back(reg);
        }

        arquivo.close();
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
        Filtro novoFiltro;

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

            if (tipo == 1)
            {
                cout << "Digite o valor exato: ";
                getline(cin, novoFiltro.valor1);
                novoFiltro.isIntervalo = false;
            }
            else if (tipo == 2)
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

        filtros.push_back(novoFiltro);
        cout << "Filtro adicionado com sucesso!" << endl;
    }

    void visualizarFiltros()
    {
        cout << "\n=== Filtros Ativos ===" << endl;
        if (filtros.empty())
        {
            cout << "Nenhum filtro ativo." << endl;
            return;
        }

        for (size_t i = 0; i < filtros.size(); i++)
        {
            cout << "Filtro #" << i + 1 << ": Campo = " << filtros[i].campo
                 << ", Valor1 = " << filtros[i].valor1;

            if (filtros[i].isIntervalo)
                cout << ", Valor2 = " << filtros[i].valor2;

            cout << endl;
        }
    }

    void limparFiltros()
    {
        filtros.clear();
        cout << "Todos os filtros foram removidos." << endl;
    }

    void visualizarDados()
    {
        // cout << "\n===== DADOS FILTRADOS =====" << endl;
        int contador = 0;
        for (auto reg : logs)
        {
            if (atendeFiltros(reg))
            {
                cout << "Registro #" << contador + 1 << ":" << endl;
                reg->mostrar();
                cout << "---------------------------" << endl;
                contador++;
            }
        }
        if (contador == 0)
            cout << "Nenhum registro encontrado com os filtros atuais." << endl;

        cout << "\nTotal de registros exibidos: " << contador << endl;
        visualizarFiltros();
    }

    void exportarDados()
    {
        cout << "Digite o nome do arquivo para salvar os registros filtrados: ";
        string nomeArquivo;
        getline(cin, nomeArquivo);

        ofstream arquivoSaida(nomeArquivo);
        if (!arquivoSaida.is_open())
        {
            cout << "Erro ao abrir o arquivo para escrita." << endl;
            return;
        }

        int contador = 0;
        for (auto reg : logs)
        {
            if (atendeFiltros(reg))
            {
                arquivoSaida << reg->toExportString() << endl;
                contador++;
            }
        }
        arquivoSaida.close();

        cout << contador << " registros exportados para o arquivo '" << nomeArquivo << "'." << endl;
    }

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

    ~Sistema()
    {
        for (auto reg : logs)
        {
            delete reg;
        }
        logs.clear();
    }
};

int main()
{
    Sistema sistema("snortsyslog"); // Ajuste o caminho do arquivo de log
    sistema.mostrarCabecalho();
    sistema.mostrarPrimeiros(20);

    int opcao;

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

    } while (opcao != 0);

    return 0;
}
