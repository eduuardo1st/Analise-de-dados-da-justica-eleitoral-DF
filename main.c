#include "func.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("teste - ");
    processo_t *processos = LerArquivo("./processo_043_202409032338.csv");
    printf("%ld;%s;%s;%d;%d;%d\n",
         processos[0].id, processos[0].numero, processos[0].data_ajuizamento,
          processos[0].id_classe, processos[0].id_assunto, processos[0].ano_aleicao);


    return 0;
}