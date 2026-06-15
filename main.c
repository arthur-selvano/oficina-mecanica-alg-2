#include <stdio.h>
#include <stdlib.h>

struct Mecanico{
    int id_mecanico;
    char nome[50];
    char especialidade[50];
    float salario;
};

struct Veiculo{
    char placa_veiculo[10];
    char modelo[50];
    int ano;
    char telefone_dono[15];
};

struct Ordem_Servico{
    int numero_os;
    int id_mecanico;
    char placa_veiculo[10];
    char data_servico[15];
    float valor_total;
};

/*
Pensei em utilizar uma funcao para mostrar o menu de todos os CRUDS, 
essa esta retornando a opcao, mas pode ser alterada para ela mesma puxar a funcao
que realiza os CRUD, assim tirando o seu retorno.
*/


int switch_case_crud(char tipo[]){ 
    int opcao;
    do{
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

        switch (opcao)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            
            if(opcao == 5){
                printf("\n\tVoltando ao Menu Principal...\n");
            }
            return opcao;
        default:
            printf("\nOpcao Invalida! Escolha Uma Correta!\n\n");
            break;
        }
    }while(opcao !=5);    
}

int main (){
    struct Mecanico mecanicos[5];
    struct Veiculo veiculos[5];
    struct Ordem_Servico ordem_servico[5];

    int opcao, lala;

    do{
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
        fflush(stdin);
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            lala = switch_case_crud("Mecanicos");
            break;
        case 2:
            lala = switch_case_crud("Veiculos");
            break;
        case 3:
            lala = switch_case_crud("Ord. Servico");
            break;
        case 4:
            printf("\n| | | | | | | |   SISTEMA FECHADO   | | | | | | | |\n\n\n\n\n");
            break;
        default:
            printf("\nOpcao Invalida! Escolha Uma Correta!\n\n");
            break;
        }

    }while(opcao != 4);

    system("pause");
    return 0;
}