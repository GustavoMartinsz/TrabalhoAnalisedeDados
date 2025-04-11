#include "processo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void ordenarPorId(Processo processos[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (processos[j].id > processos[j + 1].id) {
                Processo temp = processos[j];
                processos[j] = processos[j + 1];
                processos[j + 1] = temp;
            }
        }
    }
}

void ordenarPorData(Processo processos[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (strcmp(processos[j].data_ajuizamento, processos[j + 1].data_ajuizamento) < 0) {
                Processo temp = processos[j];
                processos[j] = processos[j + 1];
                processos[j + 1] = temp;
            }
        }
    }
}

int contarIdClasse(Processo processos[], int tamanho, int id_classe) {
    int count = 0;
    for (int i = 0; i < tamanho; i++) {
        if (processos[i].id_classe == id_classe) {
            count++;
        }
    }
    return count;
}

int contarIdAssuntos(Processo processos[], int tamanho) {
    int assuntos_unicos[1000] = {0};
    int total_unicos = 0;

    for (int i = 0; i < tamanho; i++) {
        int encontrado = 0;
        for (int j = 0; j < total_unicos; j++) {
            if (assuntos_unicos[j] == processos[i].id_assunto[0]) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            assuntos_unicos[total_unicos++] = processos[i].id_assunto[0];
        }
    }

    return total_unicos;
}

void listarMultivalorados(Processo processos[], int tamanho) {
    printf("Processos com id_assunto multivalorado:\n");
    for (int i = 0; i < tamanho; i++) {
        if (processos[i].id_assunto[1] != 0) { 
            printf("ID: %d, Numero: %s\n", processos[i].id, processos[i].numero);
        }
    }
}

void calcularDiasTramitacao(Processo processos[], int tamanho) {
    time_t agora = time(NULL); 
    struct tm data = {0}; 

    for (int i = 0; i < tamanho; i++) {
        sscanf(processos[i].data_ajuizamento, "%d-%d-%d %d:%d:%d",
               &data.tm_year, &data.tm_mon, &data.tm_mday,
               &data.tm_hour, &data.tm_min, &data.tm_sec);

        data.tm_year -= 1900; 
        data.tm_mon -= 1;  
        
        time_t data_ajuizamento = mktime(&data);

        double diferenca = difftime(agora, data_ajuizamento) / (60 * 60 * 24);
        printf("Processo %d está em tramitação há %.0f dias\n", processos[i].id, diferenca);
    }
}
