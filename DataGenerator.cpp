#include "DataGenerator.h"
#include <random>
#include <algorithm>

vector<int> DataGenerator::uniforme(int n, int U) {
    mt19937 generador(42);
    uniform_int_distribution<int> distribucion(0, U - 1);
    vector<int> datos(n);
    for (int i = 0; i < n; i++) {
        datos[i] = distribucion(generador);
    }
    return datos;
}

vector<int> DataGenerator::ordenado(int n, int U) {
    vector<int> datos(n);
    for (int i = 0; i < n; i++) {
        datos[i] = i % U;
    }
    return datos;
}

vector<int> DataGenerator::inverso(int n, int U) {
    vector<int> datos(n);
    for (int i = 0; i < n; i++) {
        datos[i] = (n - 1 - i) % U;
    }
    return datos;
}

vector<int> DataGenerator::repetidos(int n, int U) {
    mt19937 generador(42);
    int rango = min(10, U);
    uniform_int_distribution<int> distribucion(0, rango - 1);
    vector<int> datos(n);
    for (int i = 0; i < n; i++) {
        datos[i] = distribucion(generador);
    }
    return datos;
}
