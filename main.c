#include <stdio.h>
#include <stdlib.h>
#include "funcoes_oficina.h"

int main()
{

    Lista_mecanico *lista_mec = criarListaMecanico(5);
    Lista_veiculo *lista_veiculo = criarListaVeiculo(5);
    Lista_servico *lista_servico = criarListaServico(5);

    int opcao;

    do
    {
        printf("\n===================================================\n");
        printf("           SISTEMA DE GERENCIA DA OFICINA\n");
        printf("===================================================\n");
        printf("             1 - Gerenciar Mecanicos.               \n");
        printf("             2 - Gerenciar Veiculos.                \n");
        // printf("             3 - Gerenciar Ordem de Servico.        \n");
        printf("             3 - Sair...                            \n");
        printf("===================================================\n");
        printf("| | | | | | | |  ESCOLHA UMA OPCAO  | | | | | | | |\n\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            gerenciarMecanicos(lista_mec);
            break;
        case 2:
            gerenciarVeiculos(lista_veiculo);
            break;
        case 3:
            printf("\n| | | | | | | |   SISTEMA FECHADO   | | | | | | | |\n\n\n\n\n");
            break;
        default:
            printf("\nOpcao Invalida! Escolha Uma Correta!\n\n");
            break;
        }

    } while (opcao != 3);
    
    liberarListaMecanico(lista_mec);
    liberarListaVeiculo(lista_veiculo);
    liberarListaServico(lista_servico);

    system("pause");
    return 0;
}