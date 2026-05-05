#ifndef BENCHMARKRESULT_H
#define BENCHMARKRESULT_H

#include <string>

using namespace std;

struct BenchmarkResult {
    string nombre_algoritmo;
    double tiempo_promedio_ms;
    double desviacion_estandar;
    double throughput;
    int n;
    int U;
    string distribucion;
};

#endif
