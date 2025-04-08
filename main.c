#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    Processo *processos = LerArquivo("./processo_043_202409032338.csv");
    if (processos == NULL) {
        printf("Erro ao carregar os processos.\n");
        return 1;
    }

    int i;
    for(i=10667; i<10673; i++) {
        printf("%d %s %s %s %s %s %d\n", i, processos[i].id, processos[i].numero, processos[i].data_ajuizamento, processos[i].id_classe, processos[i].id_assunto, processos[i].ano_eleicao);
    }

    QuickSortID(processos, 0, NumProcesso - 1);
    EscreverArquivo( processos, "./processo_ordenado_id.csv");

    QuickSortDataMaisAtual(processos, 0, NumProcesso - 1);
    EscreverArquivo( processos, "./processo_ordenado_data.csv");

    QntdProcessosID_classe(processos, "261");

    free(processos);
    return 0;
}
