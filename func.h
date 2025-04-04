#ifndef FUNC_H
#define FUNC_H

#define NumProcesso 18391

typedef struct processo_t {
    char id[20];
    char numero[25];
    char data_ajuizamento[40];
    char id_classe[20];
    char id_assunto[20];
    char ano_aleicao[5];
}processo_t;

processo_t *LerArquivo(const char *nomeArquivo);

void QuickSort(int *V, int inf, int sup);
int Particao(int *V, int inf, int sup);
void swap(int *a, int*b);



#endif