#ifndef SORTERS_H
#define SORTERS_H

#include <vector>

using namespace std;

class Sorters {
public:
    static void dialsort(vector<int>& datos, int U);
    static void radixsort(vector<int>& datos);
    static void stdsort(vector<int>& datos);
    static bool esta_ordenado(const vector<int>& datos);
};

#endif
