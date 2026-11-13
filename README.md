# 🏦 Sistema Bancário em C++

![Linguagem](https://img.shields.io/badge/Linguagem-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Tipo](https://img.shields.io/badge/Projeto-Acadêmico-2E8B57?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Concluído-brightgreen?style=for-the-badge)

## 📌 Sobre o projeto

O **Sistema Bancário** é um projeto acadêmico desenvolvido em **C++**, com o objetivo de aplicar conceitos fundamentais de programação por meio da simulação de operações bancárias.

O trabalho foi organizado em **duas etapas**, permitindo acompanhar a evolução do sistema desde as funcionalidades básicas de gerenciamento de contas até a implementação de movimentações financeiras.

O projeto utiliza estruturas condicionais, laços de repetição, arrays, strings e validações para simular o funcionamento de um sistema bancário no terminal.

---

## 🚀 Funcionalidades

O sistema permite realizar as seguintes operações:

- ✅ Cadastrar contas bancárias.
- ✅ Listar contas cadastradas.
- ✅ Consultar contas pelo número.
- ✅ Realizar depósitos.
- ✅ Efetuar saques com verificação de saldo.
- ✅ Transferir valores entre contas.
- ✅ Consultar o extrato de movimentações.
- ✅ Validar dados informados pelo usuário.
- ✅ Impedir operações com valores inválidos.
- ✅ Registrar movimentações financeiras.

### 🔐 Validações implementadas

Para garantir maior consistência nas operações, o sistema possui verificações como:

- CPF contendo exatamente 11 dígitos numéricos.
- Número de conta não duplicado.
- Tipo de conta válido (corrente ou poupança).
- Valores monetários positivos nas movimentações.
- Saldo suficiente para realizar saques e transferências.
- Existência e situação ativa das contas envolvidas.

---

## 📂 Estrutura do projeto

```text
Sistema-Bancario/
│
├── sistema-bancario-etapa1/
│   └── Código da primeira etapa
│
├── sistema-bancario-etapa2/
│   └── Código da segunda etapa
│
└── README.md
```

### 📘 Etapa 1 — Gerenciamento de contas

A primeira etapa apresenta a estrutura inicial do sistema bancário e trabalha os fundamentos necessários para cadastrar e gerenciar contas.

**Principais conceitos:**
- Variáveis e tipos de dados.
- Arrays para armazenamento.
- Estruturas condicionais.
- Estruturas de repetição.
- Entrada e saída de dados.
- Menus interativos.

### 📗 Etapa 2 — Operações bancárias

A segunda etapa amplia o sistema, implementando operações financeiras e controles para garantir que as movimentações ocorram corretamente.

**Principais recursos:**
- Depósitos e saques.
- Transferências bancárias.
- Consulta de extrato.
- Registro de movimentações.
- Verificação de saldo.
- Tratamento de entradas inválidas.

---

## 🛠️ Tecnologias utilizadas

| Tecnologia | Finalidade |
|---|---|
| C++ | Desenvolvimento do sistema |
| Biblioteca iostream | Entrada e saída de dados |
| Biblioteca string | Manipulação de textos |
| Biblioteca iomanip | Formatação de valores |
| Biblioteca limits | Tratamento de entradas |
| Git | Versionamento do código |
| GitHub | Hospedagem do repositório |

---

## 💻 Como executar

### 1. Clone o repositório

```bash
git clone URL_DO_REPOSITORIO
```

### 2. Acesse a pasta do projeto

```bash
cd Sistema-Bancario
```

### 3. Compile o programa

Com o compilador G++ instalado, entre na pasta da etapa desejada e execute:

```bash
g++ main.cpp -o sistema
```

> Substitua `main.cpp` pelo nome real do arquivo C++ da etapa escolhida.

### 4. Execute o sistema

No Windows (PowerShell):

```powershell
.\sistema.exe
```

No Linux:

```bash
./sistema
```

---

## 🖥️ Menu do sistema

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

## 🧠 Conhecimentos desenvolvidos

Durante o desenvolvimento deste projeto, foram praticados conceitos importantes da programação:

- Organização e estruturação de código em C++.
- Desenvolvimento de algoritmos.
- Manipulação de arrays paralelos.
- Implementação de regras de negócio.
- Validação de entradas.
- Controle de fluxo com `if`, `switch`, `for` e `do while`.
- Lógica de movimentações financeiras.
- Identificação e correção de erros.

---

## ⚠️ Limitações do projeto

Este sistema foi desenvolvido para fins educacionais.

- Os dados ficam armazenados temporariamente na memória.
- As informações são perdidas ao encerrar o programa.
- Não existe integração com bancos reais.
- O histórico possui capacidade limitada.
- Não utiliza banco de dados ou autenticação.

Essas limitações representam oportunidades para futuras melhorias.

---

## 🔮 Melhorias futuras

- [ ] Implementar persistência de dados em arquivos.
- [ ] Integrar um banco de dados.
- [ ] Criar autenticação para clientes.
- [ ] Implementar encerramento de contas.
- [ ] Adicionar datas e horários às movimentações.
- [ ] Desenvolver uma interface gráfica.

---

## 👨‍💻 Desenvolvedor

**Filipe Pereira dos Santos**

Estudante e desenvolvedor em formação, com interesse em desenvolvimento de software e aprendizado contínuo.

**GitHub:** [filipepereiradossantos](https://github.com/pereiralp)

---

<p align="center">
  <strong>🏦 Sistema Bancário em C++</strong>
  
  <em>Projeto acadêmico desenvolvido para praticar lógica de programação e fundamentos da linguagem C++.</em>
</p>
