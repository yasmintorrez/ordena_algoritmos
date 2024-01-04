#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos em um array
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Função para ordenar um array usando o Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    clock_t inicio, fim;
    double tempo_execucao;

    FILE *arquivo = fopen("base3.txt", "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo de entrada.\n");
        return 1;
    }

    int maximo = 55000; //número máximo de valores no arquivo
    int arr[maximo];
    int n = 0;

    // Lê os valores do arquivo e armazena no array
    while (fscanf(arquivo, "%d", &arr[n]) == 1) {
        n++;
    }

    fclose(arquivo);

    // Mede o tempo de execução
    inicio = clock();

    // Ordena o array usando o Bubble Sort
    bubbleSort(arr, n);

    fim = clock();
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC*1000;

    FILE *saida = fopen("saida3.txt", "w");
    if (saida == NULL) {
        printf("Não foi possível criar o arquivo de saída.\n");
        return 1;
    }

    // Escreve os valores ordenados no arquivo de saída
    int i;
    for ( i = 0; i < n; i++) {
        fprintf(saida, "%d\n", arr[i]);
    }

    fclose(saida);
	
    printf("Arquivo ordenado com sucesso em: 'saida3.txt'.\n");
    
    printf("Tempo de execucao: %f segundos\n", tempo_execucao);

    return 0;
}
