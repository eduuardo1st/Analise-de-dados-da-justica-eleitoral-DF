#ifndef FUNC_H
#define FUNC_H

#define NumProcesso 18391

typedef struct processo_t {
    long id;
    char numero[25];
    char data_ajuizamento[40];
    int id_classe;
    int id_assunto;
    int ano_aleicao;
}processo_t;

processo_t *LerArquivo(const char *nomeArquivo);

void QuickSort(int *V, int inf, int sup);
int Particao(int *V, int inf, int sup);
void swap(int *a, int*b);



#endif