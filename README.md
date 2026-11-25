
# 🏦 Banco INF101 — Sistema Bancário em C++

![C++](https://img.shields.io/badge/Linguagem-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Projeto acadêmico](https://img.shields.io/badge/Projeto-Acad%C3%AAmico-34675C?style=for-the-badge)
![Etapas](https://img.shields.io/badge/Etapas-3-2563EB?style=for-the-badge)

## 📌 Sobre o projeto

O **Banco INF101** é um sistema bancário desenvolvido em C++ como trabalho acadêmico da disciplina **INF101 — Programação de Computadores I**, do **Centro Universitário de Viçosa (UNIVIÇOSA)**.

O projeto tem como objetivo aplicar os conhecimentos adquiridos durante as aulas por meio da criação de um sistema capaz de cadastrar contas bancárias, realizar operações financeiras e armazenar informações.

O desenvolvimento foi dividido em **três etapas**, permitindo acompanhar a evolução do código, desde um sistema básico até a implementação de persistência de dados em arquivos.

---

## 📚 Etapas do desenvolvimento

| Etapa | Descrição | Conteúdos principais |
|---|---|---|
| Etapa 1 | Gerenciamento básico de uma conta | Variáveis, condicionais e repetições |
| Etapa 2 | Múltiplas contas e operações bancárias | Arrays, laços e movimentações |
| Etapa 3 | Armazenamento permanente dos dados | Funções e manipulação de arquivos |

### 📘 Etapa 1 — Fundamentos do sistema bancário

A primeira etapa foi dedicada à construção da estrutura inicial do sistema.

O programa permite cadastrar e gerenciar uma conta bancária por meio de um menu interativo.

**Funcionalidades desenvolvidas:**

- Cadastrar uma conta bancária.
- Informar nome e CPF do titular.
- Definir o número da conta.
- Escolher entre conta corrente e poupança.
- Informar o saldo inicial.
- Consultar os dados da conta.
- Verificar o saldo disponível.
- Alterar o tipo da conta.
- Ativar ou desativar uma conta.
- Validar as informações fornecidas pelo usuário.

**Conceitos utilizados:**

- Variáveis e tipos de dados.
- Entrada e saída com `cin` e `cout`.
- Estruturas condicionais `if` e `else`.
- Estrutura de seleção `switch`.
- Estruturas de repetição `while` e `do-while`.
- Manipulação de strings.

📂 [Acessar código da Etapa 1](./sistema-bancario-etapa1/sistemabancario.cpp)

---

### 📗 Etapa 2 — Múltiplas contas e movimentações

Na segunda etapa, o sistema foi ampliado para permitir o gerenciamento de várias contas bancárias.

Foram implementados **arrays paralelos**, possibilitando armazenar os dados de até 100 contas e registrar até 500 movimentações financeiras.

**Funcionalidades desenvolvidas:**

- Cadastrar múltiplas contas.
- Listar contas cadastradas.
- Consultar uma conta pelo número.
- Realizar depósitos.
- Realizar saques.
- Verificar saldo suficiente antes de um saque.
- Transferir valores entre contas.
- Consultar o extrato de movimentações.
- Impedir o cadastro de números de conta duplicados.
- Validar as operações financeiras.

**Registro de movimentações:**

| Código | Operação | Efeito |
|---|---|---|
| D | Depósito | Adiciona valor ao saldo |
| S | Saque | Subtrai valor do saldo |
| Transferência | Saída + entrada | Atualiza duas contas |

Cada transferência gera dois registros no histórico: um saque na conta de origem e um depósito na conta de destino.

**Conceitos utilizados:**

- Arrays unidimensionais.
- Laços de repetição `for`.
- Busca de informações em arrays.
- Controle de índices.
- Estruturas condicionais.
- Validação de dados.
- Registro de movimentações.

**Observação:** nesta etapa, as informações são armazenadas apenas na memória. Ao encerrar o programa, os dados são perdidos.

📂 [Acessar código da Etapa 2](./sistema-bancario-etapa2/main.cpp)

---

### 📙 Etapa 3 — Persistência de dados em arquivos

A terceira etapa teve como objetivo implementar o armazenamento permanente das informações.

O sistema mantém as funcionalidades da etapa anterior, mas agora utiliza arquivos de texto para preservar contas e movimentações após o encerramento do programa.

**Funcionalidades implementadas:**

- Salvar automaticamente as contas cadastradas.
- Recuperar contas ao iniciar o sistema.
- Armazenar os saldos atualizados.
- Salvar o histórico de movimentações.
- Recuperar depósitos, saques e transferências anteriores.
- Atualizar os arquivos após operações financeiras.
- Organizar as operações de leitura e gravação em funções.

**Funções principais:**

| Função | Responsabilidade |
|---|---|
| `salvarContas()` | Gravar os dados das contas |
| `carregarContas()` | Recuperar as contas armazenadas |
| `salvarMovimentacoes()` | Gravar o histórico financeiro |
| `carregarMovimentacoes()` | Recuperar movimentações anteriores |

### 📄 Arquivos utilizados

**contas.txt**

Responsável por armazenar:

- Número da conta.
- Nome do titular.
- CPF.
- Tipo da conta.
- Saldo.
- Situação da conta.

Exemplo de registro:

```text
1001;Ana Silva;12345678900;1;700.00;1
1002;Bruno Souza;98765432100;2;800.00;1
```

**movimentacoes.txt**

Responsável por armazenar o histórico financeiro.

Exemplo:

```text
1001;D;500.00
1001;S;200.00
1002;D;300.00
```

Os dados são recuperados quando o sistema é executado novamente.

**Conceitos utilizados:**

- Biblioteca `fstream`.
- Manipulação de arquivos de texto.
- `ofstream` para gravação.
- `ifstream` para leitura.
- `is_open()` para verificar a abertura.
- `getline()` para leitura.
- `close()` para fechar arquivos.
- Funções com parâmetros.
- Passagem de arrays para funções.
- Organização e reutilização de código.

📂 [Acessar código da Etapa 3](./sistema-bancario-etapa3/main.cpp)

---

## 📂 Estrutura do repositório

```text
sistema-bancario-inf101/
│
├── sistema-bancario-etapa1/
│   └── sistemabancario.cpp
│
├── sistema-bancario-etapa2/
│   └── main.cpp
│
├── sistema-bancario-etapa3/
│   └── main.cpp
│
└── README.md
```

Os arquivos `contas.txt` e `movimentacoes.txt` são gerados durante a execução da terceira etapa.

---

## 🛠️ Tecnologias utilizadas

| Tecnologia | Finalidade |
|---|---|
| C++ | Desenvolvimento do sistema |
| iostream | Entrada e saída de dados |
| string | Manipulação de textos |
| iomanip | Formatação de valores |
| limits | Tratamento de entradas |
| cmath | Validação de valores numéricos |
| fstream | Leitura e gravação em arquivos |
| sstream | Processamento de registros |
| Git | Controle de versões |
| GitHub | Organização e publicação do projeto |

---

## 💻 Como executar o projeto

### 1. Clonar o repositório

```bash
git clone https://github.com/pereiralp/sistema-bancario-inf101.git
```

### 2. Acessar a pasta do projeto

```bash
cd sistema-bancario-inf101
```

### 3. Escolher a etapa

Para executar a versão mais recente:

```bash
cd sistema-bancario-etapa3
```

### 4. Compilar o código

Com o G++ instalado:

```bash
g++ -std=c++17 main.cpp -o banco-inf101
```

### 5. Executar o programa

**Windows:**

```powershell
.\banco-inf101.exe
```

**Linux:**

```bash
./banco-inf101
```

---

## 🖥️ Menu do sistema — Etapas 2 e 3

```text
*********************************
           BEM-VINDO
*********************************

1. Cadastrar contas
2. Listar as contas cadastradas
3. Consultar uma conta pelo numero
4. Realizar depositos
5. Realizar saques
6. Realizar transferencias
7. Exibir o extrato de uma conta
8. Sair

Selecione uma opcao:
```

---

## 🧪 Testando a Etapa 3

Para verificar o funcionamento do armazenamento permanente:

1. Execute o sistema.
2. Cadastre duas contas bancárias.
3. Realize depósitos, saques ou transferências.
4. Consulte os saldos e extratos.
5. Encerre o programa.
6. Execute o sistema novamente.
7. Consulte as contas e os extratos anteriores.

O objetivo é verificar se os arquivos preservaram as informações e se os dados foram carregados corretamente.

---

## 🧠 Conhecimentos desenvolvidos

Durante o desenvolvimento do Banco INF101, foram praticados:

- Lógica de programação.
- Desenvolvimento de algoritmos.
- Estruturas condicionais e de repetição.
- Manipulação de variáveis e strings.
- Utilização de arrays.
- Busca e validação de informações.
- Controle de operações financeiras.
- Desenvolvimento de funções.
- Leitura e gravação em arquivos.
- Organização e manutenção de código.
- Versionamento com Git e GitHub.

Cada etapa contribuiu para a evolução do sistema e para a aplicação prática dos conteúdos apresentados durante a disciplina.

---

## ⚠️ Limitações do sistema

O Banco INF101 foi desenvolvido exclusivamente para fins acadêmicos.

- Não possui integração com instituições financeiras reais.
- Não utiliza banco de dados.
- Não possui sistema de autenticação.
- Possui limite de contas e movimentações.
- Utiliza arquivos locais para armazenamento.
- Não implementa mecanismos de segurança exigidos em sistemas bancários reais.

---

## 🚀 Possíveis melhorias futuras

- [ ] Implementar banco de dados.
- [ ] Criar autenticação de usuários.
- [ ] Registrar data e horário das movimentações.
- [ ] Implementar encerramento definitivo de contas.
- [ ] Criar uma interface gráfica.
- [ ] Desenvolver relatórios financeiros.
- [ ] Implementar testes automatizados.

---

## 👨‍💻 Desenvolvedor

**Filipe Pereira dos Santos**

**Disciplina:** INF101 — Programação de Computadores I  
**Instituição:** Centro Universitário de Viçosa — UNIVIÇOSA  
**Linguagem:** C++

**GitHub:** [@pereiralp](https://github.com/pereiralp)

---

<p align="center">
  <strong>🏦 Banco INF101 — Sistema Bancário em C++</strong>
</p>

<p align="center">
  Projeto acadêmico desenvolvido em três etapas, aplicando fundamentos de programação, operações bancárias e persistência de dados.
</p>
