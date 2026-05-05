#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#include <vector>

using namespace std;

class DataGenerator {
public:
    static vector<int> uniforme(int n, int U);
    static vector<int> ordenado(int n, int U);
    static vector<int> inverso(int n, int U);
    static vector<int> repetidos(int n, int U);
};

#endif
