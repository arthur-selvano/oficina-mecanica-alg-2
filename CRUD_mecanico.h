#ifndef CRUD_MECANICO_H
#define CRUD_MECANICO_H


typedef struct
{
    int id_mecanico;
    char nome[50];
    char especialidade[50];
    float salario;
} Mecanico;

typedef struct Lista_mecanico
{
    Mecanico *mecanicos;
    int qtd_mec, qtd_max;
} Lista_mecanico;

typedef struct Lista_servico Lista_servico;


void cadastrarMecanico(Lista_mecanico *);
void alterarMecanico(Lista_mecanico *);
void consultarMecanico(Lista_mecanico *);
void removerMecanico(Lista_mecanico *, Lista_servico *);
void listarMecanicos(Lista_mecanico *);
int existeRegistro(Lista_mecanico *);


Mecanico *buscaMecanicoId(Lista_mecanico *, int);
void printMecanico(Mecanico *);

Lista_mecanico *criarListaMecanico(int);
void liberarListaMecanico(Lista_mecanico *);

void salvarMecanicos(Lista_mecanico *, char *);
void carregarMecanicos(Lista_mecanico *, char *);

#endif