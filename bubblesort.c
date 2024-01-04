#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fun��o para trocar dois elementos em um array
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Fun��o para ordenar um array usando o Bubble Sort
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
        printf("N�o foi poss�vel abrir o arquivo de entrada.\n");
        return 1;
    }

    int maximo = 55000; //n�mero m�ximo de valores no arquivo
    int arr[maximo];
    int n = 0;

    // L� os valores do arquivo e armazena no array
    while (fscanf(arquivo, "%d", &arr[n]) == 1) {
        n++;
    }

    fclose(arquivo);

    // Mede o tempo de execu��o
    inicio = clock();

    // Ordena o array usando o Bubble Sort
    bubbleSort(arr, n);

    fim = clock();
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC*1000;

    FILE *saida = fopen("saida3.txt", "w");
    if (saida == NULL) {
        printf("N�o foi poss�vel criar o arquivo de sa�da.\n");
        return 1;
    }

    // Escreve os valores ordenados no arquivo de sa�da
    int i;
    for ( i = 0; i < n; i++) {
        fprintf(saida, "%d\n", arr[i]);
    }

    fclose(saida);
	
    printf("Arquivo ordenado com sucesso em: 'saida3.txt'.\n");
    
    printf("Tempo de execucao: %f segundos\n", tempo_execucao);

    return 0;
}
