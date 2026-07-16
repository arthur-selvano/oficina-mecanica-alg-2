#include <stdio.h>
#include <stdlib.h>
#include "CRUD_mecanico.h"
#include "funcoes_oficina.h"

//===========================================================================
// FUNÇÃO 1 CADASTRO_MECANICO;

void cadastrarMecanico(Lista_mecanico *lista_mec)
{
    printf("\n====== CADASTRO DE MECANICO ======\n");

    if (lista_mec->qtd_mec >= lista_mec->qtd_max)
    {
        int nova_capacidade = lista_mec->qtd_max * 2;

        Mecanico *temporario = realloc(
            lista_mec->mecanicos,
            nova_capacidade * sizeof(Mecanico)
        );

        if (temporario == NULL)
        {
            printf("\nErro: memoria insuficiente!\n");
            return;
        }

        lista_mec->mecanicos = temporario;
        lista_mec->qtd_max = nova_capacidade;
    }

    Mecanico *NovoMecanico =
        &lista_mec->mecanicos[lista_mec->qtd_mec];

    do
    {
        printf("ID: ");
        scanf("%d", &NovoMecanico->id_mecanico);

        if (buscaMecanicoId(lista_mec, NovoMecanico->id_mecanico) != NULL)
        {
            printf("Atencao: esse ID ja existe!\n\n");
        }

    } while (buscaMecanicoId(lista_mec, NovoMecanico->id_mecanico) != NULL);

    printf("Nome: ");
    scanf(" %[^\n]", NovoMecanico->nome);

    printf("Especialidade: ");
    scanf(" %[^\n]", NovoMecanico->especialidade);

    printf("Salario: ");
    scanf("%f", &NovoMecanico->salario);

    lista_mec->qtd_mec++;
}

//===========================================================================
// FUNÇÃO 2 ALTERAR_MECANICO;
void alterarMecanico(Lista_mecanico *lista_mec)
{

    int id;

    if(!existeRegistro(lista_mec)){
        return;
    }

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
    if(!existeRegistro(lista_mec)){
        return;
    }
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

void removerMecanico(Lista_mecanico *lista_mec, Lista_servico *lista_servico)
{
    int *qtd = &lista_mec->qtd_mec;
    int id;

    if(!existeRegistro(lista_mec)){
        return;
    }

    printf("\n====== REMOVER MECANICO ======\n");
    printf("Digite o ID do mecanico: ");
    scanf("%d", &id);

    Mecanico *mecanico = buscaMecanicoId(lista_mec, id);

    if (mecanico == NULL)
    {
        printf("\nMecanico nao encontrado!\n");
        return;
    }

    for (int i = 0; i < lista_servico->qtd_servicos; i++)
    {
        if(lista_servico->ordem_servicos[i].id_mecanico == id){
            printf("Remocao negada, ha registro do mecanico\nem uma ordem de servio\n");
            return;
        }
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
            return;
        }
    }
}

void printMecanico(Mecanico *mecanico)
{
    printf("\nID: %d\n", mecanico->id_mecanico);
    printf("Nome: %s\n", mecanico->nome);
    printf("Especialidade: %s\n", mecanico->especialidade);
    printf("Salario: %.2f\n", mecanico->salario);
}

void listarMecanicos(Lista_mecanico *lista_mec)
{

    if(!existeRegistro(lista_mec)){
        return;
    }

    printf("\n=========== MECANICOS ===========\n");

    for (int i = 0; i < lista_mec->qtd_mec; i++)
    {
        printMecanico(&lista_mec->mecanicos[i]);
    }
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

int existeRegistro(Lista_mecanico *lista_mec){
    if (lista_mec->qtd_mec == 0) 
    {
        printf("\nNenhum mecanico cadastrado.\n");
        return 0;
    }
    return 1;
}

Lista_mecanico *criarListaMecanico(int tamanho)
{
    Lista_mecanico *lista_mec = malloc(sizeof(Lista_mecanico));

    if (lista_mec == NULL)
    {
        printf("\nMemoria insuficiente!\n");
        return NULL;
    }

    lista_mec->qtd_mec = 0;
    lista_mec->qtd_max = tamanho;

    lista_mec->mecanicos = malloc(tamanho * sizeof(Mecanico));

    if (lista_mec->mecanicos == NULL)
    {
        printf("\nMemoria insuficiente!\n");
        free(lista_mec);
        return NULL;
    }

    return lista_mec;
}


void liberarListaMecanico(Lista_mecanico *lista_mec)
{
    free(lista_mec->mecanicos);
    free(lista_mec);
}