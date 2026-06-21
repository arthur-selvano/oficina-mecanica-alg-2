#include <stdio.h>
#include <stdlib.h>
#include "funcoes_oficina.h"

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
    printf("             5 - Voltar...                \n");
    printf("===================================================\n");
    printf("| | | | | | | |  ESCOLHA UMA OPCAO  | | | | | | | |\n\n");
    printf("Escolha: ");
    fflush(stdin);
    scanf("%d", &opcao);
    return opcao;
}

void gerenciarMecanico(Lista_mecanico *lista_mec)
{
    int opcao;
    do
    {
        opcao = switch_case_crud("Mecanico");

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

            if (opcao == 5)
            {
                printf("\n\tVoltando ao Menu Principal...\n");
            }
            break;
        default:
            printf("\nOpcao Invalida! Escolha Uma Correta!\n\n");
            opcao = switch_case_crud("Mecanico");
            break;
        }
    } while (opcao != 5);
}

//===========================================================================
// FUNÇÃO 1 CADASTRO_MECANICO;

void cadastrarMecanico(Lista_mecanico *lista_mec)
{
    int *qtd = &lista_mec->qtd_mec;

    printf("\n====== CADASTRO DE MECANICO ======\n");

    if (*qtd >= lista_mec->qtd_max)
    {
        printf("\nErro: Limite maximo de %d mecanicos atingido!\n", lista_mec->qtd_max);
        return;
    }

    int id_teste;

    do
    {
        printf("ID: ");
        scanf("%d", &id_teste);

        if (buscaMecanicoId(lista_mec, id_teste) != NULL)
        {
            printf("Atenção esse ID ja existe!\n\n");
        }

    } while (buscaMecanicoId(lista_mec, id_teste) != NULL);

    lista_mec->mecanicos[*qtd].id_mecanico = id_teste;

    printf("Nome: ");
    scanf(" %[^\n]", lista_mec->mecanicos[*qtd].nome);

    printf("Especialidade: ");
    scanf(" %[^\n]", lista_mec->mecanicos[*qtd].especialidade);

    printf("Salario: ");
    scanf("%f", &lista_mec->mecanicos[*qtd].salario);

    (*qtd)++;
}

//===========================================================================
// FUNÇÃO 2 ALTERAR_MECANICO;
void alterarMecanico(Lista_mecanico *lista_mec)
{

    int id;

    printf("\n====== ALTERAR MECANICO ======\n");
    printf("Digite o ID do mecanico: ");
    scanf("%d", &id);

    Mecanico *mecanico = buscaMecanicoId(lista_mec, id);

    if (mecanico == NULL)
    {
        printf("\nMecanico nao encontrado!\n");
        return;
    }

    printf("\nMecanico encontrado!\n");

    printf("Novo ID: ");
    scanf("%d", &mecanico->id_mecanico);

    printf("Novo nome: ");
    scanf(" %[^\n]", mecanico->nome);

    printf("Nova especialidade: ");
    scanf(" %[^\n]", mecanico->especialidade);

    printf("Novo salario: ");
    scanf("%f", &mecanico->salario);

    printf("\nAtualizado com sucesso!\n");
    return;
}

//===========================================================================
// FUNÇÃO 3 CONSULTAR_MECANICO;

void consultarMecanico(Lista_mecanico *lista_mec)
{

    int id;

    printf("Digite o ID do mecanico: ");
    scanf("%d", &id);

    Mecanico *mecanico = buscaMecanicoId(lista_mec, id);

    if (mecanico == NULL)
    {
        printf("\nMecanico nao encontrado!\n");
        return;
    }

    printf("\nMecanico encontrado!\n");
    printMecanico(mecanico);
}

//===========================================================================
// FUNÇÃO 4 REMOVE_MECANICO;

void removerMecanico(Lista_mecanico *lista_mec)
{
    int *qtd = &lista_mec->qtd_mec;
    int id;

    printf("\n====== REMOVER MECANICO ======\n");
    printf("Digite o ID do mecanico: ");
    scanf("%d", &id);

    Mecanico *mecanico = buscaMecanicoId(lista_mec, id);

    if (mecanico == NULL)
    {
        printf("\nMecanico nao encontrado!\n");
        return;
    }

    for (int i = 0; i < *qtd; i++)
    {
        if (lista_mec->mecanicos[i].id_mecanico == id)
        {

            for (int j = i; j < (*qtd - 1); j++)
            {
                lista_mec->mecanicos[j] = lista_mec->mecanicos[j + 1];
            }
            (*qtd)--;
            printf("\nMecanico removido com sucesso!\n");
        }
    }
}

Lista_mecanico *criarListaMecanico(int tamanho)
{
    Lista_mecanico *lista_mec = malloc(sizeof(Lista_mecanico));
    lista_mec->qtd_mec = 0;
    lista_mec->qtd_max = tamanho;
    lista_mec->mecanicos = malloc(tamanho * sizeof(Mecanico));

    if (lista_mec == NULL)
    {
        printf("\nMemoria insuficiente!\n");
        return NULL;
    }
    return lista_mec;
}

Lista_veiculo *criarListaVeiculo(int tamanho)
{
    Lista_veiculo *lista_veiculo = malloc(sizeof(Lista_veiculo));
    lista_veiculo->qtd_veiculos = 0;
    lista_veiculo->qtd_max = tamanho;
    lista_veiculo->veiculos = malloc(tamanho * sizeof(Veiculo));

    if (lista_veiculo == NULL)
    {
        printf("\nMemoria insuficiente!\n");
        return NULL;
    }
    return lista_veiculo;
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

void printMecanico(Mecanico *mecanico)
{
    printf("\nID: %d\n", mecanico->id_mecanico);
    printf("Nome: %s\n", mecanico->nome);
    printf("Especialidade: %s\n", mecanico->especialidade);
    printf("Salario: %.2f\n", mecanico->salario);
}

Mecanico *buscaMecanicoId(Lista_mecanico *lista_mec, int id_mecanico) // busca mecanico
{
    if (lista_mec->qtd_mec == 0)
    {
        return NULL;
    }

    for (int i = 0; i < lista_mec->qtd_mec; i++)
    {
        if (lista_mec->mecanicos[i].id_mecanico == id_mecanico)
        {
            return &lista_mec->mecanicos[i];
        }
    }

    return NULL;
}

void liberarListaMecanico(Lista_mecanico *lista_mec)
{
    free(lista_mec->mecanicos);
    free(lista_mec);
}

void liberarListaVeiculo(Lista_veiculo *lista_veiculo)
{
    free(lista_veiculo->veiculos);
    free(lista_veiculo);
}

void liberarListaServico(Lista_servico *lista_servico)
{
    free(lista_servico->ordem_servicos);
    free(lista_servico);
}