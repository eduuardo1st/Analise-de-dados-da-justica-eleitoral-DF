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

    while(fscanf(arquivo, " %[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]",
        processos[i].id, 
        processos[i].numero, 
        processos[i].data_ajuizamento,
        processos[i].id_classe, 
        processos[i].id_assunto, 
        processos[i].ano_aleicao) == 6)i++;


    
    fclose(arquivo);
    return processos;
}



void QuickSort(int *V, int inf, int sup){
	if(inf < sup){
		int P = Particao(V, inf, sup);
		QuickSort(V, inf, P - 1);
		QuickSort(V, P, sup);
	}
	
}

int Particao(int *V, int inf, int sup){
	int Pivo = V[(inf + sup) / 2];
	int i = inf;
	int j = sup;
	
	while(i <= j) {
		while(V[i] < Pivo) i++;
		while(V[j] > Pivo) j--;
		if (i <= j){
			swap(&V[i], &V[j]);
			i++;
			j--;
		}
	}
	return i;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	
}
