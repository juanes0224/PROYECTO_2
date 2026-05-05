#include "Sorters.h"
#include <algorithm>

void Sorters::dialsort(vector<int>& datos, int U) {
    vector<int> diales(U, 0);

    for (int valor : datos) {
        diales[valor]++;
    }

    int posicion = 0;
    for (int i = 0; i < U; i++) {
        for (int j = 0; j < diales[i]; j++) {
            datos[posicion] = i;
            posicion++;
        }
    }
}

void Sorters::radixsort(vector<int>& datos) {
    int n = datos.size();
    if (n <= 1) return;

    int maximo = *max_element(datos.begin(), datos.end());
    if (maximo == 0) return;

    vector<int> salida(n);

    for (int exp = 1; maximo / exp > 0; exp *= 10) {
        vector<int> conteo(10, 0);

        for (int i = 0; i < n; i++) {
            int digito = (datos[i] / exp) % 10;
            conteo[digito]++;
        }

        for (int i = 1; i < 10; i++) {
            conteo[i] += conteo[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            int digito = (datos[i] / exp) % 10;
            conteo[digito]--;
            salida[conteo[digito]] = datos[i];
        }

        datos = salida;
    }
}

void Sorters::stdsort(vector<int>& datos) {
    sort(datos.begin(), datos.end());
}

bool Sorters::esta_ordenado(const vector<int>& datos) {
    for (int i = 1; i < (int)datos.size(); i++) {
        if (datos[i] < datos[i - 1]) {
            return false;
        }
    }
    return true;
}
