#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool is_sorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

void shuffle(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int r = rand() % n;
        int temp = arr[i];
        arr[i] = arr[r];
        arr[r] = temp;
    }
}

void bogosort(int arr[], int n) {
    while (!is_sorted(arr, n)) {
        shuffle(arr, n);
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void save_to_file(char *filename, int size, double time_spent) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        fprintf(stderr, "Falha ao abrir o arquivo %s.\n", filename);
        exit(1);
    }

    fprintf(file, "%d %.6f\n", size, time_spent);

    fclose(file);
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
    int *arr = malloc(initial_size * sizeof(int));

    // Limpar os arquivos antes de começar
    clear_file("melhorcaso.txt");
    clear_file("piorcaso.txt");

    if (arr == NULL) {
        fprintf(stderr, "Falha na alocação de memória.\n");
        return 1;
    }

    // Melhor caso: Array já ordenado
    for (int size = initial_size; size <= 12; size++) {
        arr = realloc(arr, size * sizeof(int));

        if (arr == NULL) {
            fprintf(stderr, "Falha na realocação de memória.\n");
            return 1;
        }

        for (int i = 0; i < size; i++) {
            arr[i] = i;  // Melhor caso: array já ordenado
        }

        printf("Array original (Melhor Caso - Tamanho %d):\n", size);
        print_array(arr, size);

        clock_t start_time = clock();
        bogosort(arr, size);
        clock_t end_time = clock();
        double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        printf("Array ordenado (Melhor Caso - Tamanho %d):\n", size);
        print_array(arr, size);
        printf("Tempo para ordenar: %.6f segundos\n\n", time_spent);

        save_to_file("melhorcaso.txt", size, time_spent);
    }

    // Pior caso: Array em ordem inversa
    for (int size = initial_size; size <= 12; size++) {
        arr = realloc(arr, size * sizeof(int));

        if (arr == NULL) {
            fprintf(stderr, "Falha na realocação de memória.\n");
            return 1;
        }

        for (int i = 0; i < size; i++) {
            arr[i] = size - i - 1;  // Pior caso: array em ordem inversa
        }

        printf("Array original (Pior Caso - Tamanho %d):\n", size);
        print_array(arr, size);

        clock_t start_time = clock();
        bogosort(arr, size);
        clock_t end_time = clock();
        double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        printf("Array ordenado (Pior Caso - Tamanho %d):\n", size);
        print_array(arr, size);
        printf("Tempo para ordenar: %.6f segundos\n\n", time_spent);

        save_to_file("piorCaso.txt", size, time_spent);
        
    }
    FILE *pipe = popen("python script.py", "w");
    if (pipe == NULL) {
        fprintf(stderr, "Erro ao abrir o pipe para o script Python.\n");
        return 1;
    }

    system("script.py"); // Substitua "script.py" pelo nome real do seu script Python
    free(arr);
    return 0;
}
