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
    printf("             5 - Listar %s.              \n", tipo);
    printf("             6 - Voltar...                \n");
    printf("===================================================\n");
    printf("| | | | | | | |  ESCOLHA UMA OPCAO  | | | | | | | |\n\n");
    printf("Escolha: ");
    if (scanf("%d", &opcao) != 1)
    {
        opcao = -1; // Se digitar letra, força -1 para cair no default do switch de quem chamou
    }

    // Limpa o buffer do teclado para eliminar as letras ou o 'Enter'
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    return opcao;
}

void gerenciarMecanicos(Lista_mecanico *lista_mec, Lista_servico *lista_servico)
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
            removerMecanico(lista_mec, lista_servico);
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

void gerenciarVeiculos(Lista_veiculo *lista_veiculos, Lista_servico *lista_servico)
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
            removerVeiculo(lista_veiculos, lista_servico);
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

void gerenciarServicos(Lista_servico *lista_servico, Lista_mecanico *lista_mec, Lista_veiculo *lista_veiculos)
{

    int opcao;

    do
    {

        opcao = switch_case_crud("Ordem de Servico");

        switch (opcao)
        {

        case 1:
            cadastrarServico(lista_servico, lista_mec, lista_veiculos);
            break;

        case 2:
            alterarServico(lista_servico, lista_mec, lista_veiculos);
            break;

        case 3:
            consultarServico(lista_servico);
            break;

        case 4:
            removerServico(lista_servico);
            break;

        case 5:
            listarServico(lista_servico, lista_mec, lista_veiculos);
            break;

        case 6:
            printf("\nVoltando ao menu principal...\n");
            break;
        default:
            printf("\nOpcao Invalida! Escolha Uma Correta!\n\n");
            opcao = switch_case_crud("Ordem de Servico");
            break;
        }

    } while (opcao != 6);
}

void salvarDadosOficina(Lista_mecanico *lista_mec, Lista_veiculo *lista_veiculo, Lista_servico *lista_servico, char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "wb");
    if (arquivo == NULL)
    {
        printf("\nErro ao abrir o arquivo para salvar!\n");
        return;
    }

    // 1. Salva a lista de Mecânicos
    fwrite(&lista_mec->qtd_mec, sizeof(int), 1, arquivo);
    fwrite(&lista_mec->qtd_max, sizeof(int), 1, arquivo);
    fwrite(lista_mec->mecanicos, sizeof(Mecanico), lista_mec->qtd_mec, arquivo);

    // 2. Salva a lista de Veículos
    fwrite(&lista_veiculo->qtd_veiculos, sizeof(int), 1, arquivo);
    fwrite(&lista_veiculo->qtd_max, sizeof(int), 1, arquivo);
    fwrite(lista_veiculo->veiculos, sizeof(Veiculo), lista_veiculo->qtd_veiculos, arquivo);

    // 3. Salva a lista de Serviços
    fwrite(&lista_servico->qtd_servicos, sizeof(int), 1, arquivo);
    fwrite(&lista_servico->qtd_max, sizeof(int), 1, arquivo);
    fwrite(lista_servico->ordem_servicos, sizeof(Ordem_servico), lista_servico->qtd_servicos, arquivo);

    fclose(arquivo);
    printf("\nDados da oficina salvos com sucesso!\n");
}

void carregarDadosOficina(Lista_mecanico *lista_mec, Lista_veiculo *lista_veiculo, Lista_servico *lista_servico, char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL)
    {
        printf("\nArquivo de dados nao encontrado. Um novo sera criado ao salvar.\n");
        return;
    }

    // 1. Carrega a lista de Mecânicos
    fread(&lista_mec->qtd_mec, sizeof(int), 1, arquivo);
    fread(&lista_mec->qtd_max, sizeof(int), 1, arquivo);
    lista_mec->mecanicos = realloc(lista_mec->mecanicos, lista_mec->qtd_max * sizeof(Mecanico));
    fread(lista_mec->mecanicos, sizeof(Mecanico), lista_mec->qtd_mec, arquivo);

    // 2. Carrega a lista de Veículos
    fread(&lista_veiculo->qtd_veiculos, sizeof(int), 1, arquivo);
    fread(&lista_veiculo->qtd_max, sizeof(int), 1, arquivo);
    lista_veiculo->veiculos = realloc(lista_veiculo->veiculos, lista_veiculo->qtd_max * sizeof(Veiculo));
    fread(lista_veiculo->veiculos, sizeof(Veiculo), lista_veiculo->qtd_veiculos, arquivo);

    // 3. Carrega a lista de Serviços
    fread(&lista_servico->qtd_servicos, sizeof(int), 1, arquivo);
    fread(&lista_servico->qtd_max, sizeof(int), 1, arquivo);
    lista_servico->ordem_servicos = realloc(lista_servico->ordem_servicos, lista_servico->qtd_max * sizeof(Ordem_servico));
    fread(lista_servico->ordem_servicos, sizeof(Ordem_servico), lista_servico->qtd_servicos, arquivo);

    fclose(arquivo);
    printf("\nDados da oficina carregados com sucesso!\n");
}