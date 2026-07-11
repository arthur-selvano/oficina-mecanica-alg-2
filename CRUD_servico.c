#include <stdio.h>
#include <stdlib.h>
#include "CRUD_servico.h"

void cadastrarServico(Lista_servico *lista_servico){

    Lista_servico *NovoServico = &lista_servico->ordem_servicos[lista_servico->qtd_servicos];


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

void liberarListaServico(Lista_servico *lista_servico)
{
    free(lista_servico->ordem_servicos);
    free(lista_servico);
}