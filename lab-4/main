#include <iostream>
#include <omp.h>

// Función a integrar
double f(double x) {
    return (x * x * x) / 3.0 + 4.0;
}

// Función que calcula la integral usando la regla del trapecio
double integrate(double a, double b, int n) {
    double h = (b - a) / n;  // Ancho de cada subintervalo
    double sum = 0.0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += f(x);
    }

    // Sumar los términos de los extremos
    sum += (f(a) + f(b)) / 2.0;
    sum *= h;

    return sum;
}

int main() {
    double a, b;
    int n;

    // Leer los límites de integración y el número de subintervalos
    std::cout << "Introduce el límite inferior a: ";
    std::cin >> a;
    std::cout << "Introduce el límite superior b: ";
    std::cin >> b;
    std::cout << "Introduce el número de subintervalos n: ";
    std::cin >> n;

    // Calcular la integral
    double result = integrate(a, b, n);

    // Mostrar el resultado
    std::cout << "El valor de la integral es: " << result << std::endl;

    return 0;
}
