#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limparChavesEAspas(char *str) {
    if (str == NULL) return;

    char *inicio = strchr(str, '{');
    char *fim = strrchr(str, '}');

    if (inicio && fim && fim > inicio) {
        memmove(str, inicio + 1, fim - inicio - 1);
        str[fim - inicio - 1] = '\0';
    }

    // Remover aspas duplas se existirem
    if (str[0] == '"') {
        memmove(str, str + 1, strlen(str));
        char *fimAspas = strrchr(str, '"');
        if (fimAspas) *fimAspas = '\0';
    }
}

#include "func.h"
#include <stdio.h>
#include <stdlib.h>

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
