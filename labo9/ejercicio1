#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int rank, num_procs, N = 100;
    int *vector = NULL;
    int local_sum = 0;
    int *local_buffer;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    if (rank == 0) {
        // Solo el proceso maestro crea el vector de tamaño N con valores aleatorios
        vector = (int *)malloc(N * sizeof(int));
        srand(time(NULL));
        for (int i = 0; i < N; i++) {
            vector[i] = rand() % 100; // Genera valores aleatorios entre 0 y 99
        }
    }

    // Determina cuántos elementos manejará cada proceso
    int elements_per_proc = N / num_procs;
    local_buffer = (int *)malloc(elements_per_proc * sizeof(int));

    // Distribuye el vector a todos los procesos
    MPI_Scatter(vector, elements_per_proc, MPI_INT, local_buffer, elements_per_proc, MPI_INT, 0, MPI_COMM_WORLD);

    // Cada proceso calcula la suma de sus elementos locales
    for (int i = 0; i < elements_per_proc; i++) {
        local_sum += local_buffer[i];
    }

    // Cada proceso muestra su PID y el resultado de su suma local
    printf("Proceso %d: Suma local = %d\n", rank, local_sum);

    // Liberar memoria
    if (rank == 0) {
        free(vector);
    }
    free(local_buffer);

    MPI_Finalize();
    return 0;
}
