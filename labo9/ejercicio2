#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        // Proceso 0 envía dos números reales al proceso 1
        double num1 = 3.14;
        double num2 = 2.71;
        MPI_Send(&num1, 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);
        MPI_Send(&num2, 1, MPI_DOUBLE, 1, 1, MPI_COMM_WORLD);

        // Proceso 0 recibe la suma del proceso 1 y la imprime
        double sum;
        MPI_Recv(&sum, 1, MPI_DOUBLE, 1, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Proceso 0: La suma de %.2f y %.2f es %.2f\n", num1, num2, sum);
    } else if (rank == 1) {
        // Proceso 1 recibe los dos números reales del proceso 0
        double num1, num2;
        MPI_Recv(&num1, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&num2, 1, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        // Proceso 1 calcula la suma y la envía de vuelta al proceso 0
        double sum = num1 + num2;
        MPI_Send(&sum, 1, MPI_DOUBLE, 0, 2, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
