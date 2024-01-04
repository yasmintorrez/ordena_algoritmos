#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fun��o para ordenar um array usando o Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move os elementos do arr[0..i-1] que s�o maiores do que key
		// para uma posi��o � frente de sua posi��o atual
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
        printf("N�o foi poss�vel abrir o arquivo de entrada.\n");
        return 1;
    }

    int maximo = 55000;  //n�mero m�ximo de valores no arquivo
    int arr[maximo];
    int n = 0;

    // L� os valores do arquivo e armazena no array
    while (fscanf(arquivo, "%d", &arr[n]) == 1) {
        n++;
    }

    fclose(arquivo);

    // Mede o tempo de execu��o
    inicio = clock();

    // Ordena o array usando o Insertion Sort
    insertionSort(arr, n);

    fim = clock();
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC*1000;

    FILE *saida = fopen("saida1.txt", "w");
    if (saida == NULL) {
        printf("N�o foi poss�vel criar o arquivo de sa�da.\n");
        return 1;
    }

    // Escreve os valores ordenados no arquivo de sa�da
    int i;
    for (i = 0; i < n; i++) {
        fprintf(saida, "%d\n", arr[i]);
    }

    fclose(saida);

    printf("Arquivo ordenado com sucesso em: 'saida1.txt'.\n");
    printf("Tempo de execucao: %f segundos\n", tempo_execucao);

    return 0;
}

