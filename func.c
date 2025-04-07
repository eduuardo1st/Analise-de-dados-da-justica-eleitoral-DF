#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

processo_t *LerArquivo(const char *nomeArquivo){
    int N = 0;
    char linha[2048];

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

    fscanf(arquivo, "%*[^\n]\n");

    while(fscanf(arquivo, " %[^\n]\n", linha) == 1 && N < NumProcesso){
        int I_id;
        for(I_id = 0; linha[I_id] != ',' && I_id < sizeof(processos[N].id)-1; I_id++) 
            processos[N].id[I_id] = linha[I_id];
        processos[N].id[I_id] = '\0';
        I_id++;

        int I_numero;
        for(I_numero = I_id + 1; linha[I_numero] != '\"' && (I_numero - I_id - 1) < sizeof(processos[N].numero)-1; I_numero++) 
            processos[N].numero[I_numero - I_id - 1] = linha[I_numero];
        processos[N].numero[I_numero - I_id - 1] = '\0';
        I_numero++;

        int I_data;
        for(I_data = I_numero + 1; linha[I_data] != ',' && (I_data - I_numero - 1) < sizeof(processos[N].data_ajuizamento)-1; I_data++) 
            processos[N].data_ajuizamento[I_data - I_numero - 1] = linha[I_data];
        processos[N].data_ajuizamento[I_data - I_numero - 1] = '\0';
        I_data++;

        if(linha[I_data] == '\"') I_data++;

        int I_classe;
        for (I_classe = I_data + 1; linha[I_classe] != '}' && (I_classe - I_data - 1) < sizeof(processos[N].id_assunto)-1; I_classe++) 
            processos[N].id_assunto[I_classe - I_data - 1] = linha[I_classe];
        processos[N].id_assunto[I_classe - I_data - 1] = '\0';
        I_classe++;

        if(linha[I_classe] == '\"') I_classe += 2;
        else I_classe++;

        if(linha[I_classe] == '\"') I_classe++;

        int I_assunto;
        for(I_assunto = I_classe + 1; linha[I_assunto] != '}' && (I_assunto - I_classe - 1) < sizeof(processos[N].id_classe)-1; I_assunto++) 
            processos[N].id_classe[I_assunto - I_classe - 1] = linha[I_assunto];
        processos[N].id_classe[I_assunto - I_classe - 1] = '\0';
        I_assunto++;

        if(linha[I_assunto] == '\"') I_assunto += 2;
        else I_assunto++;

        int I_ano;
        processos[N].ano_eleicao = 0;
        for(I_ano = I_assunto; I_ano < strlen(linha); I_ano++) processos[N].ano_eleicao = 10 * processos[N].ano_eleicao + (linha[I_ano] - '0');
        

        N++;
    }
   
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

