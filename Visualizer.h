#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <vector>
#include <string>

using namespace std;

class Visualizer {
public:
    static void mostrar_vector(const vector<int>& vec, const string& etiqueta);
    static void dialsort(vector<int> datos, int U);
    static void radixsort(vector<int> datos);
};

#endif
