#ifndef FUNCOES_OFICINA_H
#define FUNCOES_OFICINA_H

#include "CRUD_mecanico.h"
#include "CRUD_veiculo.h"
#include "CRUD_servico.h"


int switch_case_crud(char tipo[]);
void gerenciarMecanicos(Lista_mecanico *);
void gerenciarVeiculos(Lista_veiculo *);
void gerenciarServico(Lista_servico *);

#endif