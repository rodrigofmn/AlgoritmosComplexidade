#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int jump_search(int arr[], int n, int x) {
    int step = sqrt(n);
    int prev = 0;
    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }
    while (arr[prev] < x) {
        prev++;
        if (prev == min(step, n)) {
            return -1;
        }
    }
    if (arr[prev] == x) {
        return prev;
    }
    return -1;
}

int min(int a, int b) {
    return (a < b) ? a : b;
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

        printf("Melhor Caso - Array:\n");
        print_array(arr, size);

        int x = size - 1;  // Último elemento

        clock_t start_time = clock();
        int result = jump_search(arr, size, x);
        clock_t end_time = clock();

        double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("Melhor Caso - Elemento %d encontrado na posição %d.\n", x, result);
        printf("Melhor Caso - Tempo para buscar: %.6f segundos\n\n", time_spent);

        // Salvar resultados no arquivo
        FILE *best_case_file = fopen("melhorcaso.txt", "a");
        fprintf(best_case_file, "%d %.6f\n", size, time_spent);
        fclose(best_case_file);

        free(arr);

        // Pior caso
        arr = realloc(NULL, size * sizeof(int));
        generate_worst_case(arr, size);

        printf("Pior Caso - Array:\n");
        print_array(arr, size);

        start_time = clock();
        result = jump_search(arr, size, x);
        end_time = clock();

        time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("Pior Caso - Elemento %d encontrado na posição %d.\n", x, result);
        printf("Pior Caso - Tempo para buscar: %.6f segundos\n\n", time_spent);

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
