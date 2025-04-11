📊 Trabalho de Análise de Dados em C

🎓 Projeto Acadêmico – Leitura e Manipulação de Arquivos CSV

   Este projeto tem como objetivo a implementação de um programa em C capaz de ler, interpretar e manipular dados contidos em um arquivo `.csv` com registros de processos judiciais da Justiça Eleitoral.

 📁 Estrutura do Projeto

- `main.c` – Arquivo principal do programa
- `processo.c` – Arquivo com funções auxiliares
- `processo.h` – Definições e protótipos
- `processo_043_202409032338.csv` – Base de dados (.csv)
- `resultado.csv` – Arquivo gerado com os resultados processados
- `teste.exe` – Executável do programa
- `README.md` – Este documento

📌 Funcionalidades Implementadas

1. Ordenar os dados por `id` (ordem crescente)
2. Ordenar por `data_ajuizamento` (ordem decrescente)
3. Contar processos com determinado `id_classe`
4. Contar `id_assunto` distintos
5. Listar processos com múltiplos assuntos
6. Calcular há quantos dias um processo está em tramitação


 ▶️ Como Compilar e Executar

 ✅ Compilação (GCC):

bash
gcc main.c processo.c -o teste.exe
