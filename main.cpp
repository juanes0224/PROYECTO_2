#include <iostream>
#include <vector>
#include "Visualizer.h"
#include "Benchmark.h"

using namespace std;

void mostrar_menu() {
    cout << "\n============================================" << endl;
    cout << "  BENCHMARK: DIALSORT vs RADIXSORT vs STD::SORT" << endl;
    cout << "  ST0245 - EAFIT University" << endl;
    cout << "============================================" << endl;
    cout << "  1. Visualizar DialSort (ejemplo pequeno)" << endl;
    cout << "  2. Visualizar RadixSort (ejemplo pequeno)" << endl;
    cout << "  3. Ejecutar benchmark completo" << endl;
    cout << "  4. Ejecutar benchmark personalizado" << endl;
    cout << "  5. Salir" << endl;
    cout << "============================================" << endl;
    cout << "  Seleccione una opcion: ";
}

int main() {
    int opcion;

    do {
        mostrar_menu();
        cin >> opcion;

        switch (opcion) {
            case 1: {
                vector<int> ejemplo = {4, 2, 0, 3, 1, 4, 2, 0, 3, 1};
                Visualizer::dialsort(ejemplo, 5);
                break;
            }
            case 2: {
                vector<int> ejemplo = {170, 45, 75, 90, 802, 24, 2, 66};
                Visualizer::radixsort(ejemplo);
                break;
            }
            case 3: {
                Benchmark::completo();
                break;
            }
            case 4: {
                Benchmark::personalizado();
                break;
            }
            case 5: {
                cout << "\nSaliendo del programa. Hasta luego!" << endl;
                break;
            }
            default: {
                cout << "\nOpcion invalida. Intente de nuevo." << endl;
                break;
            }
        }

    } while (opcion != 5);

    return 0;
}
