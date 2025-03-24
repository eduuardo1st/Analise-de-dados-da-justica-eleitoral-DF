#ifndef FUNC_H
#define FUNC_H

#define NumProcesso 18391

typedef struct processo_t {
    long id;
    long long int numero;
    char data_ajuizamento[40];
    int id_classe;
    int id_assunto;
    int ano_aleicao;
}processo_t;

processo_t *LerArquivo(const char *nomeArquivo);



#endif