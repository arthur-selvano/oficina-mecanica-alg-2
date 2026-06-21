#ifndef FUNCOES_OFICINA_H
#define FUNCOES_OFICINA_H

typedef struct
{
    int id_mecanico;
    char nome[50];
    char especialidade[50];
    float salario;
} Mecanico;

typedef struct
{
    Mecanico *mecanicos;
    int qtd_mec, qtd_max;
} Lista_mecanico;

typedef struct
{
    char placa_veiculo[10];
    char modelo[50];
    int ano;
    char telefone_dono[15];
} Veiculo;

typedef struct
{
    Veiculo *veiculos;
    int qtd_veiculos, qtd_max;
} Lista_veiculo;

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
void cadastrarMecanico(Lista_mecanico *);
void alterarMecanico(Lista_mecanico *);
void consultarMecanico(Lista_mecanico *);
void removerMecanico(Lista_mecanico *);
void printMecanico(Mecanico *);
Mecanico *buscaMecanicoId(Lista_mecanico *, int);

Lista_mecanico *criarListaMecanico(int);
Lista_veiculo *criarListaVeiculo(int);
Lista_servico *criarListaServico(int);
void liberarListaMecanico(Lista_mecanico *);
void liberarListaVeiculo(Lista_veiculo *);
void liberarListaServico(Lista_servico *);

#endif