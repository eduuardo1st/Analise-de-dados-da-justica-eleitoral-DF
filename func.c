#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

processo_t *LerArquivo(const char *nomeArquivo){
    int i = 0;
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("ERRO! Falha ao abrir o arquivo.\n");
        return NULL;
    }

    processo_t *processos = (processo_t *)malloc(NumProcesso * sizeof(processo_t));
    if (processos == NULL) {
        printf("Nao foi possivel alocar memoria para a tabela!\n");
        fclose(arquivo);
        return NULL;
    }

    // Pular primeira linha
    fscanf(arquivo, "%*[^\n]\n");

    while(fscanf(arquivo, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n",
        processos[i].id, 
        processos[i].numero, 
        processos[i].data_ajuizamento,
        processos[i].id_classe, 
        processos[i].id_assunto, 
        processos[i].ano_aleicao) == 6)i++;


    
    fclose(arquivo);
    return processos;
}

void QuickSortID(processo_t *V, int inf, int sup){
	if(inf < sup){
		int P = Particao(V, inf, sup);
		QuickSortID(V, inf, P - 1);
		QuickSortID(V, P, sup);
	}
	
}

int Particao(processo_t *V, int inf, int sup){
	processo_t Pivo = V[(inf + sup) / 2];
	int i = inf;
	int j = sup;
	
	while (i <= j) {
        while(strcmp(V[i].id, Pivo.id) < 0) i++;
        while(strcmp(V[j].id, Pivo.id) > 0) j--;
        if( i <= j) {
            Swap(&V[i], &V[j]);
            i++;
            j--;
        }
	}
	return i;
}

void Swap(processo_t *a, processo_t *b){
	processo_t temp = *a;
	*a = *b;
	*b = temp;
}

void QuickSortDataMaisAtual(processo_t *V, int inf, int sup){
	if(inf < sup){
		int P = ParticaoData(V, inf, sup);
		QuickSortDataMaisAtual(V, inf, P - 1);
		QuickSortDataMaisAtual(V, P, sup);
	}
	
}

int ParticaoData(processo_t *V, int inf, int sup){
	processo_t Pivo = V[(inf + sup) / 2];
	int i = inf;
	int j = sup;
	
	while (i <= j) {
        while(strcmp(V[i].data_ajuizamento, Pivo.data_ajuizamento) > 0) i++;
        while(strcmp(V[j].data_ajuizamento, Pivo.data_ajuizamento) < 0) j--;
        if( i <= j) {
            Swap(&V[i], &V[j]);
            i++;
            j--;
        }
	}
	return i;
}

void QntdProcessosID_classe(processo_t *V, unsigned char *string){
    int i;
    int processosLigadosAClasse = 0;
    for(i=0;i<NumProcesso-1;i++){
        if (strstr(V[i].id_classe, string) != NULL) {
            processosLigadosAClasse++;
        }
    }
    printf("Ha %d processos ligados a classe '%s'.\n", processosLigadosAClasse, string);
}

