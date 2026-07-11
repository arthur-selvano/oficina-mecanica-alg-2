#ifndef CRUD_SERVICO_H
#define CRUD_SERVICO_H


void cadastrarServico(Lista_servico *);

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


Lista_servico *criarListaServico(int);
void liberarListaServico(Lista_servico *);

#endif