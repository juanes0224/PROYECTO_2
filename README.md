<div align="center">

# 🎯 PROYECTO 2

### DialSort vs RadixSort vs std::sort

**Análisis Experimental de Algoritmos y Estructuras de Datos**

![C++](https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![CLion](https://img.shields.io/badge/CLion-000000?style=for-the-badge&logo=clion&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-3.20+-064F8C?style=for-the-badge&logo=cmake&logoColor=white)
![License](https://img.shields.io/badge/Licencia-Académica-green?style=for-the-badge)

<br>

📚 **ST0245 — Estructuras de Datos y Algoritmos**
🏫 **EAFIT University — Escuela de Ciencias Aplicadas e Ingeniería**
👨‍🏫 **Docente:** Alexander Narváez Berrío
📅 **Abril 2026**

---

</div>

## 📋 Descripción

Benchmark completo que implementa y compara experimentalmente **tres estrategias de ordenamiento** con visualización del comportamiento interno, medición de tiempos y análisis estadístico.

| Algoritmo | Tipo | Idea Central |
|:---------:|:----:|:-------------|
| 🎯 **DialSort** | Counting Sort | Cuenta ocurrencias de cada valor en un arreglo de tamaño U |
| 🔢 **RadixSort** | LSD Radix | Ordena dígito por dígito, del menos al más significativo |
| ⚡ **std::sort** | Introsort (STL) | Combina QuickSort + HeapSort + InsertionSort |

---

## 📊 Complejidad Algorítmica

<div align="center">

| | DialSort | RadixSort | std::sort |
|:--|:--:|:--:|:--:|
| ⏱️ **Mejor caso** | `O(n + U)` | `O(d·(n+b))` | `O(n log n)` |
| ⏱️ **Caso promedio** | `O(n + U)` | `O(d·(n+b))` | `O(n log n)` |
| ⏱️ **Peor caso** | `O(n + U)` | `O(d·(n+b))` | `O(n log n)` |
| 💾 **Espacio** | `O(U)` | `O(n + b)` | `O(log n)` |

</div>

> **Variables:**
> `n` = número de elementos · `U` = tamaño del universo · `d` = dígitos del máximo · `b` = base (10)

---

## 🗂️ Estructura del Proyecto

```
PROYECTO_2/
│
├── 📄 CMakeLists.txt          ← Configuración de CMake para CLion
├── 🚀 main.cpp                ← Punto de entrada y menú interactivo
│
├── 📦 BenchmarkResult.h       ← Struct con los datos de cada medición
│
├── 🎯 Sorters.h               ← Declaración de los 3 algoritmos
├── 🎯 Sorters.cpp             ← Implementación: dialsort, radixsort, stdsort
│
├── 🎲 DataGenerator.h         ← Declaración de generadores de datos
├── 🎲 DataGenerator.cpp       ← Implementación: uniforme, ordenado, inverso, repetidos
│
├── 👁️ Visualizer.h            ← Declaración de la visualización paso a paso
├── 👁️ Visualizer.cpp          ← Implementación: muestra el comportamiento interno
│
├── ⏱️ Benchmark.h             ← Declaración del sistema de benchmark
└── ⏱️ Benchmark.cpp           ← Implementación: medición, estadísticas, tablas
```

---

## 🧩 Clases del Proyecto

### `Sorters`
Contiene los tres algoritmos como métodos estáticos y la verificación de correctitud.

```cpp
Sorters::dialsort(datos, U);     // Counting Sort con universo U
Sorters::radixsort(datos);       // LSD Radix Sort base 10
Sorters::stdsort(datos);         // Wrapper de std::sort
Sorters::esta_ordenado(datos);   // Verifica que el arreglo esté ordenado
```

### `DataGenerator`
Genera arreglos de prueba con cuatro distribuciones distintas.

```cpp
DataGenerator::uniforme(n, U);   // Valores aleatorios en [0, U-1]
DataGenerator::ordenado(n, U);   // Valores ascendentes con módulo U
DataGenerator::inverso(n, U);    // Valores descendentes con módulo U
DataGenerator::repetidos(n, U);  // Solo 10 valores distintos máximo
```

### `Visualizer`
Muestra paso a paso cómo funciona cada algoritmo con arreglos pequeños.

```cpp
Visualizer::dialsort(datos, U);  // Visualiza conteo y reconstrucción
Visualizer::radixsort(datos);    // Visualiza cada pasada por dígito
```

### `Benchmark`
Ejecuta las pruebas de rendimiento y calcula estadísticas.

```cpp
Benchmark::completo();           // Todas las combinaciones de n, U, distribución
Benchmark::personalizado();      // El usuario elige los parámetros
Benchmark::ejecutar(nombre, fn, datos, U, dist);  // Una sola prueba
```

### `BenchmarkResult`
Struct que almacena los resultados de cada medición.

```cpp
struct BenchmarkResult {
    string nombre_algoritmo;
    double tiempo_promedio_ms;
    double desviacion_estandar;
    double throughput;
    int n, U;
    string distribucion;
};
```

---

## ⚙️ Compilación y Ejecución

### 🔧 Opción 1: CLion (recomendado)

1. Abrir CLion
2. `File` → `Open` → Seleccionar la carpeta `PROYECTO_2`
3. CLion detecta `CMakeLists.txt` automáticamente
4. Click en ▶️ **Run** o `Shift + F10`

### 🖥️ Opción 2: Terminal

```bash
cd PROYECTO_2

# Compilar
g++ -std=c++17 -O2 -Wall -Wextra -o PROYECTO_2 main.cpp Sorters.cpp DataGenerator.cpp Visualizer.cpp Benchmark.cpp

# Ejecutar
./PROYECTO_2
```

### 🐳 Opción 3: CMake manual

```bash
cd PROYECTO_2
mkdir build && cd build
cmake ..
make
./PROYECTO_2
```

---

## 🖥️ Uso del Programa

Al ejecutar se muestra un menú interactivo:

```
============================================
  BENCHMARK: DIALSORT vs RADIXSORT vs STD::SORT
  ST0245 - EAFIT University
============================================
  1. Visualizar DialSort (ejemplo pequeno)
  2. Visualizar RadixSort (ejemplo pequeno)
  3. Ejecutar benchmark completo
  4. Ejecutar benchmark personalizado
  5. Salir
============================================
```

| Opción | Descripción |
|:------:|:------------|
| `1` | 👁️ Muestra paso a paso el conteo y reconstrucción de DialSort |
| `2` | 👁️ Muestra cada pasada de RadixSort dígito por dígito |
| `3` | 📊 Ejecuta **60 configuraciones** (5 tamaños × 3 universos × 4 distribuciones) |
| `4` | 🎛️ El usuario elige `n`, `U` y tipo de distribución |
| `5` | 🚪 Salir |

---

## 📏 Configuraciones del Benchmark

<div align="center">

| Parámetro | Valores |
|:---------:|:--------|
| 📐 **n** (tamaño) | `100,000` · `500,000` · `1,000,000` · `5,000,000` · `10,000,000` |
| 🌐 **U** (universo) | `100` · `10,000` · `1,000,000` |
| 📈 **Distribuciones** | Uniforme · Ordenado · Inverso · Repetidos |
| 🔁 **Repeticiones** | 5 por configuración |

</div>

---

## 📉 Métricas Medidas

| Métrica | Fórmula | Descripción |
|:--------|:--------|:------------|
| ⏱️ **Tiempo promedio** | `Σtᵢ / k` | Media de k=5 ejecuciones en milisegundos |
| 📊 **Desviación estándar** | `√(Σ(tᵢ - μ)² / k)` | Dispersión de los tiempos |
| 🚀 **Throughput** | `n / (t_ms / 1000)` | Elementos ordenados por segundo |

---

## 🏆 Resultados Esperados

```
🥇 DialSort domina cuando U es pequeño (U ≤ 10,000)
    → O(n + U) ≈ O(n), todo cabe en caché L1/L2

🥈 RadixSort es competitivo con U grande y n grande
    → O(d·n) donde d ≤ 7 dígitos para U ≤ 10⁶

🥉 std::sort es la mejor opción general cuando U es desconocido
    → O(n log n) sin depender de U ni de la distribución
```

---

## 👥 Integrantes

| Nombres
| [Juan Esteban Grisales Restrepo] | [Sofia Rojo Salazar] |

---

<div align="center">

**Hecho con** ❤️ **para ST0245 — EAFIT University — 2026-1**
**Se utilizó claude como soporte para el desarrollo del codigo y chatgpt para el readme**
</div>
