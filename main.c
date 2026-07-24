#include <stdio.h>
#include <stdlib.h>
#include "funcoes_oficina.h"

int main()
{

    Lista_mecanico *lista_mecanico = criarListaMecanico(5);
    Lista_veiculo *lista_veiculo = criarListaVeiculo(5);
    Lista_servico *lista_servico = criarListaServico(5);

    int opcao;

    carregarDadosOficina(lista_mecanico, lista_veiculo, lista_servico, "dados_oficina.bin");

    do
    {

        printf("\n===================================================\n");
        printf("           SISTEMA DE GERENCIA DA OFICINA\n");
        printf("===================================================\n");
        printf("             1 - Gerenciar Mecanicos.               \n");
        printf("             2 - Gerenciar Veiculos.                \n");
        printf("             3 - Gerenciar Ordem de Servico.        \n");
        printf("             4 - Gerar Relatorio em TXT.            \n"); 
        printf("             5 - Sair...                            \n");
        printf("===================================================\n");
        printf("| | | | | | | |  ESCOLHA UMA OPCAO  | | | | | | | |\n\n");
        printf("Escolha: ");
        if (scanf("%d", &opcao) != 1) // scanf quando consegue ler, retorna 1, quando nao, diferente de 1
        {
            opcao = -1; // Forçamos um valor inválido para cair no default do switch
        }

        // 2. Limpamos o buffer imediatamente para o lixo de letras não rodar nos próximos menus
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

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
            gerarRelatorioTxt(lista_mecanico, lista_veiculo, lista_servico); 
            break;
        case 5:
            printf("\n| | | | | | | |   SISTEMA FECHADO   | | | | | | | |\n\n\n\n\n");
            break;
        default:
            printf("\nOpcao Invalida! Escolha Uma Correta!\n\n");
            break;
        }

    } while (opcao != 5); 

    salvarDadosOficina(lista_mecanico, lista_veiculo, lista_servico, "dados_oficina.bin");

    liberarListaMecanico(lista_mecanico);
    liberarListaVeiculo(lista_veiculo);
    liberarListaServico(lista_servico);

    return 0;
}