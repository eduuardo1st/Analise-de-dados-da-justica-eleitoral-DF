#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "func.h"

Processo *LerArquivo(const char *nomeArquivo){
    int N = 0;
    char linha[2048];

    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("ERRO! Falha ao abrir o arquivo.\n");
        return NULL;
    }

    Processo *processos = (Processo *)malloc(NumProcesso * sizeof(Processo));
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
        for (I_classe = I_data + 1; linha[I_classe] != '}' && (I_classe - I_data - 1) < sizeof(processos[N].id_classe)-1; I_classe++) 
            processos[N].id_classe[I_classe - I_data - 1] = linha[I_classe];
        processos[N].id_classe[I_classe - I_data - 1] = '\0';
        I_classe++;

        if(linha[I_classe] == '\"') I_classe += 2;
        else I_classe++;

        if(linha[I_classe] == '\"') I_classe++;

        int I_assunto;
        for(I_assunto = I_classe + 1; linha[I_assunto] != '}' && (I_assunto - I_classe - 1) < sizeof(processos[N].id_assunto)-1; I_assunto++) 
            processos[N].id_assunto[I_assunto - I_classe - 1] = linha[I_assunto];
        processos[N].id_assunto[I_assunto - I_classe - 1] = '\0';
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

void QuickSortID(Processo *V, int inf, int sup){
	if(inf < sup){
		int P = Particao(V, inf, sup);
		QuickSortID(V, inf, P - 1);
		QuickSortID(V, P, sup);
	}
	
}

int Particao(Processo *V, int inf, int sup){
	Processo Pivo = V[(inf + sup) / 2];
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

void Swap(Processo *a, Processo *b){
	Processo temp = *a;
	*a = *b;
	*b = temp;
}

void QuickSortDataMaisAtual(Processo *V, int inf, int sup){
	if(inf < sup){
		int P = ParticaoData(V, inf, sup);
		QuickSortDataMaisAtual(V, inf, P - 1);
		QuickSortDataMaisAtual(V, P, sup);
	}
	
}

int ParticaoData(Processo *V, int inf, int sup){
	Processo Pivo = V[(inf + sup) / 2];
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

void QntdProcessosID_classe(Processo *V, unsigned char *string){
    int i;
    int processosLigadosAClasse = 0;
    for(i=0;i<NumProcesso;i++){
        if (strstr(V[i].id_classe, string) != NULL) {
            processosLigadosAClasse++;
        }
    }
    printf("Ha %d processos ligados a classe '%s'.\n", processosLigadosAClasse, string);
}

void EscreverArquivo(Processo *V, const char *nomeArquivo){
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("ERRO! Falha ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "id;numero;data_ajuizamento;id_classe;id_assunto;ano_eleicao\n");

    for(int i = 0; i < NumProcesso; i++){
        fprintf(arquivo, "%s,\"%s\",%s,\"{%s}\",\"{%s}\",%d\n", 
                V[i].id, 
                V[i].numero, 
                V[i].data_ajuizamento, 
                V[i].id_classe, 
                V[i].id_assunto, 
                V[i].ano_eleicao);
    }

    fclose(arquivo);
}

void QntdProcessosID_assunto(Processo *V){

    int Qtd_total = 0;
    for (int i = 0; i < NumProcesso; i++){
        Qtd_total++;
        for (int j = 0; V[i].id_assunto[j] != '\0'; j++){
            if (V[i].id_assunto[j] == ','){
                Qtd_total++;
            }
        }
    }

    int assuntos_diff[100]; 
    int Qtd_diff = 0;
    int i = 0;
    
    do {
        int temp[5] = {0};  
        int Qtd_adicionado = sscanf(V[i].id_assunto, "%d,%d,%d,%d,%d",
                                     &temp[0], &temp[1], &temp[2],
                                     &temp[3], &temp[4]);
    
        for (int j = 0; j < Qtd_adicionado; j++) {
            int valor = temp[j];
            int ja_existe = 0;
    
            for (int k = 0; k < Qtd_diff; k++) {
                if (assuntos_diff[k] == valor) {
                    ja_existe = 1;
                    break;
                }
            }
    
            if (!ja_existe) {
                assuntos_diff[Qtd_diff++] = valor;
            }
        }
    
        i++;
    } while (i < NumProcesso);

    printf("Constam %d assuntos totais na base de dados e %d assuntos unicos.\n", Qtd_total, Qtd_diff);
}

void QntdAssuntosMultiplos(Processo *V){
    int Qtd_total = 0;
    for (int i = 0; i < NumProcesso; i++){
        if(strstr(V[i].id_assunto, ",") != NULL){
            printf("%s,%s,%s,{%s},\"{%s}\",%d\n", V[i].id, V[i].numero, V[i].data_ajuizamento, V[i].id_classe, V[i].id_assunto, V[i].ano_eleicao);
            Qtd_total++;
        }
    }
    printf(" ^ foram encontrados %d processos que estao vinculados a mais de um assunto.^\n", Qtd_total);
}

void QuantosDias(Processo *V, unsigned char *string){

    time_t calendario_atual;
    if (time(&calendario_atual) == -1)
    {
        printf("Calendario indisponível.\n");
        exit(1);
    }

    struct tm *calendario_atual_struct = localtime(&calendario_atual);

    struct tm data_CSV;

    int i = 0;
    for (i; i < NumProcesso; i++)
    {
        if (strstr(V[i].id, string) != NULL)
            break;
    }

    if (i == NumProcesso)
    {
        printf("Processo com ID '%s' não encontrado.\n", string);
        return;
    }

    if (sscanf(V[i].data_ajuizamento, "%d-%d-%d %d:%d:%d",
               &data_CSV.tm_year, &data_CSV.tm_mon, &data_CSV.tm_mday,
               &data_CSV.tm_hour, &data_CSV.tm_min, &data_CSV.tm_sec) == 6)
    {
        data_CSV.tm_year -= 1900;
        data_CSV.tm_mon -= 1;
        data_CSV.tm_isdst = -1;
    }
    else
    {
        printf("Erro ao ler a data do processo.\n");
        return;
    }

    time_t tempo_CSV = mktime(&data_CSV);

    if (tempo_CSV == -1)
    {
        printf("\nErro ao converter a data CSV para time_t\n");
        exit(1);
    }

    time_t segundos_diferenca = difftime(calendario_atual, tempo_CSV);
    float dias = (float)segundos_diferenca / 86400;
    if (calendario_atual_struct->tm_hour > data_CSV.tm_hour)
        dias--;

    printf("\nLinha - %d", i + 2);
    printf("\nO processo de id '%s' esta em tramitacao na justica ha %.f dias!\n", string, dias);
}
