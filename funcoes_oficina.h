#ifndef FUNCOES_OFICINA_H
#define FUNCOES_OFICINA_H

#include "CRUD_mecanico.h"
#include "CRUD_veiculo.h"
#include "CRUD_servico.h"


int switch_case_crud(char tipo[]);
void gerenciarMecanicos(Lista_mecanico *, Lista_servico *);
void gerenciarVeiculos(Lista_veiculo *, Lista_servico *);
void gerenciarServicos(Lista_servico *, Lista_mecanico *, Lista_veiculo *);

void salvarDadosOficina(Lista_mecanico *, Lista_veiculo *, Lista_servico *, char *);
void carregarDadosOficina(Lista_mecanico *, Lista_veiculo *, Lista_servico *, char *);

#endif