#include "Benchmark.h"
#include "Sorters.h"
#include "DataGenerator.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>
#include <numeric>

BenchmarkResult Benchmark::ejecutar(
    const string& nombre,
    function<void(vector<int>&)> algoritmo,
    const vector<int>& datos_originales,
    int U,
    const string& distribucion,
    int repeticiones
) {
    vector<double> tiempos;
    int n = datos_originales.size();

    for (int r = 0; r < repeticiones; r++) {
        vector<int> copia = datos_originales;

        auto inicio = chrono::high_resolution_clock::now();
        algoritmo(copia);
        auto fin = chrono::high_resolution_clock::now();

        double duracion = chrono::duration<double, milli>(fin - inicio).count();
        tiempos.push_back(duracion);

        if (r == 0 && !Sorters::esta_ordenado(copia)) {
            cerr << "ERROR: " << nombre << " no ordeno correctamente!" << endl;
        }
    }

    double suma = accumulate(tiempos.begin(), tiempos.end(), 0.0);
    double media = suma / repeticiones;

    double suma_cuadrados = 0.0;
    for (double t : tiempos) {
        suma_cuadrados += (t - media) * (t - media);
    }
    double desviacion = sqrt(suma_cuadrados / repeticiones);

    double throughput = (media > 0) ? (n / (media / 1000.0)) : 0;

    BenchmarkResult resultado;
    resultado.nombre_algoritmo = nombre;
    resultado.tiempo_promedio_ms = media;
    resultado.desviacion_estandar = desviacion;
    resultado.throughput = throughput;
    resultado.n = n;
    resultado.U = U;
    resultado.distribucion = distribucion;

    return resultado;
}

void Benchmark::linea_separadora() {
    cout << string(105, '-') << endl;
}

void Benchmark::imprimir_encabezado() {
    linea_separadora();
    cout << left << setw(15) << "Algoritmo"
         << right << setw(12) << "n"
         << setw(12) << "U"
         << setw(14) << "Distrib."
         << setw(16) << "Tiempo(ms)"
         << setw(14) << "Desv.Est."
         << setw(22) << "Throughput(elem/s)" << endl;
    linea_separadora();
}

void Benchmark::imprimir_resultado(const BenchmarkResult& r) {
    cout << left << setw(15) << r.nombre_algoritmo
         << right << setw(12) << r.n
         << setw(12) << r.U
         << setw(14) << r.distribucion
         << setw(16) << fixed << setprecision(3) << r.tiempo_promedio_ms
         << setw(14) << fixed << setprecision(3) << r.desviacion_estandar
         << setw(22) << scientific << setprecision(2) << r.throughput << endl;
}

void Benchmark::completo() {
    cout << "\n*** EJECUTANDO BENCHMARK COMPLETO ***\n" << endl;

    vector<int> tamanos_n = {100000, 500000, 1000000, 5000000, 10000000};
    vector<int> tamanos_U = {100, 10000, 1000000};
    vector<string> nombres_dist = {"Uniforme", "Ordenado", "Inverso", "Repetidos"};

    vector<BenchmarkResult> todos_resultados;

    imprimir_encabezado();

    for (int n : tamanos_n) {
        for (int U : tamanos_U) {
            for (int d = 0; d < (int)nombres_dist.size(); d++) {

                vector<int> datos;
                switch (d) {
                    case 0: datos = DataGenerator::uniforme(n, U); break;
                    case 1: datos = DataGenerator::ordenado(n, U); break;
                    case 2: datos = DataGenerator::inverso(n, U); break;
                    case 3: datos = DataGenerator::repetidos(n, U); break;
                }

                auto fn_dialsort = [U](vector<int>& v) { Sorters::dialsort(v, U); };
                BenchmarkResult r1 = ejecutar("DialSort", fn_dialsort, datos, U, nombres_dist[d]);
                imprimir_resultado(r1);
                todos_resultados.push_back(r1);

                auto fn_radixsort = [](vector<int>& v) { Sorters::radixsort(v); };
                BenchmarkResult r2 = ejecutar("RadixSort", fn_radixsort, datos, U, nombres_dist[d]);
                imprimir_resultado(r2);
                todos_resultados.push_back(r2);

                auto fn_stdsort = [](vector<int>& v) { Sorters::stdsort(v); };
                BenchmarkResult r3 = ejecutar("std::sort", fn_stdsort, datos, U, nombres_dist[d]);
                imprimir_resultado(r3);
                todos_resultados.push_back(r3);

                linea_separadora();
            }
        }
    }

    cout << "\n*** RESUMEN: GANADORES POR CONFIGURACION ***\n" << endl;
    for (int i = 0; i < (int)todos_resultados.size(); i += 3) {
        double t1 = todos_resultados[i].tiempo_promedio_ms;
        double t2 = todos_resultados[i + 1].tiempo_promedio_ms;
        double t3 = todos_resultados[i + 2].tiempo_promedio_ms;

        string ganador;
        if (t1 <= t2 && t1 <= t3) ganador = "DialSort";
        else if (t2 <= t1 && t2 <= t3) ganador = "RadixSort";
        else ganador = "std::sort";

        cout << "n=" << setw(10) << todos_resultados[i].n
             << " U=" << setw(10) << todos_resultados[i].U
             << " Dist=" << setw(10) << todos_resultados[i].distribucion
             << " -> Ganador: " << ganador << endl;
    }
}

void Benchmark::personalizado() {
    int n, U, dist;

    cout << "\nIngrese el tamano del arreglo (n): ";
    cin >> n;

    cout << "Ingrese el tamano del universo (U): ";
    cin >> U;

    cout << "Seleccione distribucion:" << endl;
    cout << "  1. Uniforme" << endl;
    cout << "  2. Ordenado" << endl;
    cout << "  3. Inverso" << endl;
    cout << "  4. Repetidos" << endl;
    cout << "Opcion: ";
    cin >> dist;

    if (dist < 1 || dist > 4) {
        cout << "Distribucion invalida." << endl;
        return;
    }

    vector<int> datos;
    string nombre_dist;

    switch (dist) {
        case 1: datos = DataGenerator::uniforme(n, U); nombre_dist = "Uniforme"; break;
        case 2: datos = DataGenerator::ordenado(n, U); nombre_dist = "Ordenado"; break;
        case 3: datos = DataGenerator::inverso(n, U); nombre_dist = "Inverso"; break;
        case 4: datos = DataGenerator::repetidos(n, U); nombre_dist = "Repetidos"; break;
    }

    cout << "\nEjecutando benchmark con n=" << n << ", U=" << U
         << ", Dist=" << nombre_dist << "...\n" << endl;

    imprimir_encabezado();

    auto fn_dialsort = [U](vector<int>& v) { Sorters::dialsort(v, U); };
    imprimir_resultado(ejecutar("DialSort", fn_dialsort, datos, U, nombre_dist));

    auto fn_radixsort = [](vector<int>& v) { Sorters::radixsort(v); };
    imprimir_resultado(ejecutar("RadixSort", fn_radixsort, datos, U, nombre_dist));

    auto fn_stdsort = [](vector<int>& v) { Sorters::stdsort(v); };
    imprimir_resultado(ejecutar("std::sort", fn_stdsort, datos, U, nombre_dist));

    linea_separadora();
}
