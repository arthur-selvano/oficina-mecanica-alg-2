#include <stdio.h>
#include <stdlib.h>
#include "funcoes_oficina.h"


int switch_case_crud(char tipo[]){ 
    int opcao;
    
    printf("\n===================================================\n");
    printf("               CRUD de %s\n", tipo);
    printf("===================================================\n");
    printf("             1 - Adicionar %s.            \n", tipo);
    printf("             2 - Alterar %s.              \n", tipo);
    printf("             3 - Consultar %s.            \n", tipo);
    printf("             4 - Remover %s.              \n", tipo);
    printf("             5 - Voltar...                \n");
    printf("===================================================\n");
    printf("| | | | | | | |  ESCOLHA UMA OPCAO  | | | | | | | |\n\n");
    printf("Escolha: ");
    fflush(stdin);
    scanf("%d", &opcao);
    return opcao;
}


void gerenciarMecanico (struct Mecanico *mecanicos, int *qtd_mec){
    int opcao;
    do{
        opcao = switch_case_crud("Mecanico");

        switch (opcao)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            
            if(opcao == 5){
                printf("\n\tVoltando ao Menu Principal...\n");
            }
            break;
        default:
            printf("\nOpcao Invalida! Escolha Uma Correta!\n\n");
            opcao = switch_case_crud("Mecanico");
            break;
        }
    }while(opcao !=5);
}
