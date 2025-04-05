# Análise de Dados da Justiça Eleitoral (DF)

Projeto desenvolvido como parte da disciplina de Programação Estruturada (2025/1), com foco na manipulação de dados estruturados em linguagem C, utilizando vetores de structs e TADs.

---

## Objetivo

Este projeto tem como objetivo a leitura, organização e análise de dados relacionados a processos da Justiça Eleitoral do Distrito Federal, presentes em um arquivo `.csv`. O sistema realiza diferentes operações sobre os dados, simulando funcionalidades de um pequeno sistema de consulta.

---

## Funcionalidades Implementadas

- Leitura e carregamento de dados de um arquivo CSV contendo milhares de processos  
- Ordenação dos dados:
  - Por ID, em ordem crescente
  - Por Data de Ajuizamento, da mais recente para a mais antiga  
- Contagem de processos associados a uma determinada classe processual (`id_classe`)

---

## Estrutura dos Dados

Cada processo possui os seguintes campos:
- `id`: Identificador único do processo
- `numero`: Número oficial do processo
- `data_ajuizamento`: Data e hora de início do processo
- `id_classe`: Classe processual (pode conter múltiplos valores)
- `id_assunto`: Assunto vinculado ao processo
- `ano_eleicao`: Ano da eleição relacionada ao processo

---

## Tecnologias e Técnicas Utilizadas

- Linguagem C
- Alocação dinâmica de memória
- Vetores de structs
- Manipulação de arquivos `.csv`
- Implementação manual de algoritmos de ordenação (sem uso de bibliotecas externas)
- Separação em múltiplos arquivos:
  - `main.c`
  - `func.c`
  - `func.h`
- Utilização de Tipo Abstrato de Dados (TAD)

---

## Funcionalidades Futuras (Em Desenvolvimento)

- Contagem dos diferentes `id_assunto` existentes  
- Listagem de processos com múltiplos assuntos  
- Cálculo de dias em tramitação para cada processo  
- Escrita de arquivos `.csv` com os resultados das ordenações

---

## Como Executar

1. Clone este repositório:
```bash
git clone https://github.com/seu-usuario/seu-repositorio.git
```

2. Compile os arquivos:
```bash
gcc main.c func.c -o analise_processos
```

3. Execute o programa:
```bash
./analise_processos
```

---

## Autoria

Projeto desenvolvido por Eduardo C., como parte do curso de Engenharia de Software - 2024.  
Em caso de dúvidas ou sugestões, entre em contato por [eduardouc388@gmail.com](mailto:eduardouc388@gmail.com)  
GitHub: [https://github.com/eduuardo1st](https://github.com/eduuardo1st)

---

## Licença

Este projeto está licenciado sob a MIT License.
