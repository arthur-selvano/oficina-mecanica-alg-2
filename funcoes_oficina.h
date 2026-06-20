#ifndef FUNCOES_OFICINA_h
#define FUNCOES_OFICINA_h


struct Mecanico{
    int id_mecanico;
    char nome[50];
    char especialidade[50];
    float salario;
};

struct Veiculo{
    char placa_veiculo[10];
    char modelo[50];
    int ano;
    char telefone_dono[15];
};

struct Ordem_Servico{
    int numero_os;
    int id_mecanico;
    char placa_veiculo[10];
    char data_servico[15];
    char servico_realizado[200];
    float valor_total;
};

int switch_case_crud(char tipo[]);
void gerenciarMecanico (struct Mecanico *mecanicos, int *qtd_mec);


#endif