#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para ordenar um array usando o Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move os elementos do arr[0..i-1] que são maiores do que key
		// para uma posição à frente de sua posição atual
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

    int maximo = 55000;  //número máximo de valores no arquivo
    int arr[maximo];
    int n = 0;

    // Lê os valores do arquivo e armazena no array
    while (fscanf(arquivo, "%d", &arr[n]) == 1) {
        n++;
    }

    fclose(arquivo);

    // Mede o tempo de execução
    inicio = clock();

    // Ordena o array usando o Insertion Sort
    insertionSort(arr, n);

    fim = clock();
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC*1000;

    FILE *saida = fopen("saida1.txt", "w");
    if (saida == NULL) {
        printf("Não foi possível criar o arquivo de saída.\n");
        return 1;
    }

    // Escreve os valores ordenados no arquivo de saída
    int i;
    for (i = 0; i < n; i++) {
        fprintf(saida, "%d\n", arr[i]);
    }

    fclose(saida);

    printf("Arquivo ordenado com sucesso em: 'saida1.txt'.\n");
    printf("Tempo de execucao: %f segundos\n", tempo_execucao);

    return 0;
}

