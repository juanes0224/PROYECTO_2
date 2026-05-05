#include "Visualizer.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

void Visualizer::mostrar_vector(const vector<int>& vec, const string& etiqueta) {
    cout << "  " << etiqueta << ": [";
    for (int i = 0; i < (int)vec.size(); i++) {
        cout << vec[i];
        if (i < (int)vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

void Visualizer::dialsort(vector<int> datos, int U) {
    cout << "\n========================================" << endl;
    cout << "   VISUALIZACION DE DIALSORT" << endl;
    cout << "========================================" << endl;

    mostrar_vector(datos, "Datos originales");
    cout << "  Universo U = " << U << endl;
    cout << endl;

    cout << "--- Paso 1: Crear arreglo de diales (tamano U=" << U << ") ---" << endl;
    vector<int> diales(U, 0);
    cout << "  Diales iniciales (todos en 0):" << endl;
    cout << "  Indice: ";
    for (int i = 0; i < U; i++) cout << setw(3) << i << " ";
    cout << endl;
    cout << "  Conteo: ";
    for (int i = 0; i < U; i++) cout << setw(3) << diales[i] << " ";
    cout << endl << endl;

    cout << "--- Paso 2: Contar ocurrencias de cada valor ---" << endl;
    for (int i = 0; i < (int)datos.size(); i++) {
        int valor = datos[i];
        diales[valor]++;
        cout << "  Elemento datos[" << i << "] = " << valor
             << " -> diales[" << valor << "]++ = " << diales[valor] << endl;
    }

    cout << endl << "  Diales despues del conteo:" << endl;
    cout << "  Indice: ";
    for (int i = 0; i < U; i++) cout << setw(3) << i << " ";
    cout << endl;
    cout << "  Conteo: ";
    for (int i = 0; i < U; i++) cout << setw(3) << diales[i] << " ";
    cout << endl << endl;

    cout << "--- Paso 3: Reconstruir arreglo ordenado ---" << endl;
    int posicion = 0;
    for (int i = 0; i < U; i++) {
        for (int j = 0; j < diales[i]; j++) {
            datos[posicion] = i;
            cout << "  Escribir valor " << i << " en posicion " << posicion << endl;
            posicion++;
        }
    }

    cout << endl;
    mostrar_vector(datos, "Resultado ordenado");
    cout << "========================================\n" << endl;
}

void Visualizer::radixsort(vector<int> datos) {
    cout << "\n========================================" << endl;
    cout << "   VISUALIZACION DE RADIXSORT" << endl;
    cout << "========================================" << endl;

    mostrar_vector(datos, "Datos originales");

    int maximo = *max_element(datos.begin(), datos.end());
    cout << "  Valor maximo: " << maximo << endl;
    cout << endl;

    int n = datos.size();
    vector<int> salida(n);

    int paso = 1;
    for (int exp = 1; maximo / exp > 0; exp *= 10) {
        cout << "--- Pasada " << paso << ": digito en posicion " << exp << " ---" << endl;

        vector<int> conteo(10, 0);

        for (int i = 0; i < n; i++) {
            int digito = (datos[i] / exp) % 10;
            conteo[digito]++;
        }

        cout << "  Conteo de digitos: ";
        for (int i = 0; i < 10; i++) {
            if (conteo[i] > 0) cout << "[" << i << "]=" << conteo[i] << " ";
        }
        cout << endl;

        for (int i = 1; i < 10; i++) {
            conteo[i] += conteo[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            int digito = (datos[i] / exp) % 10;
            conteo[digito]--;
            salida[conteo[digito]] = datos[i];
        }

        datos = salida;
        mostrar_vector(datos, "  Despues de pasada " + to_string(paso));
        cout << endl;
        paso++;
    }

    mostrar_vector(datos, "Resultado ordenado");
    cout << "========================================\n" << endl;
}
