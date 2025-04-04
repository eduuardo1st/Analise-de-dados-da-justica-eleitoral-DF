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

void QuickSortID(processo_t *V, int inf, int sup);
int Particao(processo_t *V, int inf, int sup);
void QuickSortDataMaisAtual(processo_t *V, int inf, int sup);
int ParticaoData(processo_t *V, int inf, int sup);
void Swap(processo_t *a, processo_t *b);
void QntdProcessosID_classe(processo_t *V, unsigned char *string);



#endif