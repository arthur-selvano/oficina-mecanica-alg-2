#ifndef CRUD_VEICULO_H
#define CRUD_VEICULO_H


typedef struct
{
    char placa_veiculo[10];
    char modelo[50];
    int ano;
    char telefone_dono[20];
} Veiculo;

typedef struct Lista_veiculo
{
    Veiculo *veiculos;
    int qtd_veiculos, qtd_max;
} Lista_veiculo;

typedef struct Lista_servico Lista_servico;


void cadastrarVeiculo(Lista_veiculo *);
void alterarVeiculo(Lista_veiculo *);
void consultarVeiculo(Lista_veiculo *);
void removerVeiculo(Lista_veiculo *, Lista_servico *);
void listarVeiculos(Lista_veiculo *);
int existeRegistroVeiculo(Lista_veiculo *);
char* placaMaiusculo(char placa[10]);

Veiculo *buscaVeiculoPlaca(Lista_veiculo *, char placa[10]);
void printVeiculo(Veiculo *);

Lista_veiculo *criarListaVeiculo(int);
void liberarListaVeiculo(Lista_veiculo *);

#endif