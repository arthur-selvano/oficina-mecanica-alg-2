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


int main(){    

    return 0;
}