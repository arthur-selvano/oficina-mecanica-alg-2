#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// Função auxiliar para comparar datas convertendo DD/MM/AAAA para AAAAMMDD (inteiro)
int converterDataInt(char* data) {
    int d, m, a;
    if (sscanf(data, "%d/%d/%d", &d, &m, &a) == 3) {
        return a * 10000 + m * 100 + d;
    }
    return 0;
}

// Nova função de relatório baseada nos requisitos
void gerarRelatorioTxt(Lista_mecanico *lista_mec, Lista_veiculo *lista_veiculo, Lista_servico *lista_servico)
{
    int opcao;
    
    printf("\n====== GERAR RELATORIO (TXT) ======\n");
    printf("1 - Relatorio por Data de Servico\n");
    printf("2 - Relatorio por Mecanico\n");
    printf("3 - Relatorio por Veiculo\n");
    printf("Escolha uma opcao: ");
    
    if (scanf("%d", &opcao) != 1) {
        opcao = -1;
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    if (opcao < 1 || opcao > 3) {
        printf("\nOpcao Invalida!\n");
        return;
    }

    FILE *arquivo = fopen("relatorio_filtrado.txt", "w");
    if (arquivo == NULL)
    {
        printf("\nErro ao criar o relatorio!\n");
        return;
    }

    // ==========================================================
    // RELATÓRIO 1: POR DATA DE SERVIÇO
    // ==========================================================
    if (opcao == 1) {
        char data_inicial[15];
        printf("Digite a data inicial (DD/MM/AAAA): ");
        scanf("%14s", data_inicial);
        int data_ini_int = converterDataInt(data_inicial);

        fprintf(arquivo, "========================================================================================\n");
        fprintf(arquivo, "                    RELATORIO POR DATA DE SERVICO (A PARTIR DE %s)\n", data_inicial);
        fprintf(arquivo, "========================================================================================\n\n");
        fprintf(arquivo, "| %-4s | %-12s | %-15s | %-20s | %-20s |\n", "OS", "Data", "Valor Total", "Mecanico", "Veiculo (Modelo)");
        fprintf(arquivo, "----------------------------------------------------------------------------------------\n");

        int encontrou = 0;
        for (int i = 0; i < lista_servico->qtd_servicos; i++) {
            Ordem_servico *os = &lista_servico->ordem_servicos[i];
            
            if (converterDataInt(os->data_servico) >= data_ini_int) {
                encontrou = 1;
                Mecanico *mec = buscaMecanicoId(lista_mec, os->id_mecanico);
                Veiculo *vei = buscaVeiculoPlaca(lista_veiculo, os->placa_veiculo);
                
                char nome_mec[50] = "Removido/Inexistente";
                char modelo_vei[50] = "Removido/Inexistente";
                if (mec != NULL) strcpy(nome_mec, mec->nome);
                if (vei != NULL) strcpy(modelo_vei, vei->modelo);

                fprintf(arquivo, "| %-4d | %-12s | R$ %-12.2f | %-20s | %-20s |\n", 
                        os->numero_os, os->data_servico, os->valor_total, nome_mec, modelo_vei);
            }
        }
        if (!encontrou) fprintf(arquivo, "| Nenhuma ordem de servico encontrada a partir desta data.\n");
        fprintf(arquivo, "----------------------------------------------------------------------------------------\n");
        printf("\nRelatorio salvo com sucesso em 'relatorio_filtrado.txt'!\n");
    }

    // ==========================================================
    // RELATÓRIO 2: POR MECÂNICO
    // ==========================================================
    else if (opcao == 2) {
        int id_mec;
        printf("Digite o ID do Mecanico: ");
        scanf("%d", &id_mec);

        Mecanico *mec = buscaMecanicoId(lista_mec, id_mec);
        if (mec == NULL) {
            printf("\nMecanico nao encontrado!\n");
            fclose(arquivo);
            remove("relatorio_filtrado.txt");
            return;
        }

        fprintf(arquivo, "========================================================================================\n");
        fprintf(arquivo, "                               RELATORIO POR MECANICO\n");
        fprintf(arquivo, "========================================================================================\n");
        fprintf(arquivo, "Mecanico: %s | Especialidade: %s\n", mec->nome, mec->especialidade);
        fprintf(arquivo, "----------------------------------------------------------------------------------------\n\n");
        fprintf(arquivo, "| %-4s | %-12s | %-25s | %-35s |\n", "OS", "Data", "Veiculo (Modelo)", "Servico Realizado");
        fprintf(arquivo, "----------------------------------------------------------------------------------------\n");

        int encontrou = 0;
        for (int i = 0; i < lista_servico->qtd_servicos; i++) {
            Ordem_servico *os = &lista_servico->ordem_servicos[i];
            
            if (os->id_mecanico == id_mec) {
                encontrou = 1;
                Veiculo *vei = buscaVeiculoPlaca(lista_veiculo, os->placa_veiculo);
                char modelo_vei[50] = "Removido/Inexistente";
                if (vei != NULL) strcpy(modelo_vei, vei->modelo);

                fprintf(arquivo, "| %-4d | %-12s | %-25s | %-35s |\n", 
                        os->numero_os, os->data_servico, modelo_vei, os->servico_realizado);
            }
        }
        if (!encontrou) fprintf(arquivo, "| Nenhum servico realizado por este mecanico.\n");
        fprintf(arquivo, "----------------------------------------------------------------------------------------\n");
        printf("\nRelatorio salvo com sucesso em 'relatorio_filtrado.txt'!\n");
    }

    // ==========================================================
    // RELATÓRIO 3: POR VEÍCULO
    // ==========================================================
    else if (opcao == 3) {
        char placa[10];
        printf("Digite a Placa do Veiculo: ");
        scanf("%9s", placa);
        placaMaiusculo(placa); 

        Veiculo *vei = buscaVeiculoPlaca(lista_veiculo, placa);
        if (vei == NULL) {
            printf("\nVeiculo nao encontrado!\n");
            fclose(arquivo);
            remove("relatorio_filtrado.txt");
            return;
        }

        fprintf(arquivo, "========================================================================================\n");
        fprintf(arquivo, "                               RELATORIO POR VEICULO\n");
        fprintf(arquivo, "========================================================================================\n");
        fprintf(arquivo, "Placa: %s | Modelo: %s | Ano: %d\n", vei->placa_veiculo, vei->modelo, vei->ano);
        fprintf(arquivo, "----------------------------------------------------------------------------------------\n\n");
        fprintf(arquivo, "| %-4s | %-12s | %-20s | %-40s |\n", "OS", "Data", "Mecanico", "Servico Realizado");
        fprintf(arquivo, "----------------------------------------------------------------------------------------\n");

        int encontrou = 0;
        for (int i = 0; i < lista_servico->qtd_servicos; i++) {
            Ordem_servico *os = &lista_servico->ordem_servicos[i];
            
            if (strcmp(os->placa_veiculo, placa) == 0) {
                encontrou = 1;
                Mecanico *mec = buscaMecanicoId(lista_mec, os->id_mecanico);
                char nome_mec[50] = "Removido/Inexistente";
                if (mec != NULL) strcpy(nome_mec, mec->nome);

                fprintf(arquivo, "| %-4d | %-12s | %-20s | %-40s |\n", 
                        os->numero_os, os->data_servico, nome_mec, os->servico_realizado);
            }
        }
        if (!encontrou) fprintf(arquivo, "| Nenhum historico de servico para este veiculo.\n");
        fprintf(arquivo, "----------------------------------------------------------------------------------------\n");
        printf("\nRelatorio salvo com sucesso em 'relatorio_filtrado.txt'!\n");
    }

    fclose(arquivo);
}