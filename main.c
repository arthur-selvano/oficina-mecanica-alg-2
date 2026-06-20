#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "funcoes_oficina.c"

int main() {
    // Declaração dos arrays e contadores
    struct Mecanico mecanicos[5];
    int qtdMecanicos = 0;

    // Reservado para futuras implementações
    // struct Veiculo veiculos[5];
    // int qtdVeiculos = 0;

    int opcao;

    do {
        printf("\n===================================================\n");
        printf("           SISTEMA DE GERENCIA DA OFICINA\n");
        printf("===================================================\n");
        printf("             1 - Gerenciar Mecanicos.               \n");
        printf("             2 - Gerenciar Veiculos.                \n");
        printf("             3 - Sair.                              \n");
        printf("===================================================\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada invalida!\n");
            break;
        }

        switch (opcao) {
            case 1:
                gerenciarMecanicos(mecanicos, &qtdMecanicos);
                break;
            case 2:
                printf("\nModulo de Veiculos em desenvolvimento\n");
                break;
            case 3:
                printf("\nSaindo do sistema.\n");
                break;
            default:
                printf("\nOpcao Invalida!\n");
        }
    } while(opcao != 3);

    return 0;
}