#include <iostream>
#include <vector>
#include <thread>

const int N = 3; // Tamaño de la matriz (cambia según tus necesidades)

// Función para sumar las filas
void sumaFilas(const std::vector<std::vector<int>>& matriz, std::vector<int>& resultadoFilas) {
    for (int fila = 0; fila < N; ++fila) {
        int suma = 0;
        for (int columna = 0; columna < N; ++columna) {
            suma += matriz[fila][columna];
        }
        resultadoFilas[fila] = suma;
    }
}

// Función para sumar las columnas
void sumaColumnas(const std::vector<std::vector<int>>& matriz, std::vector<int>& resultadoColumnas) {
    for (int columna = 0; columna < N; ++columna) {
        int suma = 0;
        for (int fila = 0; fila < N; ++fila) {
            suma += matriz[fila][columna];
        }
        resultadoColumnas[columna] = suma;
    }
}

int main() {
    std::vector<std::vector<int>> matriz(N, std::vector<int>(N));

    // Llena la matriz con valores (puedes modificar esto según tus necesidades)
    for (int fila = 0; fila < N; ++fila) {
        for (int columna = 0; columna < N; ++columna) {
            std::cout << "Introduce el valor para la posición [" << fila << "][" << columna << "]: ";
            std::cin >> matriz[fila][columna];
        }
    }

    std::vector<int> resultadoFilas(N);
    std::vector<int> resultadoColumnas(N);

    // Crea los hilos para calcular las sumas
    std::thread hiloFilas(sumaFilas, std::ref(matriz), std::ref(resultadoFilas));
    std::thread hiloColumnas(sumaColumnas, std::ref(matriz), std::ref(resultadoColumnas));

    // Espera a que los hilos terminen
    hiloFilas.join();
    hiloColumnas.join();

    // Muestra los resultados
    std::cout << "Suma de las filas:" << std::endl;
    for (int fila = 0; fila < N; ++fila) {
        std::cout << "Fila " << fila << ": " << resultadoFilas[fila] << std::endl;
    }

    std::cout << "Suma de las columnas:" << std::endl;
    for (int columna = 0; columna < N; ++columna) {
        std::cout << "Columna " << columna << ": " << resultadoColumnas[columna] << std::endl;
    }

    return 0;
}
