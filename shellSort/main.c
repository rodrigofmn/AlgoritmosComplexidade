#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellsort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generate_best_case(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;  // Melhor caso: array já ordenado
    }
}

void generate_worst_case(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = size - i - 1;  // Pior caso: array em ordem inversa
    }
}

void clear_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Falha ao abrir o arquivo %s.\n", filename);
        exit(1);
    }
    fclose(file);
}

int main() {
    srand(time(NULL));
    int initial_size = 5;

    // Limpar os arquivos antes de começar
    clear_file("melhorcaso.txt");
    clear_file("piorcaso.txt");

    for (int size = initial_size; size <= 1000; size++) {
        int *arr = realloc(NULL, size * sizeof(int));

        if (arr == NULL) {
            fprintf(stderr, "Falha na alocação de memória.\n");
            return 1;
        }

        // Melhor caso
        generate_best_case(arr, size);

        printf("Melhor Caso - Array original:\n");
        print_array(arr, size);

        clock_t start_time = clock();
        shellsort(arr, size);
        clock_t end_time = clock();

        double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("Melhor Caso - Array ordenado:\n");
        print_array(arr, size);
        printf("Tempo para ordenar: %.6f segundos\n\n", time_spent);

        // Salvar resultados no arquivo
        FILE *best_case_file = fopen("melhorcaso.txt", "a");
        fprintf(best_case_file, "%d %.6f\n", size, time_spent);
        fclose(best_case_file);

        free(arr);

        // Pior caso
        arr = realloc(NULL, size * sizeof(int));
        generate_worst_case(arr, size);

        printf("Pior Caso - Array original:\n");
        print_array(arr, size);

        start_time = clock();
        shellsort(arr, size);
        end_time = clock();

        time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("Pior Caso - Array ordenado:\n");
        print_array(arr, size);
        printf("Tempo para ordenar: %.6f segundos\n\n", time_spent);

        // Salvar resultados no arquivo
        FILE *worst_case_file = fopen("piorcaso.txt", "a");
        fprintf(worst_case_file, "%d %.6f\n", size, time_spent);
        fclose(worst_case_file);

        free(arr);
    }

    // Executar script Python
    system("python script.py");

    return 0;
}
