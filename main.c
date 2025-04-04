#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    processo_t *processos = LerArquivo("./processo_043_202409032338_modificado.csv");
    if (processos == NULL) {
        printf("Erro ao carregar os processos.\n");
        return 1;  // Encerra de forma segura
    }
    printf("Lendo os dados do arquivo:\n");
    for (int i = 0; i < 10; i++) {
        if (strlen(processos[i].id) == 0) {
            break;
        }
        printf("Linha %d:\n", i + 1);
        printf("  ID: %s\n", processos[i].id);
        printf("  Número: %s\n", processos[i].numero);
        printf("  Data de Ajuizamento: %s\n", processos[i].data_ajuizamento);
        printf("  ID Classe: %s\n", processos[i].id_classe);
        printf("  ID Assunto: %s\n", processos[i].id_assunto);
        printf("  Ano Eleição: %s\n", processos[i].ano_aleicao);
        printf("----------------------\n");
    }
    free(processos);  // Liberar memória alocada

    return 0;
}
