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

    int opcao;
    char input[100];

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Ordenar processos por ID e salvar em arquivo\n");
        printf("2 - Ordenar processos por data mais atual e salvar em arquivo\n");
        printf("3 - Quantidade de processos por ID de classe\n");
        printf("4 - Quantos dias desde o inicio do processo (por ID)\n");
        printf("5 - Quantidade de processos por assunto\n");
        printf("6 - Quantidade de processos com multiplos assuntos\n");
        printf("0 - Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Consumir o '\n' do buffer

        switch (opcao) {
            case 1:
                QuickSortID(processos, 0, NumProcesso - 1);
                EscreverArquivo(processos, "./processo_ordenado_id.csv");
                system("cls");
                printf("Processos ordenados por ID salvos em 'processo_ordenado_id.csv'.\n");
                break;

            case 2:
                QuickSortDataMaisAtual(processos, 0, NumProcesso - 1);
                EscreverArquivo(processos, "./processo_ordenado_data.csv");
                system("cls");
                printf("Processos ordenados por data salvos em 'processo_ordenado_data.csv'.\n");
                break;

            case 3:
                printf("Digite o ID da classe: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0';  
                system("cls");
                QntdProcessosID_classe(processos, input);
                break;

            case 4:
                printf("Digite o ID do processo: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0';
                system("cls");
                QuantosDias(processos, input);
                break;

            case 5:
                system("cls");
                QntdProcessosID_assunto(processos);
                break;

            case 6:
                system("cls");
                QntdAssuntosMultiplos(processos);
                break;

            case 0:
                system("cls");
                printf("Encerrando o programa...\n");
                break;

            default:
                system("cls");
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    free(processos);
    return 0;
}

