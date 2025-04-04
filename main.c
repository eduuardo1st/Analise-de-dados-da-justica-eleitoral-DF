#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    processo_t *processos = LerArquivo("./processo_043_202409032338_modificado.csv");
    if (processos == NULL) {
        printf("Erro ao carregar os processos.\n");
        return 1;
    }

    QuickSortID(processos, 0, NumProcesso - 1);

    QuickSortDataMaisAtual(processos, 0, NumProcesso - 1);

    QntdProcessosID_classe(processos, "12554");

    free(processos);
    return 0;
}
