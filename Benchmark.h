#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <vector>
#include <string>
#include <functional>
#include "BenchmarkResult.h"

using namespace std;

class Benchmark {
public:
    static BenchmarkResult ejecutar(
        const string& nombre,
        function<void(vector<int>&)> algoritmo,
        const vector<int>& datos_originales,
        int U,
        const string& distribucion,
        int repeticiones = 5
    );

    static void linea_separadora();
    static void imprimir_encabezado();
    static void imprimir_resultado(const BenchmarkResult& r);
    static void completo();
    static void personalizado();
};

#endif
