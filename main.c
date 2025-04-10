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

    printf("\n");

    QuickSortID(processos, 0, NumProcesso - 1);
    EscreverArquivo( processos, "./processo_ordenado_id.csv");

    QuickSortDataMaisAtual(processos, 0, NumProcesso - 1);
    EscreverArquivo( processos, "./processo_ordenado_data.csv");

    QntdProcessosID_classe(processos, "1727");

    QuantosDias(processos,"405277413");

    printf("\n");

    QntdProcessosID_assunto(processos);

    printf("\n");
    
    QntdAssuntosMultiplos(processos);

    free(processos);
    return 0;
}
