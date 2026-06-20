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
            cadastrarMecanico( mecanicos, qtd_mec);
            break;
        case 2:
            alterarMecanico(mecanicos,*qtd_mec);
            break;
        case 3:
            consultarMecanico(mecanicos, *qtd_mec);
            break;
        case 4:
            removerMecanico(mecanicos, qtd_mec);
            break;
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


//===========================================================================
//FUNÇÃO 1 CADASTRO_MECANICO;

void cadastrarMecanico(struct Mecanico* mecanicos, int* qtd){

    printf("\n====== CADASTRO DE MECANICO ======\n");

    if(*qtd >= 5){
        printf("\nErro: Limite maximo de 5 mecanicos atingido!\n");
    }else{
        int id_teste;
        int i;
        int id_repetido=0;

        do{
            printf("ID: ");
            scanf("%d", &id_teste);

            for(i= 0; i < *qtd; i++ ){
                if(mecanicos[i].id_mecanico == id_teste){
                    printf("Atenção esse ID ja existe!\n\n");
                    id_repetido=1;
                    break;
                }
            }
        }while(id_repetido == 1);

        mecanicos[*qtd].id_mecanico= id_teste;

        printf("Nome: ");
        scanf(" %[^\n]", mecanicos[*qtd].nome);

        printf("Especialidade: ");
        scanf(" %[^\n]", mecanicos[*qtd].especialidade);

        printf("Salario: ");
        scanf("%f", &mecanicos[*qtd].salario);
        
        (*qtd)++;
    }
}


//===========================================================================
//FUNÇÃO 2 ALTERAR_MECANICO;
void alterarMecanico(struct Mecanico *mecanicos, int qtd){

int id;
int temp=0;

    printf("\n====== ALTERAR MECANICO ======\n");
    printf("Digite o ID do mecanico: ");
    scanf("%d", &id);

    for(int i = 0; i < qtd; i++){

        if(mecanicos[i].id_mecanico == id){
            temp=1;

            printf("\nMecanico encontrado!\n");

            printf("Novo ID: ");
            scanf("%d", &mecanicos[i].id_mecanico);

            printf("Novo nome: ");
            scanf(" %[^\n]", mecanicos[i].nome);
            
            printf("Nova especialidade: ");
            scanf(" %[^\n]", mecanicos[i].especialidade);
            
            printf("Novo salario: ");
            scanf("%f", &mecanicos[i].salario);

            printf("\nAtualizado com sucesso!\n");
            break;
        }
    }

    if(temp == 0){
        printf("\nMecanico nao encontrado!\n");

    }
}


//===========================================================================
//FUNÇÃO 3 CONSULTAR_MECANICO;

void consultarMecanico(struct Mecanico mecanicos[], int qtd){

    int id;

    printf("Digite o ID do mecanico: ");
    scanf("%d", &id);

    for(int i = 0; i < qtd; i++){

        if(mecanicos[i].id_mecanico == id){
            printf("\nID: %d\n", mecanicos[i].id_mecanico);
            printf("Nome; %s\n", mecanicos[i].nome);
            printf("Especialidade: %s\n", mecanicos[i]. especialidade);
            printf("Salario: %.2f\n", mecanicos[i].salario);

        }
    }
}


//===========================================================================
//FUNÇÃO 4 REMOVE_MECANICO;

void removerMecanico(struct Mecanico mecanicos[], int *qtd){

    int id;
    int temp=0;

    printf("\n====== REMOVER MECANICO ======\n");
    printf("Digite o ID do mecanico: ");
    scanf("%d", &id);

    for(int i = 0; i < *qtd; i++){

        if(mecanicos[i].id_mecanico == id){
            temp=1;

            for(int j = i; j < (*qtd - 1); j++){ 
                mecanicos[j] = mecanicos[j + 1];
            }
            (*qtd)--;
            printf("\nMecanico removido com sucesso!\n");
        }
    }
        if(temp == 0){
            printf("\nMecanico nao encontrado!\n");

    }  

}


