#ifndef CRUD_SERVICO_H
#define CRUD_SERVICO_H

typedef struct Lista_mecanico Lista_mecanico;
typedef struct Lista_veiculo Lista_veiculo;

typedef struct
{
    int numero_os;
    int id_mecanico;
    char placa_veiculo[10];
    char data_servico[15];
    char servico_realizado[200];
    float valor_total;
} Ordem_servico;

typedef struct Lista_servico
{
    Ordem_servico *ordem_servicos;
    int qtd_servicos, qtd_max;
} Lista_servico;

void cadastrarServico(Lista_servico *, Lista_mecanico *, Lista_veiculo *);
void alterarServico(Lista_servico *, Lista_mecanico *, Lista_veiculo *);
void removerServico(Lista_servico *);
void consultarServico(Lista_servico *);
void listarServico(Lista_servico *, Lista_mecanico *, Lista_veiculo *);
void printServico(Ordem_servico *);
int validarID(Lista_mecanico *);
void validarPlaca(Lista_veiculo *, char *);
int validarOS(Lista_servico *);
Ordem_servico *buscaOS(Lista_servico *, int);

Lista_servico *criarListaServico(int);
void liberarListaServico(Lista_servico *);

#endif