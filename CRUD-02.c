#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

// ==================== ESTRUTURAS ====================

struct Mecanico {
    int id_mecanico;
    char nome[50];
    char especialidade[50];
    float salario;
};

struct Veiculo {
    char placa_veiculo[10];
    char modelo[50];
    int ano;
    char telefone_dono[15];
};

struct Ordem_Servico {
    int numero_os;
    int id_mecanico;
    char placa_veiculo[10];
    char data_servico[15];
    float valor_total;
};

// ==================== CRUD MECÂNICOS ====================

void cadastrarMecanico(struct Mecanico mecanicos[], int *qtd) {

    if (*qtd >= MAX) {
        printf("\nLimite de mecanicos atingido!\n");
        return;
    }

    printf("\nID do mecanico: ");
    scanf("%d", &mecanicos[*qtd].id_mecanico);

    printf("Nome: ");
    scanf(" %[^\n]", mecanicos[*qtd].nome);

    printf("Especialidade: ");
    scanf(" %[^\n]", mecanicos[*qtd].especialidade);

    printf("Salario: ");
    scanf("%f", &mecanicos[*qtd].salario);

    (*qtd)++;

    printf("\nMecanico cadastrado com sucesso!\n");
}

void listarMecanicos(struct Mecanico mecanicos[], int qtd) {

    if (qtd == 0) {
        printf("\nNenhum mecanico cadastrado.\n");
        return;
    }

    printf("\n=========== MECANICOS ===========\n");

    for (int i = 0; i < qtd; i++) {

        printf("\nID: %d", mecanicos[i].id_mecanico);
        printf("\nNome: %s", mecanicos[i].nome);
        printf("\nEspecialidade: %s", mecanicos[i].especialidade);
        printf("\nSalario: R$ %.2f\n", mecanicos[i].salario);
    }
}

void consultarMecanico(struct Mecanico mecanicos[], int qtd) {

    int id;

    printf("\nDigite o ID do mecanico: ");
    scanf("%d", &id);

    for (int i = 0; i < qtd; i++) {

        if (mecanicos[i].id_mecanico == id) {

            printf("\nID: %d", mecanicos[i].id_mecanico);
            printf("\nNome: %s", mecanicos[i].nome);
            printf("\nEspecialidade: %s", mecanicos[i].especialidade);
            printf("\nSalario: R$ %.2f\n", mecanicos[i].salario);

            return;
        }
    }

    printf("\nMecanico nao encontrado.\n");
}

void alterarMecanico(struct Mecanico mecanicos[], int qtd) {

    int id;

    printf("\nDigite o ID do mecanico: ");
    scanf("%d", &id);

    for (int i = 0; i < qtd; i++) {

        if (mecanicos[i].id_mecanico == id) {

            printf("Novo nome: ");
            scanf(" %[^\n]", mecanicos[i].nome);

            printf("Nova especialidade: ");
            scanf(" %[^\n]", mecanicos[i].especialidade);

            printf("Novo salario: ");
            scanf("%f", &mecanicos[i].salario);

            printf("\nMecanico alterado com sucesso!\n");
            return;
        }
    }

    printf("\nMecanico nao encontrado.\n");
}

void removerMecanico(struct Mecanico mecanicos[], int *qtd) {

    int id;

    printf("\nDigite o ID do mecanico: ");
    scanf("%d", &id);

    for (int i = 0; i < *qtd; i++) {

        if (mecanicos[i].id_mecanico == id) {

            for (int j = i; j < *qtd - 1; j++) {
                mecanicos[j] = mecanicos[j + 1];
            }

            (*qtd)--;

            printf("\nMecanico removido com sucesso!\n");
            return;
        }
    }

    printf("\nMecanico nao encontrado.\n");
}

// ==================== CRUD VEÍCULOS ====================

void cadastrarVeiculo(struct Veiculo veiculos[], int *qtd) {

    if (*qtd >= MAX) {
        printf("\nLimite de veiculos atingido!\n");
        return;
    }

    printf("\nPlaca: ");
    scanf("%9s", veiculos[*qtd].placa_veiculo);

    printf("Modelo: ");
    scanf(" %[^\n]", veiculos[*qtd].modelo);

    printf("Ano: ");
    scanf("%d", &veiculos[*qtd].ano);

    printf("Telefone do proprietario: ");
    scanf("%14s", veiculos[*qtd].telefone_dono);

    (*qtd)++;

    printf("\nVeiculo cadastrado com sucesso!\n");
}

void listarVeiculos(struct Veiculo veiculos[], int qtd) {

    if (qtd == 0) {
        printf("\nNenhum veiculo cadastrado.\n");
        return;
    }

    printf("\n=========== VEICULOS ===========\n");

    for (int i = 0; i < qtd; i++) {

        printf("\nPlaca: %s", veiculos[i].placa_veiculo);
        printf("\nModelo: %s", veiculos[i].modelo);
        printf("\nAno: %d", veiculos[i].ano);
        printf("\nTelefone do Proprietario: %s\n",
               veiculos[i].telefone_dono);
    }
}

void consultarVeiculo(struct Veiculo veiculos[], int qtd) {

    char placa[10];

    printf("\nDigite a placa do veiculo: ");
    scanf("%9s", placa);

    for (int i = 0; i < qtd; i++) {

        if (strcmp(veiculos[i].placa_veiculo, placa) == 0) {

            printf("\nPlaca: %s", veiculos[i].placa_veiculo);
            printf("\nModelo: %s", veiculos[i].modelo);
            printf("\nAno: %d", veiculos[i].ano);
            printf("\nTelefone do Proprietario: %s\n",
                   veiculos[i].telefone_dono);

            return;
        }
    }

    printf("\nVeiculo nao encontrado.\n");
}

void alterarVeiculo(struct Veiculo veiculos[], int qtd) {

    char placa[10];

    printf("\nDigite a placa do veiculo: ");
    scanf("%9s", placa);

    for (int i = 0; i < qtd; i++) {

        if (strcmp(veiculos[i].placa_veiculo, placa) == 0) {

            printf("Novo modelo: ");
            scanf(" %[^\n]", veiculos[i].modelo);

            printf("Novo ano: ");
            scanf("%d", &veiculos[i].ano);

            printf("Novo telefone do proprietario: ");
            scanf("%14s", veiculos[i].telefone_dono);

            printf("\nVeiculo alterado com sucesso!\n");
            return;
        }
    }

    printf("\nVeiculo nao encontrado.\n");
}

void removerVeiculo(struct Veiculo veiculos[], int *qtd) {

    char placa[10];

    printf("\nDigite a placa do veiculo: ");
    scanf("%9s", placa);

    for (int i = 0; i < *qtd; i++) {

        if (strcmp(veiculos[i].placa_veiculo, placa) == 0) {

            for (int j = i; j < *qtd - 1; j++) {
                veiculos[j] = veiculos[j + 1];
            }

            (*qtd)--;

            printf("\nVeiculo removido com sucesso!\n");
            return;
        }
    }

    printf("\nVeiculo nao encontrado.\n");
}

// ==================== MENU CRUD ====================

int menuCRUD(char tipo[]) {

    int opcao;

    do {

        printf("\n=========================================\n");
        printf("           CRUD DE %s\n", tipo);
        printf("=========================================\n");
        printf("1 - Adicionar\n");
        printf("2 - Alterar\n");
        printf("3 - Consultar\n");
        printf("4 - Remover\n");
        printf("5 - Listar\n");
        printf("6 - Voltar\n");
        printf("=========================================\n");
        printf("Escolha: ");

        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 6)
            return opcao;

        printf("\nOpcao invalida!\n");

    } while (1);
}

// ==================== GERENCIAR MECÂNICOS ====================

void gerenciarMecanicos(struct Mecanico mecanicos[], int *qtd) {

    int opcao;

    do {

        opcao = menuCRUD("MECANICOS");

        switch (opcao) {

            case 1:
                cadastrarMecanico(mecanicos, qtd);
                break;

            case 2:
                alterarMecanico(mecanicos, *qtd);
                break;

            case 3:
                consultarMecanico(mecanicos, *qtd);
                break;

            case 4:
                removerMecanico(mecanicos, qtd);
                break;

            case 5:
                listarMecanicos(mecanicos, *qtd);
                break;

            case 6:
                printf("\nVoltando ao menu principal...\n");
                break;
        }

    } while (opcao != 6);
}

// ==================== GERENCIAR VEÍCULOS ====================

void gerenciarVeiculos(struct Veiculo veiculos[], int *qtd) {

    int opcao;

    do {

        opcao = menuCRUD("VEICULOS");

        switch (opcao) {

            case 1:
                cadastrarVeiculo(veiculos, qtd);
                break;

            case 2:
                alterarVeiculo(veiculos, *qtd);
                break;

            case 3:
                consultarVeiculo(veiculos, *qtd);
                break;

            case 4:
                removerVeiculo(veiculos, qtd);
                break;

            case 5:
                listarVeiculos(veiculos, *qtd);
                break;

            case 6:
                printf("\nVoltando ao menu principal...\n");
                break;
        }

    } while (opcao != 6);
}

// ==================== MAIN ====================

int main() {

    struct Mecanico mecanicos[MAX];
    struct Veiculo veiculos[MAX];
    struct Ordem_Servico ordens[MAX];

    int qtdMecanicos = 0;
    int qtdVeiculos = 0;
    int opcao;

    do {

        printf("\n===================================================\n");
        printf("           SISTEMA DE GERENCIA DA OFICINA\n");
        printf("===================================================\n");
        printf("1 - Gerenciar Mecanicos\n");
        printf("2 - Gerenciar Veiculos\n");
        printf("3 - Gerenciar Ordem de Servico\n");
        printf("4 - Sair\n");
        printf("===================================================\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                gerenciarMecanicos(mecanicos, &qtdMecanicos);
                break;

            case 2:
                gerenciarVeiculos(veiculos, &qtdVeiculos);
                break;

            case 3:
                printf("\nModulo de Ordem de Servico em desenvolvimento.\n");
                break;

            case 4:
                printf("\nSistema encerrado.\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 4);

    return 0;
}
