#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CRUD_veiculo.h"

// ==================== ESTRUTURAS ====================

struct Veiculo
{
    char placa_veiculo[10];
    char modelo[50];
    int ano;
    char telefone_dono[15];
};

// ==================== CRUD VEÍCULOS ====================

void cadastrarVeiculo(Lista_veiculo *lista_veiculo)
{

    Veiculo *NovoVeiculo = &lista_veiculo->veiculos[lista_veiculo->qtd_veiculos];

    if (lista_veiculo->qtd_veiculos >= lista_veiculo->qtd_max)
    {
        printf("\nLimite de veiculos atingido!\n");
        return;
    }

    do
    {
        printf("\nPlaca: ");
        scanf("%9s", NovoVeiculo->placa_veiculo);

        if (buscaVeiculoPlaca(lista_veiculo, NovoVeiculo->placa_veiculo) != NULL)
        {
            printf("Atenção essa placa ja existe!\n\n");
        }

    } while (buscaVeiculoPlaca(lista_veiculo, NovoVeiculo->placa_veiculo) != NULL);

    printf("Modelo: ");
    scanf(" %[^\n]", NovoVeiculo->modelo);

    printf("Ano: ");
    scanf("%d", &NovoVeiculo->ano);

    printf("Telefone do proprietario: ");
    scanf("%14s", NovoVeiculo->telefone_dono);

    (lista_veiculo->qtd_veiculos)++;

    printf("\nVeiculo cadastrado com sucesso!\n");
}

void listarVeiculos(Lista_veiculo *lista_veiculo)
{

    if (lista_veiculo->qtd_veiculos == 0)
    {
        printf("\nNenhum veiculo cadastrado.\n");
        return;
    }

    printf("\n=========== VEICULOS ===========\n");

    for (int i = 0; i < lista_veiculo->qtd_veiculos; i++)
    {
        printVeiculo(&lista_veiculo->veiculos[i]);
    }
}

void printVeiculo(Veiculo *veiculo)
{
    printf("\nPlaca: %s", veiculo->placa_veiculo);
    printf("\nModelo: %s", veiculo->modelo);
    printf("\nAno: %d", veiculo->ano);
    printf("\nTelefone do Proprietario: %s\n", veiculo->telefone_dono);
}

void consultarVeiculo(Lista_veiculo *lista_veiculo)
{

    char placa[10];

    printf("\nDigite a placa do veiculo: ");
    scanf("%9s", placa);

    Veiculo *veiculo = buscaVeiculoPlaca(lista_veiculo, placa);

    if (veiculo == NULL)
    {
        printf("\nVeiculo nao encontrado.\n");
        return;
    }

    printVeiculo(veiculo);
}

Veiculo *buscaVeiculoPlaca(Lista_veiculo *lista_veiculo, char placa[10])
{

    for (int i = 0; i < lista_veiculo->qtd_veiculos; i++)
    {

        if (strcmp(lista_veiculo->veiculos[i].placa_veiculo, placa) == 0)
        {
            return &lista_veiculo->veiculos[i];
        }
    }
}

void alterarVeiculo(Lista_veiculo *lista_veiculo)
{

    char placa[10];

    printf("\nDigite a placa do veiculo: ");
    scanf("%9s", placa);

    Veiculo *veiculo = buscaVeiculoPlaca(lista_veiculo, placa);

    if (veiculo == NULL)
    {
        printf("\nVeiculo nao encontrado.\n");
        return;
    }

    printf("Novo modelo: ");
    scanf(" %[^\n]", veiculo->modelo);

    printf("Novo ano: ");
    scanf("%d", &veiculo->ano);

    printf("Novo telefone do proprietario: ");
    scanf("%14s", veiculo->telefone_dono);

    printf("\nVeiculo alterado com sucesso!\n");
}

void removerVeiculo(Lista_veiculo *veiculos)
{

    char placa[10];

    printf("\nDigite a placa do veiculo: ");
    scanf("%9s", placa);

    if (veiculos->qtd_veiculos == 0)
    {
        printf("\nNenhum veiculo cadastrado.\n");
        return;
    }

    if (buscaVeiculoPlaca(veiculos, placa) == NULL)
    {
        printf("\nVeiculo nao encontrado.\n");
        return;
    }

    for (int i = 0; i < veiculos->qtd_veiculos; i++)
    {
        if (strcmp(veiculos->veiculos[i].placa_veiculo, placa) == 0)
        {
            for (int j = i; j < veiculos->qtd_veiculos - 1; j++)
            {
                veiculos->veiculos[j] = veiculos->veiculos[j + 1];
            }
            (veiculos->qtd_veiculos)--;
            printf("\nVeiculo removido com sucesso!\n");
            return;
        }
    }
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

void liberarListaVeiculo(Lista_veiculo *lista_veiculo)
{
    free(lista_veiculo->veiculos);
    free(lista_veiculo);
}
