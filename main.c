#include <stdio.h>
#include <string.h> 

// 1. Estrutura Mecânico
struct mecanico {
    int id_mecanico;       
    char nome[100];
    char especialidade[100];    
    float salario;         
};

// 2. Estrutura Veículo
struct veiculo {
    char placa_veiculo[15]; 
    char modelo[50];
    int ano;
    char telefone_dono[20];
};

// 3. Estrutura Ordem de Serviço
struct ordem_de_servico {
    int numero_os;          
    int id_mecanico;        
    char placa_veiculo[15]; 
    char data_servico[11];  
    float valor_total;      
};

// Protótipo de Funções
int buscarMecanicoPorId(struct mecanico* mecanicos, int qtd, int id);
int buscarVeiculoPorPlaca(struct veiculo* veiculos, int qtd, char* placa);

// CRUD Mecânicos
void cadastrarMecanico(struct mecanico* mecanicos, int* qtd);
void listarMecanicos(struct mecanico* mecanicos, int qtd);
void consultarMecanico(struct mecanico* mecanicos, int qtd);
void alterarMecanico(struct mecanico* mecanicos, int qtd);

// CRUD Veículos
void cadastrarVeiculo(struct veiculo* veiculos, int* qtd);
void listarVeiculos(struct veiculo* veiculos, int qtd);
void consultarVeiculo(struct veiculo* veiculos, int qtd);
void alterarVeiculo(struct veiculo* veiculos, int qtd);

int main(){    
    return 0;
}