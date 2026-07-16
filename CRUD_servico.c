#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CRUD_servico.h"
#include "funcoes_oficina.h"

void cadastrarServico(Lista_servico *lista_servico, Lista_mecanico *lista_mec, Lista_veiculo *lista_veiculo)
{

    if (lista_servico->qtd_servicos >= lista_servico->qtd_max)
    {
        int nova_capacidade = lista_servico->qtd_max * 2;

        Ordem_servico *temporario = realloc(
            lista_servico->ordem_servicos,
            nova_capacidade * sizeof(Ordem_servico)
        );

        if (temporario == NULL)
        {
            printf("\nErro: memoria insuficiente!\n");
            return;
        }

        lista_servico->ordem_servicos = temporario;
        lista_servico->qtd_max = nova_capacidade;
    }

    Ordem_servico *NovoServico = &lista_servico->ordem_servicos[lista_servico->qtd_servicos];

    printf("\n====== CADASTRO DE OD. SERVICO ======\n");

    NovoServico->id_mecanico = validarID(lista_mec);
    validarPlaca(lista_veiculo, NovoServico->placa_veiculo);
    NovoServico->numero_os = validarOS(lista_servico);

    printf("Data do serviço (DD/MM/AAAA): ");
    scanf("%14s", NovoServico->data_servico);

    printf("Servico realizado: ");
    scanf(" %[^\n]", NovoServico->servico_realizado);

    printf("Valor total: ");
    scanf("%f", &NovoServico->valor_total);

    (lista_servico->qtd_servicos)++;

    printf("\nOrdem de servico cadastrada com sucesso!\n");
}

void alterarServico(Lista_servico *lista_servico, Lista_mecanico *lista_mec, Lista_veiculo *lista_veiculo)
{

    int os;

    printf("\n Digite o numero OS: ");
    scanf("%d", &os);

    Ordem_servico *Servico = buscaOS(lista_servico, os);

    if (Servico == NULL)
    {
        printf("Numero OS nao encontrado!\n");
        return;
    }

    Servico->id_mecanico = validarID(lista_mec);
    validarPlaca(lista_veiculo, Servico->placa_veiculo);

    printf("Data do serviço (DD/MM/AAAA): ");
    scanf("%14s", Servico->data_servico);

    printf("Servico realizado: ");
    scanf(" %[^\n]", Servico->servico_realizado);

    printf("Valor total: ");
    scanf("%f", &Servico->valor_total);
}

void removerServico(Lista_servico *lista_servico)
{

    int os;

    printf("\nNumero OS: ");
    scanf("%d", &os);

    if (buscaOS(lista_servico, os) == NULL)
    {
        printf("Numero OS nao encontrado!\n");
        return;
    }

    for (int i = 0; i < lista_servico->qtd_servicos; i++)
    {
        if (lista_servico->ordem_servicos[i].numero_os == os)
        { 
            //correção ARTHUR F; j=0 para j=i:
            for (int j = i; j < lista_servico->qtd_servicos - 1; j++)
            {
                lista_servico->ordem_servicos[j] = lista_servico->ordem_servicos[j + 1];
            }
            (lista_servico->qtd_servicos)--;
            printf("\nOrdem de servico removida com sucesso!\n");
            return;
        }
    }
}

void consultarServico(Lista_servico *lista_servico)
{

    int os;

    printf("\nNumero OS: ");
    scanf("%d", &os);

    Ordem_servico *Servico = buscaOS(lista_servico, os);

    if (Servico == NULL)
    {
        printf("\nOrdem de servico nao encontrada!\n");
        return;
    }
    printServico(Servico);
}

void listarServico(Lista_servico *lista_servico, Lista_mecanico *lista_mec, Lista_veiculo *lista_veiculo)
{
    if (lista_servico->qtd_servicos == 0)
    {
        printf("\nNao ha ordens de servicos!\n");
        return;
    }

    int opcao;
    printf("\n====== FILTRAR ORDENS DE SERVICO ======\n");
    printf("1 - Filtrar por ID do Mecanico\n");
    printf("2 - Filtrar por Placa do Veiculo\n");
    printf("3 - Filtrar por Data do Servico\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    int id, encontrado = 0;
    char placa[10];
    char data[15];

    switch (opcao)
    {
    case 1:
        printf("\nID: ");
        scanf("%d", &id);
        break;
    case 2:
        printf("\nPlaca do Veiculo: ");
        scanf("%9s", placa);
        placaMaiusculo(placa);
        break;
    case 3:
        printf("\nData do Serviço (DD/MM/AAAA): ");
        scanf("%14s", data);
        break;

    default:
        printf("Opcao Invalida!\n");
        return;
    }

    printf("=========== RESULTADO ===========");

    for (int i = 0; i < lista_servico->qtd_servicos; i++)
    {
        Ordem_servico *servico = &lista_servico->ordem_servicos[i];

        if (servico == NULL)
        {
            printf("\nNao ha registro de servico!\n");
            return;
        }

        int escolha = 0;

        if ((opcao == 1) && (servico->id_mecanico == id))
        {
            escolha = 1;
        }
        if ((opcao == 2) && (strcmp(servico->placa_veiculo, placa) == 0))
        {
            escolha = 1;
        }
        if ((opcao == 3) && (strcmp(servico->data_servico, data) == 0))
        {
            escolha = 1;
        }

        if (escolha)
        {
            encontrado = 1;
            Mecanico *mecanico = buscaMecanicoId(lista_mec, servico->id_mecanico);
            Veiculo *veiculo = buscaVeiculoPlaca(lista_veiculo, servico->placa_veiculo);

            printf("\nNumero OS: %d", servico->numero_os);
            printf("\nData: %s", servico->data_servico);
            //Correção: Arthur F: Verificação se o veiculo ou mecanico existe.
            if(mecanico != NULL){
                printf("\nMecanico: %s", mecanico->nome);
            }else{
                printf("\n Mecanico: [Não encontrado ou Removido]\n");
            }
            if(veiculo != NULL){
                printf("\nVeiculo: %s", veiculo->modelo);
            }else{
                printf("\n Veiculo : [não encontrado ou Removido]\n");
            }

            printf("\nServico Realizado: %s", servico->servico_realizado);
            printf("\n=================================");
        }
    }
    if (!encontrado)
    {
        printf("\nNao ha registro!\n");
    }
}

void printServico(Ordem_servico *servico)
{

    printf("\nID Mecanico: %d", servico->id_mecanico);
    printf("\nPlaca Veiculo: %s", servico->placa_veiculo);
    printf("\nNumero OS: %d", servico->numero_os);
    printf("\nData do Servico: %s", servico->data_servico);
    printf("\nServico Realizado: %s", servico->servico_realizado);
    printf("\nValor Total: R$%.2f", servico->valor_total);
}

Ordem_servico *buscaOS(Lista_servico *lista_servico, int os)
{

    if (lista_servico->qtd_servicos == 0)
    {
        return NULL;
    }
    for (int i = 0; i < lista_servico->qtd_servicos; i++)
    {
        if (lista_servico->ordem_servicos[i].numero_os == os)
        {
            return &lista_servico->ordem_servicos[i];
        }
    }
    return NULL;
}

int validarID(Lista_mecanico *lista_mec)
{

    int id;
    do
    {
        printf("=========== ID'S DISPONIVEIS ===========\n");
        for (int i = 0; i < lista_mec->qtd_mec; i++)
        {
            if (i % 3 == 0)
            {
                printf("\n\t");
            }
            printf("- (%d) -", lista_mec->mecanicos[i].id_mecanico);
        }
        printf("\n========================================\n");

        printf("\nID: ");
        scanf("%d", &id);

        if (buscaMecanicoId(lista_mec, id) == NULL)
        {
            printf("Atenção esse ID nao existe!\n\n");
        }

    } while (buscaMecanicoId(lista_mec, id) == NULL);

    return id;
}

void validarPlaca(Lista_veiculo *lista_veiculo, char *endPlaca)
{

    do
    {
        printf("========== PLACAS DISPONIVEIS ==========\n");
        for (int i = 0; i < lista_veiculo->qtd_veiculos; i++)
        {
            if (i % 3 == 0)
            {
                printf("\n");
            }
            printf("- (%s) -", lista_veiculo->veiculos[i].placa_veiculo);
        }
        printf("\n========================================\n");

        printf("\nPlaca: ");
        scanf("%9s", endPlaca);
        placaMaiusculo(endPlaca);

        if (buscaVeiculoPlaca(lista_veiculo, endPlaca) == NULL)
        {
            printf("Atenção essa placa nao existe!\n\n");
        }

    } while (buscaVeiculoPlaca(lista_veiculo, endPlaca) == NULL);
}

int validarOS(Lista_servico *lista_servico)
{

    int os;
    do
    {
        printf("\nNumero OS: ");
        scanf("%d", &os);

        if (buscaOS(lista_servico, os) != NULL)
        {
            printf("Atenção essa OS ja existe!\n\n");
        }

    } while (buscaOS(lista_servico, os) != NULL);
    return os;
}

Lista_servico *criarListaServico(int tamanho)
{
    Lista_servico *lista_servico = malloc(sizeof(Lista_servico));

    if(lista_servico == NULL){

        printf("\n Erro: Memoria insuficiente para Criar lista de servicos\n");
        return NULL;
    }

    lista_servico->qtd_servicos = 0;
    lista_servico->qtd_max = tamanho;

    lista_servico->ordem_servicos = malloc(tamanho * sizeof(Ordem_servico));

    if (lista_servico->ordem_servicos == NULL)
    {
        printf("\nMemoria insuficiente!\n");
        free(lista_servico);
        return NULL;
    }
    return lista_servico;
}

void liberarListaServico(Lista_servico *lista_servico){

    if(lista_servico != NULL){
    free(lista_servico->ordem_servicos);
    free(lista_servico);
    }
}