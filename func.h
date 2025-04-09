#ifndef FUNC_H
#define FUNC_H

#define NumProcesso 18391

typedef struct Processo {
    char id[20];
    char numero[25];
    char data_ajuizamento[40];
    char id_classe[20];
    char id_assunto[20];
    int ano_eleicao;
}Processo;

Processo *LerArquivo(const char *nomeArquivo);

void QuickSortID(Processo *V, int inf, int sup);
int Particao(Processo *V, int inf, int sup);
void QuickSortDataMaisAtual(Processo *V, int inf, int sup);
int ParticaoData(Processo *V, int inf, int sup);
void Swap(Processo *a, Processo *b);
void QntdProcessosID_classe(Processo *V, unsigned char *string);
void EscreverArquivo(Processo *V, const char *nomeArquivo);
void QuantosDias(Processo *V, unsigned char *string);



#endif