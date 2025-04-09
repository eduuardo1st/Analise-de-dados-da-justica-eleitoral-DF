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

/*     int i;
    for(i=10667; i<10673; i++) {
        printf("Linha: %d - %s\n", i+2, processos[i].data_ajuizamento);
    } */

    printf("\n");

    QuickSortID(processos, 0, NumProcesso - 1);
    EscreverArquivo( processos, "./processo_ordenado_id.csv");

    QuickSortDataMaisAtual(processos, 0, NumProcesso - 1);
    EscreverArquivo( processos, "./processo_ordenado_data.csv");

    QntdProcessosID_classe(processos, "261");

    QuantosDias(processos,"405277413");

    free(processos);
    return 0;
}
