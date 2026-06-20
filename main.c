#include <stdio.h>
#include <stdlib.h>
#include "funcoes_oficina.h"


int main (){
    
    struct Mecanico mecanicos[5];
    struct Veiculo veiculos[5];
    struct Ordem_Servico ordem_servico[5];

    int opcao;
    int qtd_mecanicos = 0;

    do{
        printf("\n===================================================\n");
        printf("           SISTEMA DE GERENCIA DA OFICINA\n");
        printf("===================================================\n");
        printf("             1 - Gerenciar Mecanicos.               \n");
        printf("             2 - Gerenciar Veiculos.                \n");
       //printf("             3 - Gerenciar Ordem de Servico.        \n");
        printf("             4 - Sair...                            \n");
        printf("===================================================\n");
        printf("| | | | | | | |  ESCOLHA UMA OPCAO  | | | | | | | |\n\n");
        printf("Escolha: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            gerenciarMecanico(mecanicos, &qtd_mecanicos);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            printf("\n| | | | | | | |   SISTEMA FECHADO   | | | | | | | |\n\n\n\n\n");
            break;
        default:
            printf("\nOpcao Invalida! Escolha Uma Correta!\n\n");
            break;
        }

    }while(opcao != 4);

    system("pause");
    return 0;
}