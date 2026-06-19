#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

/*pessoal acho melhor fazer uma bliblioteca mesmo o codigo 
ficou muito poluido com as funções somente da estrutura de
mecanicos mais da uma olhada se tiver alguma coisa ruim me avisem */

void cadastrarMecanico(struct Mecanico* mecanicos, int* qtd){

    printf("\n====== CADASTRO DE MECANICO ======\n");

    printf("ID: ");
    scanf("%d", &mecanicos[*qtd].id_mecanico);

    printf("Nome: ");
    scanf(" %[^\n]", mecanicos[*qtd].nome);//função para cadastrar

    printf("Especialidade: ");
    scanf(" %[^\n]", mecanicos[*qtd].especialidade);

    printf("Salario: ");
    scanf("%f", &mecanicos[*qtd].salario);
    (*qtd)++;

}
void alterarMecanico(struct Mecanico *mecanicos, int qtd){


    int id;
    

    printf("\n====== ALTERAR MECANICO ======\n");
    printf("Digite o ID do mecanico: ");
    scanf("%d", &id);

    for(int i = 0; i < qtd; i++){

        if(mecanicos[i].id_mecanico == id){

            printf("\nMecanico encontrado!\n");//função para alterar

            printf("Novo ID: ");
            scanf("%d", &mecanicos[i].id_mecanico);

            printf("Novo nome: ");
            scanf(" %[^\n]", mecanicos[i].nome);

            printf("Nova especialidade: ");
            scanf(" %[^\n]", mecanicos[i].especialidade);

            printf("Novo salario: ");
            scanf("%f", &mecanicos[i].salario);

            printf("\nAtualizado com sucesso!\n");
            
        }
        printf("\nMecanico nao encontrado!\n");
    }
}


void consultarMecanico(struct Mecanico mecanicos[], int qtd){

    int id;

    printf("Digite o ID do mecanico: ");
    scanf("%d", &id);

    for(int i = 0; i < qtd; i++){

        if(mecanicos[i].id_mecanico == id){

            printf("\nID: %d\n", mecanicos[i].id_mecanico);//função para consultar
            printf("Nome: %s\n", mecanicos[i].nome);
            printf("Especialidade: %s\n", mecanicos[i].especialidade);
            printf("Salario: %.2f\n", mecanicos[i].salario);
            
        }
    }
}
void removerMecanico(struct Mecanico mecanicos[], int *qtd){

    int id;

    printf("\n====== REMOVER MECANICO ======\n");
    printf("Digite o ID do mecanico: ");
    scanf("%d", &id);

    for(int i = 0; i < *qtd; i++){

        if(mecanicos[i].id_mecanico == id){

            for(int j = i; j < (*qtd - 1); j++){ //fucão para remover;
                mecanicos[j] = mecanicos[j + 1];
            }
            (*qtd)--;
            
            printf("\nMecanico removido com sucesso!\n");
        }
    }

    // só executa se não encontrou ninguém
    printf("\nMecanico nao encontrado!\n");
}

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

    int qtdMecanicos = 0; //alteração de arthurf : criei uma variavel que controla quantos mecanicos ja foram cadastrados .

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
            
            if(lala == 1){
                cadastrarMecanico(mecanicos, &qtdMecanicos);//alteração de arthur se o usuario escolhei cadastrar eu ja chamo a função do cadastro;
            }
            if(lala == 2){
                alterarMecanico(mecanicos, qtdMecanicos);
            }
            if(lala == 3){
                consultarMecanico(mecanicos, qtdMecanicos);
            }
            if(lala == 4){
                removerMecanico(mecanicos, &qtdMecanicos);
            }
            
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

