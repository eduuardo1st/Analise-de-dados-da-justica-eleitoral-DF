
# 📊 Análise de Dados da Justiça Eleitoral (DF)

Projeto desenvolvido como parte da disciplina de **Programação Estruturada (2025/1)**, com foco na manipulação de dados estruturados em linguagem C, utilizando vetores de structs, alocação dinâmica e TADs.

---

## 🎯 Objetivo

Este projeto tem como objetivo a leitura, organização e análise de dados relacionados a processos da Justiça Eleitoral do Distrito Federal, presentes em um arquivo `.csv`. O sistema simula funcionalidades de um pequeno sistema de consulta judicial.

---

## ✅ Funcionalidades Implementadas

- Leitura e carregamento de dados de um arquivo `.csv` com milhares de processos.
- Ordenação dos processos:
  - Por **ID** (crescente).
  - Por **Data de Ajuizamento** (da mais recente para a mais antiga).
- Contagem de processos associados a uma determinada **classe processual** (`id_classe`).
- Cálculo de **dias em tramitação** com base na data de ajuizamento.
- Contagem do número total e único de **assuntos processuais** (`id_assunto`).
- Listagem de processos que possuem **múltiplos assuntos**.

---

## 🗃️ Estrutura dos Dados

Cada processo contém os seguintes campos:

- `id`: Identificador único do processo.
- `numero`: Número oficial do processo.
- `data_ajuizamento`: Data e hora de início do processo.
- `id_classe`: Classe processual (pode conter múltiplos valores).
- `id_assunto`: Assunto(s) vinculado(s) ao processo.
- `ano_eleicao`: Ano da eleição associada ao processo.

---

## 🧪 Tecnologias e Técnicas Utilizadas

- Linguagem C
- Vetores de structs e TAD
- Alocação dinâmica de memória
- Manipulação de arquivos `.csv`
- Implementação manual de algoritmos de ordenação (`QuickSort`)
- Separação modular em múltiplos arquivos:
  - `main.c` (execução principal)
  - `func.c` (implementações)
  - `func.h` (interface e definições)
- Manipulação de datas e uso da biblioteca `time.h`

---

## 🧰 Como Executar

1. Clone este repositório:

```bash
git clone https://github.com/seu-usuario/seu-repositorio.git
cd seu-repositorio
```

2. Compile o código:

```bash
gcc main.c func.c -o analise_processos
```

3. Certifique-se de ter um arquivo `.csv` chamado `processo_043_202409032338.csv` na pasta do projeto.

4. Execute o programa:

```bash
./analise_processos
```

---

## 👨‍💻 Autoria

Desenvolvido por:

- Eduardo Gonçalves – [eduardouc388@gmail.com](mailto:eduardouc388@gmail.com) – [@eduuardo1st](https://github.com/eduuardo1st)  
- Arthur Vieira – [arthurVsousa@outlook.com](mailto:arthurVsousa@outlook.com) – [@He1ce](https://github.com/He1ce)  

Curso de Engenharia de Software - 2024, Universidade XYZ.

---

## 📄 Licença

Este projeto está licenciado sob a **MIT License**. Consulte o arquivo `LICENSE` para mais informações.
