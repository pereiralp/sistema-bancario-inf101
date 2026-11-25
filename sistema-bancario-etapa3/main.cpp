/*
    Sistema Bancario - Banco INF101
    Nome: Filipe Pereira dos Santos
    RA: 28787
    Etapa 3: Persistencia de dados em arquivos
    Baseado no codigo ja realizado na Etapa 2.
*/

#include <iostream> // Permite usar cin e cout.
#include <string>   // Permite guardar o nome e o CPF como texto.
#include <iomanip>  // Permite mostrar valores com duas casas decimais.
#include <limits>   // Permite limpar entradas incorretas do teclado.
#include <cmath>    // Permite verificar se um valor monetario e finito.
#include <fstream>  // Leitura e gravacao em arquivos.
#include <sstream>  // Separa os campos de cada linha do arquivo.
#include <cctype>   // Permite validar os digitos do CPF.
using namespace std;


// Cada indice dos arrays paralelos representa uma mesma conta.
// Salva TODAS as contas, substituindo o conteudo anterior por dados atualizados.
bool salvarContas(const int numeroConta[], const string nomeCliente[], const string cpf[],
                  const int tipoConta[], const double saldo[], const bool contaAtiva[],
                  int quantidadeContas) {
    ofstream arquivo("contas.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir contas.txt para gravacao.\n";
        return false;
    }
    arquivo << fixed << setprecision(2);
    for (int i = 0; i < quantidadeContas; i++) {
        arquivo << numeroConta[i] << ';' << nomeCliente[i] << ';' << cpf[i] << ';'
                << tipoConta[i] << ';' << saldo[i] << ';' << contaAtiva[i] << '\n';
    }
    arquivo.close();
    if (arquivo.fail()) {
        cout << "Erro ao gravar contas.txt.\n";
        return false;
    }
    return true;
}

// Le do arquivo os dados salvos na execucao anterior e preenche os arrays.
void carregarContas(int numeroConta[], string nomeCliente[], string cpf[],
                    int tipoConta[], double saldo[], bool contaAtiva[],
                    int &quantidadeContas, int maxContas) {
    ifstream arquivo("contas.txt");
    if (!arquivo.is_open()) return; // Primeira execucao: arquivo ainda nao existe.

    string linha;
    while (quantidadeContas < maxContas && getline(arquivo, linha)) {
        string numeroStr, nome, documento, tipoStr, saldoStr, ativaStr;
        stringstream campos(linha);
        if (!getline(campos, numeroStr, ';') || !getline(campos, nome, ';') ||
            !getline(campos, documento, ';') || !getline(campos, tipoStr, ';') ||
            !getline(campos, saldoStr, ';') || !getline(campos, ativaStr, ';')) continue;
        try {
            int numero = stoi(numeroStr), tipo = stoi(tipoStr), ativa = stoi(ativaStr);
            double valor = stod(saldoStr);
            if (numero <= 0 || nome.empty() || tipo < 1 || tipo > 2 ||
                (ativa != 0 && ativa != 1) || !isfinite(valor) || valor < 0) continue;
            bool duplicado = false;
            for (int i = 0; i < quantidadeContas; i++) {
                if (numeroConta[i] == numero) duplicado = true;
            }
            if (duplicado) continue;
            int i = quantidadeContas;
            numeroConta[i] = numero;
            nomeCliente[i] = nome;
            cpf[i] = documento;
            tipoConta[i] = tipo;
            saldo[i] = valor;
            contaAtiva[i] = (ativa == 1);
            quantidadeContas++;
        } catch (...) {
            // Ignora registros danificados sem encerrar o sistema.
        }
    }
    arquivo.close();
}

// Salva novamente o historico completo, preservando os registros ja carregados.
bool salvarMovimentacoes(const int contaMovimentacao[], const char tipoMovimentacao[],
                         const double valorMovimentacao[], int quantidadeMovimentacoes) {
    ofstream arquivo("movimentacoes.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir movimentacoes.txt para gravacao.\n";
        return false;
    }
    arquivo << fixed << setprecision(2);
    for (int i = 0; i < quantidadeMovimentacoes; i++) {
        arquivo << contaMovimentacao[i] << ';' << tipoMovimentacao[i] << ';'
                << valorMovimentacao[i] << '\n';
    }
    arquivo.close();
    if (arquivo.fail()) {
        cout << "Erro ao gravar movimentacoes.txt.\n";
        return false;
    }
    return true;
}

// Recarrega historico anterior, evitando que os extratos se percam ao reiniciar.
void carregarMovimentacoes(int contaMovimentacao[], char tipoMovimentacao[],
                           double valorMovimentacao[], int &quantidadeMovimentacoes,
                           int maxMovimentacoes) {
    ifstream arquivo("movimentacoes.txt");
    if (!arquivo.is_open()) return;
    string linha;
    while (quantidadeMovimentacoes < maxMovimentacoes && getline(arquivo, linha)) {
        string contaStr, tipoStr, valorStr;
        stringstream campos(linha);
        if (!getline(campos, contaStr, ';') || !getline(campos, tipoStr, ';') ||
            !getline(campos, valorStr, ';')) continue;
        try {
            int numero = stoi(contaStr);
            double valor = stod(valorStr);
            if (numero <= 0 || tipoStr.size() != 1 ||
                (tipoStr[0] != 'D' && tipoStr[0] != 'S') ||
                !isfinite(valor) || valor <= 0) continue;
            int i = quantidadeMovimentacoes;
            contaMovimentacao[i] = numero;
            tipoMovimentacao[i] = tipoStr[0];
            valorMovimentacao[i] = valor;
            quantidadeMovimentacoes++;
        } catch (...) {
            // Ignora linhas invalidas sem travar a leitura.
        }
    }
    arquivo.close();
}

int main() {
    // Arrays paralelos: cada indice representa uma conta bancaria.
    const int MAX_CONTAS = 100;
    int numeroConta[MAX_CONTAS];
    string nomeCliente[MAX_CONTAS];
    string cpf[MAX_CONTAS];
    int tipoConta[MAX_CONTAS];
    double saldo[MAX_CONTAS];
    bool contaAtiva[MAX_CONTAS];
    int quantidadeContas = 0; // Quantidade de contas efetivamente cadastradas.

    // Arrays paralelos: cada indice representa uma movimentacao financeira.
    const int MAX_MOVIMENTACOES = 500;
    int contaMovimentacao[MAX_MOVIMENTACOES];
    char tipoMovimentacao[MAX_MOVIMENTACOES]; // 'D' = entrada; 'S' = saida.
    double valorMovimentacao[MAX_MOVIMENTACOES];
    int quantidadeMovimentacoes = 0;

    // Recupera automaticamente os dados guardados na ultima execucao.
    carregarContas(numeroConta, nomeCliente, cpf, tipoConta, saldo, contaAtiva,
                   quantidadeContas, MAX_CONTAS);
    carregarMovimentacoes(contaMovimentacao, tipoMovimentacao, valorMovimentacao,
                          quantidadeMovimentacoes, MAX_MOVIMENTACOES);
    cout << "Dados recuperados: " << quantidadeContas << " contas e "
         << quantidadeMovimentacoes << " movimentacoes.\n";

    int op = 0; // Guarda a opcao escolhida no menu.
    cout << fixed << setprecision(2); // Exibe valores como 150.00.

    do {
        cout << "\n*********************************\n";
        cout << "           BEM-VINDO\n";
        cout << "*********************************\n";
        cout << "1. Cadastrar contas\n";
        cout << "2. Listar as contas cadastradas\n";
        cout << "3. Consultar uma conta pelo numero\n";
        cout << "4. Realizar depositos\n";
        cout << "5. Realizar saques, verificando saldo suficiente\n";
        cout << "6. Realizar transferencias entre duas contas\n";
        cout << "7. Exibir o extrato de uma conta\n";
        cout << "8. Sair\n";
        cout << "Selecione uma opcao: ";
        if (!(cin >> op)) { // Impede que letras travem a leitura do menu.
            if (cin.eof()) break; // Encerra se a entrada terminar.
            cin.clear(); // Retira o estado de erro do cin.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta a entrada invalida.
            cout << "Opcao invalida! Digite um numero de 1 a 8.\n";
            continue; // Mostra o menu novamente.
        }

        switch (op) {
            case 1: { // CADASTRAR CONTA.
                if (quantidadeContas >= MAX_CONTAS) {
                    cout << "Limite maximo de contas atingido!\n";
                    break;
                }
                int novoNumero;
                cout << "\n--- CADASTRO DE CONTA ---\n";
                cout << "Digite o numero da conta: ";
                if (!(cin >> novoNumero)) {
                    cout << "Numero de conta invalido!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                if (novoNumero <= 0) {
                    cout << "Erro: O numero da conta deve ser maior que 0.\n";
                    break;
                }
                bool repetido = false; // Indica se ja existe conta com este numero.
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == novoNumero) {
                        repetido = true;
                        break;
                    }
                }
                if (repetido) {
                    cout << "Erro: Ja existe uma conta com esse numero!\n";
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Prepara o getline.
                string novoNome, novoCpf;
                int novoTipo;
                double novoSaldo;
                cout << "Digite o nome do cliente: ";
                getline(cin, novoNome); // Aceita nomes com espacos.
                cout << "Digite o CPF: ";
                getline(cin, novoCpf); // Preserva zeros no inicio do CPF.
                bool cpfValido = (novoCpf.length() == 11);
                for (char digito : novoCpf) {
                    if (!isdigit(static_cast<unsigned char>(digito))) cpfValido = false;
                }
                if (!cpfValido) {
                    cout << "Erro: CPF deve possuir exatamente 11 digitos numericos!\n";
                    break;
                }
                if (novoNome.empty() || novoCpf.empty()) {
                    cout << "Erro: Nome e CPF nao podem ficar vazios!\n";
                    break;
                }
                cout << "Digite o tipo da conta (1-Corrente, 2-Poupanca): ";
                if (!(cin >> novoTipo)) {
                    cout << "Tipo de conta invalido!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                if (novoTipo != 1 && novoTipo != 2) {
                    cout << "Erro: Tipo de conta invalido (use 1 ou 2)!\n";
                    break;
                }
                cout << "Digite o saldo inicial: R$ ";
                if (!(cin >> novoSaldo)) {
                    cout << "Saldo inicial invalido!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                if (!isfinite(novoSaldo) || novoSaldo < 0) {
                    cout << "Erro: Saldo inicial deve ser um valor valido e nao negativo!\n";
                    break;
                }
                // So grava nos arrays depois que todos os dados forem validados.
                numeroConta[quantidadeContas] = novoNumero;
                nomeCliente[quantidadeContas] = novoNome;
                cpf[quantidadeContas] = novoCpf;
                tipoConta[quantidadeContas] = novoTipo;
                saldo[quantidadeContas] = novoSaldo;
                contaAtiva[quantidadeContas] = true;
                quantidadeContas++; // A proxima conta ocupara o proximo indice.
                if (!salvarContas(numeroConta, nomeCliente, cpf, tipoConta, saldo,
                                  contaAtiva, quantidadeContas)) {
                    cout << "Aviso: cadastro esta na memoria, mas nao foi salvo.\n";
                }
                cout << "Conta cadastrada com sucesso!\n";
                break;
            }

            case 2: { // LISTAR CONTAS ATIVAS.
                if (quantidadeContas == 0) {
                    cout << "Nenhuma conta cadastrada.\n";
                } else {
                    cout << "\n--- LISTA DE CONTAS ---\n";
                    for (int i = 0; i < quantidadeContas; i++) {
                        if (contaAtiva[i]) { // Mostra apenas contas ativas.
                            cout << "Conta: " << numeroConta[i]
                                 << " | Titular: " << nomeCliente[i]
                                 << " | Saldo: R$ " << saldo[i] << '\n';
                        }
                    }
                }
                break;
            }

            case 3: { // CONSULTAR CONTA PELO NUMERO.
                int procurada, indice = -1; // -1 indica que a conta nao foi encontrada.
                cout << "Digite o numero da conta: ";
                if (!(cin >> procurada)) {
                    cout << "Numero invalido!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == procurada && contaAtiva[i]) {
                        indice = i; // Guarda a posicao da conta encontrada.
                        break;
                    }
                }
                if (indice == -1) {
                    cout << "Conta nao encontrada ou inativa!\n";
                } else {
                    cout << "\n--- DADOS DA CONTA ---\n";
                    cout << "Numero: " << numeroConta[indice] << '\n';
                    cout << "Titular: " << nomeCliente[indice] << '\n';
                    cout << "CPF: " << cpf[indice] << '\n';
                    cout << "Tipo: " << (tipoConta[indice] == 1 ? "Corrente" : "Poupanca") << '\n';
                    cout << "Saldo: R$ " << saldo[indice] << '\n';
                    cout << "Situacao: Ativa\n";
                }
                break;
            }

            case 4: { // DEPOSITAR E REGISTRAR UMA MOVIMENTACAO 'D'.
                int procurada, indice = -1;
                double valor;
                cout << "Digite o numero da conta: ";
                if (!(cin >> procurada)) {
                    cout << "Numero invalido!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == procurada && contaAtiva[i]) {
                        indice = i;
                        break;
                    }
                }
                if (indice == -1) {
                    cout << "Conta nao encontrada ou inativa!\n";
                    break;
                }
                if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
                    cout << "Historico cheio! Deposito nao realizado.\n";
                    break;
                }
                cout << "Digite o valor do deposito: R$ ";
                if (!(cin >> valor)) {
                    cout << "Valor invalido!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                if (!isfinite(valor) || valor <= 0 || !isfinite(saldo[indice] + valor)) {
                    cout << "Erro: Digite um valor positivo e valido!\n";
                    break;
                }
                saldo[indice] = saldo[indice] + valor; // Soma o deposito ao saldo.
                contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indice];
                tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                valorMovimentacao[quantidadeMovimentacoes] = valor;
                quantidadeMovimentacoes++; // Um deposito ocupa um registro.
                bool contasSalvas = salvarContas(numeroConta, nomeCliente, cpf, tipoConta,
                                                saldo, contaAtiva, quantidadeContas);
                bool historicoSalvo = salvarMovimentacoes(contaMovimentacao, tipoMovimentacao,
                                                          valorMovimentacao, quantidadeMovimentacoes);
                if (!contasSalvas || !historicoSalvo) cout << "AVISO: erro ao salvar dados.\n";
                cout << "Deposito realizado! Saldo atual: R$ " << saldo[indice] << '\n';
                break;
            }

            case 5: { // SACAR E REGISTRAR UMA MOVIMENTACAO 'S'.
                int procurada, indice = -1;
                double valor;
                cout << "Digite o numero da conta: ";
                if (!(cin >> procurada)) {
                    cout << "Numero invalido!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == procurada && contaAtiva[i]) {
                        indice = i;
                        break;
                    }
                }
                if (indice == -1) {
                    cout << "Conta nao encontrada ou inativa!\n";
                    break;
                }
                if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
                    cout << "Historico cheio! Saque nao realizado.\n";
                    break;
                }
                cout << "Digite o valor do saque: R$ ";
                if (!(cin >> valor)) {
                    cout << "Valor invalido!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                if (!isfinite(valor) || valor <= 0) {
                    cout << "Erro: O valor do saque deve ser positivo!\n";
                    break;
                }
                if (saldo[indice] < valor) { // Bloqueia saque sem saldo suficiente.
                    cout << "Saldo insuficiente!\n";
                    break;
                }
                saldo[indice] = saldo[indice] - valor;
                contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indice];
                tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                valorMovimentacao[quantidadeMovimentacoes] = valor;
                quantidadeMovimentacoes++; // Um saque ocupa um registro.
                bool contasSalvas = salvarContas(numeroConta, nomeCliente, cpf, tipoConta,
                                                saldo, contaAtiva, quantidadeContas);
                bool historicoSalvo = salvarMovimentacoes(contaMovimentacao, tipoMovimentacao,
                                                          valorMovimentacao, quantidadeMovimentacoes);
                if (!contasSalvas || !historicoSalvo) cout << "AVISO: erro ao salvar dados.\n";
                cout << "Saque realizado! Saldo atual: R$ " << saldo[indice] << '\n';
                break;
            }

            case 6: { // TRANSFERIR: UM SAQUE NA ORIGEM E UM DEPOSITO NO DESTINO.
                int numeroOrigem, numeroDestino;
                int indiceOrigem = -1, indiceDestino = -1;
                double valor;
                cout << "Digite o numero da conta de origem: ";
                if (!(cin >> numeroOrigem)) {
                    cout << "Numero invalido!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                cout << "Digite o numero da conta de destino: ";
                if (!(cin >> numeroDestino)) {
                    cout << "Numero invalido!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                if (numeroOrigem == numeroDestino) {
                    cout << "Erro: As contas de origem e destino devem ser diferentes!\n";
                    break;
                }
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numeroOrigem && contaAtiva[i]) {
                        indiceOrigem = i; // Localiza a conta que enviara o dinheiro.
                    }
                    if (numeroConta[i] == numeroDestino && contaAtiva[i]) {
                        indiceDestino = i; // Localiza a conta que recebera o dinheiro.
                    }
                }
                if (indiceOrigem == -1 || indiceDestino == -1) {
                    cout << "Erro: Uma das contas nao existe ou esta inativa!\n";
                    break;
                }
                if (quantidadeMovimentacoes + 2 > MAX_MOVIMENTACOES) {
                    cout << "Historico sem espaco para os dois registros!\n";
                    break;
                }
                cout << "Digite o valor da transferencia: R$ ";
                if (!(cin >> valor)) {
                    cout << "Valor invalido!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                if (!isfinite(valor) || valor <= 0) {
                    cout << "Erro: O valor deve ser positivo!\n";
                    break;
                }
                if (saldo[indiceOrigem] < valor) {
                    cout << "Saldo insuficiente na conta de origem!\n";
                    break;
                }
                if (!isfinite(saldo[indiceDestino] + valor)) {
                    cout << "Erro: Valor excede o saldo permitido!\n";
                    break;
                }
                saldo[indiceOrigem] = saldo[indiceOrigem] - valor; // Debita a origem.
                saldo[indiceDestino] = saldo[indiceDestino] + valor; // Credita o destino.
                contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceOrigem];
                tipoMovimentacao[quantidadeMovimentacoes] = 'S'; // Saida da origem.
                valorMovimentacao[quantidadeMovimentacoes] = valor;
                quantidadeMovimentacoes++;
                contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceDestino];
                tipoMovimentacao[quantidadeMovimentacoes] = 'D'; // Entrada no destino.
                valorMovimentacao[quantidadeMovimentacoes] = valor;
                quantidadeMovimentacoes++; // Uma transferencia usa dois registros.
                bool contasSalvas = salvarContas(numeroConta, nomeCliente, cpf, tipoConta,
                                                saldo, contaAtiva, quantidadeContas);
                bool historicoSalvo = salvarMovimentacoes(contaMovimentacao, tipoMovimentacao,
                                                          valorMovimentacao, quantidadeMovimentacoes);
                if (!contasSalvas || !historicoSalvo) cout << "AVISO: erro ao salvar dados.\n";
                cout << "Transferencia realizada com sucesso!\n";
                cout << "Saldo da origem: R$ " << saldo[indiceOrigem] << '\n';
                cout << "Saldo do destino: R$ " << saldo[indiceDestino] << '\n';
                break;
            }

            case 7: { // EXTRATO: FILTRA O HISTORICO PELO NUMERO DA CONTA.
                int procurada, indice = -1;
                cout << "Digite o numero da conta: ";
                if (!(cin >> procurada)) {
                    cout << "Numero invalido!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == procurada && contaAtiva[i]) {
                        indice = i;
                        break;
                    }
                }
                if (indice == -1) {
                    cout << "Conta nao encontrada ou inativa!\n";
                    break;
                }
                cout << "\n--- EXTRATO DA CONTA " << procurada << " ---\n";
                bool temMovimentacao = false; // Detecta se ha registros para mostrar.
                for (int i = 0; i < quantidadeMovimentacoes; i++) {
                    if (contaMovimentacao[i] == procurada) {
                        temMovimentacao = true;
                        if (tipoMovimentacao[i] == 'D') {
                            cout << "Deposito/entrada: + R$ " << valorMovimentacao[i] << '\n';
                        } else if (tipoMovimentacao[i] == 'S') {
                            cout << "Saque/saida: - R$ " << valorMovimentacao[i] << '\n';
                        }
                    }
                }
                if (!temMovimentacao) {
                    cout << "Nenhuma movimentacao registrada.\n";
                }
                cout << "Saldo atual: R$ " << saldo[indice] << '\n';
                break;
            }

            case 8: // ENCERRAR O PROGRAMA.
                salvarContas(numeroConta, nomeCliente, cpf, tipoConta, saldo,
                             contaAtiva, quantidadeContas);
                salvarMovimentacoes(contaMovimentacao, tipoMovimentacao,
                                    valorMovimentacao, quantidadeMovimentacoes);
                cout << "Saindo do sistema...\n";
                break;

            default: // Trata numeros fora das opcoes do menu.
                cout << "Opcao invalida! Por favor digite de 1 a 8.\n";
        }
    } while (op != 8); // Volta ao menu enquanto a opcao nao for sair.

    return 0; // Finaliza o programa normalmente.
}