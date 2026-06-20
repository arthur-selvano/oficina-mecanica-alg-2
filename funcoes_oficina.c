#include <stdio.h>
#include <string.h>
#include "estruturas.h"

void cadastrarMecanico(struct Mecanico* mecanicos, int* qtd) {
    printf("\nID: ");
    scanf("%d", &mecanicos[*qtd].id_mecanico);
    printf("Nome: ");
    scanf(" %[^\n]", mecanicos[*qtd].nome);
    printf("Especialidade: ");
    scanf(" %[^\n]", mecanicos[*qtd].especialidade);
    printf("Salario: ");
    scanf("%f", &mecanicos[*qtd].salario);
    (*qtd)++;
}

void alterarMecanico(struct Mecanico *mecanicos, int qtd) {
    int id, encontrado = 0;
    printf("Digite o ID: ");
    scanf("%d", &id);
    for(int i = 0; i < qtd; i++) {
        if(mecanicos[i].id_mecanico == id) {
            printf("Novo nome: ");
            scanf(" %[^\n]", mecanicos[i].nome);
            printf("Nova especialidade: ");
            scanf(" %[^\n]", mecanicos[i].especialidade);
            printf("Novo salario: ");
            scanf("%f", &mecanicos[i].salario);
            encontrado = 1;
            break;
        }
    }
    if(!encontrado) printf("\nMecanico nao encontrado!\n");
}

void consultarMecanico(struct Mecanico mecanicos[], int qtd) {
    int id, achou = 0;
    printf("Digite o ID: ");
    scanf("%d", &id);
    for(int i = 0; i < qtd; i++) {
        if(mecanicos[i].id_mecanico == id) {
            printf("Nome: %s | Salario: %.2f\n", mecanicos[i].nome, mecanicos[i].salario);
            achou = 1;
        }
    }
    if(!achou) printf("Nao encontrado.\n");
}

void removerMecanico(struct Mecanico mecanicos[], int *qtd) {
    int id, encontrado = 0;
    printf("Digite o ID para remover: ");
    scanf("%d", &id);
    for(int i = 0; i < *qtd; i++) {
        if(mecanicos[i].id_mecanico == id) {
            for(int j = i; j < (*qtd - 1); j++) mecanicos[j] = mecanicos[j + 1];
            (*qtd)--;
            encontrado = 1;
            break;
        }
    }
    if(!encontrado) printf("Nao encontrado.\n");
}

void gerenciarMecanicos(struct Mecanico mecanicos[], int *qtd) {
    int op;
    do {
        printf("\n--- MENU MECANICOS ---\n1-Cadastrar 2-Alterar 3-Consultar 4-Remover 5-Voltar\nOpcao: ");
        scanf("%d", &op);
        switch(op) {
            case 1: cadastrarMecanico(mecanicos, qtd); break;
            case 2: alterarMecanico(mecanicos, *qtd); break;
            case 3: consultarMecanico(mecanicos, *qtd); break;
            case 4: removerMecanico(mecanicos, qtd); break;
        }
    } while(op != 5);
}