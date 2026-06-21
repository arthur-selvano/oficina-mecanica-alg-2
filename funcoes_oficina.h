#ifndef FUNCOES_OFICINA_H
#define FUNCOES_OFICINA_H

#include "CRUD_mecanico.h"
#include "CRUD_veiculo.h"

typedef struct
{
    int numero_os;
    int id_mecanico;
    char placa_veiculo[10];
    char data_servico[15];
    char servico_realizado[200];
    float valor_total;
} Ordem_servico;

typedef struct
{
    Ordem_servico *ordem_servicos;
    int qtd_servicos, qtd_max;
} Lista_servico;

int switch_case_crud(char tipo[]);
void gerenciarMecanico(Lista_mecanico *);
void gerenciarVeiculos(Lista_veiculo *);

Lista_servico *criarListaServico(int);

void liberarListaServico(Lista_servico *);

#endif