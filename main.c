#include <stdio.h>
#include <stdlib.h>
#include "funcoes_oficina.h"

int main()
{

    Lista_mecanico *lista_mecanico = criarListaMecanico(5);
    Lista_veiculo *lista_veiculo = criarListaVeiculo(5);
    Lista_servico *lista_servico = criarListaServico(5);

    int opcao, carregar, salvar;
    do
    {
        printf("\n===================================================\n");
        printf("           Carregar dados\n");
        printf("===================================================\n");
        printf("             1 - Sim.               \n");
        printf("             2 - Nao.                \n");
        printf("===================================================\n");
        printf("| | | | | | | |  ESCOLHA UMA OPCAO  | | | | | | | |\n\n");
        printf("Escolha: ");
        if (scanf("%d", &carregar) != 1) // scanf quando consegue ler, retorna 1, quando nao, diferente de 1
        {
            carregar = -1; // Forçamos um valor inválido para cair no default do switch
        }

    } while (carregar != 1 && carregar != 2);
    if (carregar == 1)
    {
        carregarMecanicos(lista_mecanico, "mecanicos.dat");
    }

    do
    {

        printf("\n===================================================\n");
        printf("           SISTEMA DE GERENCIA DA OFICINA\n");
        printf("===================================================\n");
        printf("             1 - Gerenciar Mecanicos.               \n");
        printf("             2 - Gerenciar Veiculos.                \n");
        printf("             3 - Gerenciar Ordem de Servico.        \n");
        printf("             4 - Sair...                            \n");
        printf("===================================================\n");
        printf("| | | | | | | |  ESCOLHA UMA OPCAO  | | | | | | | |\n\n");
        printf("Escolha: ");
        if (scanf("%d", &opcao) != 1) // scanf quando consegue ler, retorna 1, quando nao, diferente de 1
        {
            opcao = -1; // Forçamos um valor inválido para cair no default do switch
        }

        // 2. Limpamos o buffer imediatamente para o lixo de letras não rodar nos próximos menus
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        switch (opcao)
        {
        case 1:
            gerenciarMecanicos(lista_mecanico, lista_servico);
            break;
        case 2:
            gerenciarVeiculos(lista_veiculo, lista_servico);
            break;
        case 3:
            gerenciarServicos(lista_servico, lista_mecanico, lista_veiculo);
            break;
        case 4:
            printf("\n| | | | | | | |   SISTEMA FECHADO   | | | | | | | |\n\n\n\n\n");
            break;
        default:
            printf("\nOpcao Invalida! Escolha Uma Correta!\n\n");
            break;
        }

    } while (opcao != 4);

     do
    {
        printf("\n===================================================\n");
        printf("           Salvar dados\n");
        printf("===================================================\n");
        printf("             1 - Sim.               \n");
        printf("             2 - Nao.                \n");
        printf("===================================================\n");
        printf("| | | | | | | |  ESCOLHA UMA OPCAO  | | | | | | | |\n\n");
        printf("Escolha: ");
        if (scanf("%d", &salvar) != 1) // scanf quando consegue ler, retorna 1, quando nao, diferente de 1
        {
            salvar = -1; // Forçamos um valor inválido para cair no default do switch
        }

    } while (salvar != 1 && salvar != 2);
    if (salvar == 1)
    {
        salvarMecanicos(lista_mecanico, "mecanicos.dat");
    }


    liberarListaMecanico(lista_mecanico);
    liberarListaVeiculo(lista_veiculo);
    liberarListaServico(lista_servico);

    return 0;
}