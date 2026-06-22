#ifndef CRUD_VEICULO_H
#define CRUD_VEICULO_H

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

void cadastrarVeiculo(Lista_veiculo *);
void alterarVeiculo(Lista_veiculo *);
void consultarVeiculo(Lista_veiculo *);
void removerVeiculo(Lista_veiculo *);
void listarVeiculos(Lista_veiculo *);
int existeRegistroVeiculo(Lista_veiculo *);


Veiculo *buscaVeiculoPlaca(Lista_veiculo *, char placa[10]);
void printVeiculo(Veiculo *);

Lista_veiculo *criarListaVeiculo(int);
void liberarListaVeiculo(Lista_veiculo *);

#endif