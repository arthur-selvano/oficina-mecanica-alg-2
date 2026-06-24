#include <stdio.h>
#include <stdlib.h>
#include "funcoes_oficina.h"
#include "CRUD_mecanico.h"

int switch_case_crud(char tipo[])
{
    int opcao;

    printf("\n===================================================\n");
    printf("               CRUD de %s\n", tipo);
    printf("===================================================\n");
    printf("             1 - Adicionar %s.            \n", tipo);
    printf("             2 - Alterar %s.              \n", tipo);
    printf("             3 - Consultar %s.            \n", tipo);
    printf("             4 - Remover %s.              \n", tipo);
    printf("             5 - Listar %s.              \n", tipo);
    printf("             6 - Voltar...                \n");
    printf("===================================================\n");
    printf("| | | | | | | |  ESCOLHA UMA OPCAO  | | | | | | | |\n\n");
    printf("Escolha: ");
    scanf("%d", &opcao);
    return opcao;
}

void gerenciarMecanicos(Lista_mecanico *lista_mec)
{

    int opcao;

    do
    {
        opcao = switch_case_crud("Mecanicos");

        switch (opcao)
        {

        case 1:
            cadastrarMecanico(lista_mec);
            break;

        case 2:
            alterarMecanico(lista_mec);
            break;

        case 3:
            consultarMecanico(lista_mec);
            break;
        case 4:
            removerMecanico(lista_mec);
            break;

        case 5:
            listarMecanicos(lista_mec);
            break;

        case 6:

            printf("\n\tVoltando ao Menu Principal...\n");
            break;
        default:
            printf("\nOpcao Invalida! Escolha Uma Correta!\n\n");
            opcao = switch_case_crud("Mecanicos");
            break;
        }
    } while (opcao != 6);
}

void gerenciarVeiculos(Lista_veiculo *lista_veiculos)
{

    int opcao;

    do
    {

        opcao = switch_case_crud("Veiculos");

        switch (opcao)
        {

        case 1:
            cadastrarVeiculo(lista_veiculos);
            break;

        case 2:
            alterarVeiculo(lista_veiculos);
            break;

        case 3:
            consultarVeiculo(lista_veiculos);
            break;

        case 4:
            removerVeiculo(lista_veiculos);
            break;

        case 5:
            listarVeiculos(lista_veiculos);
            break;

        case 6:
            printf("\nVoltando ao menu principal...\n");
            break;
        default:
            printf("\nOpcao Invalida! Escolha Uma Correta!\n\n");
            opcao = switch_case_crud("Veiculos");
            break;
        }

    } while (opcao != 6);
}

Lista_servico *criarListaServico(int tamanho)
{
    Lista_servico *lista_servico = malloc(sizeof(Lista_servico));
    lista_servico->qtd_servicos = 0;
    lista_servico->qtd_max = tamanho;
    lista_servico->ordem_servicos = malloc(tamanho * sizeof(Ordem_servico));

    if (lista_servico == NULL)
    {
        printf("\nMemoria insuficiente!\n");
        return NULL;
    }
    return lista_servico;
}

void liberarListaServico(Lista_servico *lista_servico)
{
    free(lista_servico->ordem_servicos);
    free(lista_servico);
}