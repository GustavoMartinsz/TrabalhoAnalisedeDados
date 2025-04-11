#ifndef PROCESSO_H
#define PROCESSO_H

#define MAX_PROCESSES 18392

typedef struct {
    int id;                  
    char numero[20];         
    char data_ajuizamento[25]; 
    int id_classe;           
    int id_assunto[10];     
    int ano_eleicao;         
} Processo;

void ordenarPorId(Processo processos[], int tamanho);
void ordenarPorData(Processo processos[], int tamanho);
int contarIdClasse(Processo processos[], int tamanho, int id_classe);
int contarIdAssuntos(Processo processos[], int tamanho);
void listarMultivalorados(Processo processos[], int tamanho);
void calcularDiasTramitacao(Processo processos[], int tamanho);

#endif
