#include "func.h"
#include <stdio.h>
#include <stdlib.h>

processo_t *LerArquivo(const char *nomeArquivo){
    FILE *arquivo;
    int i = 0;
    arquivo = fopen(nomeArquivo, "r");
    if(arquivo == NULL){
        printf("ERRO! falha ao abrir o arquivo.\n");
        exit(1);
    }

    processo_t *processos = (processo_t *)malloc(NumProcesso * sizeof(processo_t));
    if (processos == NULL) {
        printf("Não foi possível alocar memória para a tabela!\n");
        exit(1);
    }

    fscanf(arquivo, "%s");//pula primeira linha do arquivo .csv

    while(fscanf(arquivo, "%ld;%lld;%*[^;];%d;%d;%d",
         &processos[i].id, &processos[i].numero, processos[i].data_ajuizamento,
          &processos[i].id_classe, &processos[i].id_assunto, &processos[i].ano_aleicao) == 6)i++;

    fclose(arquivo);
    return processos;
}