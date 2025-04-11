#include <stdio.h>
#include "processo.h"

int main() {
    Processo processos[MAX_PROCESSES];
    int tamanho = 0;

    FILE *arquivo = fopen("processo_043_202409032338.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo: processo_043_202409032338.csv. Certifique-se de que o arquivo está no diretório correto.\n");
        return 1;
    }

    char linha[256];
    int i = 0;

    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo)) {
        sscanf(linha, "%d,%[^,],%[^,],%d,{%d},%d", 
               &processos[i].id, processos[i].numero, processos[i].data_ajuizamento,
               &processos[i].id_classe, &processos[i].id_assunto[0], &processos[i].ano_eleicao);
        i++;
    }
    fclose(arquivo);
    tamanho = i; 

    ordenarPorId(processos, tamanho);
    ordenarPorData(processos, tamanho);

    int count = contarIdClasse(processos, tamanho, 18392);
    printf("Total de processos com id_classe 18392: %d\n", count);

    int uniqueAssuntos = contarIdAssuntos(processos, tamanho);
    printf("Total de id_assuntos únicos: %d\n", uniqueAssuntos);

    listarMultivalorados(processos, tamanho);

    calcularDiasTramitacao(processos, tamanho);

    FILE *arquivo_saida = fopen("resultado.csv", "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao criar o arquivo de saída. Verifique permissões ou diretório.\n");
        return 1;
    }

    fprintf(arquivo_saida, "\"id\",\"numero\",\"data_ajuizamento\",\"id_classe\",\"id_assunto\",\"ano_eleicao\"\n");

    for (int j = 0; j < tamanho; j++) {
        fprintf(arquivo_saida, "%d,\"%s\",\"%s\",%d,{%d},%d\n",
                processos[j].id, processos[j].numero, processos[j].data_ajuizamento,
                processos[j].id_classe, processos[j].id_assunto[0], processos[j].ano_eleicao);
    }
    fclose(arquivo_saida); 

    printf("Resultados armazenados no arquivo 'resultado.csv'.\n");

    printf("Pressione Enter para sair...\n");
    getchar(); 

    return 0;
}
