# ?? TP01 - An�lise de Dados da Justi�a Eleitoral (DF)

Projeto desenvolvido como parte da disciplina de Programa��o Estruturada (2024), com foco na manipula��o de dados estruturados em linguagem C, utilizando vetores de structs e TADs.

---

## ?? Objetivo

Este projeto tem como objetivo a leitura, organiza��o e an�lise de dados relacionados a processos da Justi�a Eleitoral do Distrito Federal, presentes em um arquivo `.csv`. O sistema realiza diferentes opera��es sobre os dados, simulando funcionalidades de um pequeno sistema de consulta.

---

## ?? Funcionalidades Implementadas

? Leitura e carregamento de dados de um arquivo CSV contendo milhares de processos  
? Ordena��o dos dados:
- Por **ID**, em ordem crescente
- Por **Data de Ajuizamento**, da mais recente para a mais antiga  

? Contagem de processos associados a uma determinada **classe processual (`id_classe`)**

---

## ?? Estrutura dos Dados

Cada processo possui os seguintes campos:
- `id`: Identificador �nico do processo
- `numero`: N�mero oficial do processo
- `data_ajuizamento`: Data e hora de in�cio do processo
- `id_classe`: Classe processual (pode conter m�ltiplos valores)
- `id_assunto`: Assunto vinculado ao processo
- `ano_eleicao`: Ano da elei��o relacionada ao processo

Exemplo de linha do arquivo CSV:
```csv
638633058,"00000103020166070018",2016-04-20 15:03:40.000,{12554},{11778},0

## ?? Tecnologias e T�cnicas Utilizadas

Linguagem C

Aloca��o din�mica de mem�ria

Vetores de structs

Manipula��o de arquivos (.csv)

Implementa��o manual de QuickSort (sem uso de bibliotecas externas)

Separa��o em m�ltiplos arquivos:

main.c

func.c

func.h

Uso de Tipo Abstrato de Dados (TAD)

?? Funcionalidades Futuras (Em Desenvolvimento)
?? Contagem dos diferentes id_assunto existentes
?? Listagem de processos com m�ltiplos assuntos
?? C�lculo de dias em tramita��o para cada processo
?? Escrita de arquivos .csv com os resultados das ordena��es

## ?? Como Executar
Clone este reposit�rio:

bash
Copiar
Editar
git clone https://github.com/seu-usuario/seu-repositorio.git
Compile os arquivos:

bash
Copiar
Editar
gcc main.c func.c -o analise_processos
Execute o programa:

bash
Copiar
Editar
./analise_processos

## ????? Autoria
Projeto desenvolvido por Eduardo C., como parte do curso de Engenharia de Software - 2024.
Em caso de d�vidas ou sugest�es, entre em contato por eduardouc388@gmail.com
GitHub: https://github.com/eduuardo1st

## ?? Licen�a
Este projeto est� licenciado sob a MIT License.