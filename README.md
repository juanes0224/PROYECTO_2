Aquí tienes una versión optimizada para **GitHub**, con estilo más visual, uso de emojis tipo “stickers” y mejor jerarquía Markdown:

---

# 🚀 Practice II: DialSort vs RadixSort vs std::sort

🎓 **ST0245 - Data Structures and Algorithms**
🏫 **EAFIT University - School of Applied Sciences and Engineering**
📅 **April 2026**

---

## 👥 Integrantes del Equipo

* ✏️ Juan Esteban Grisales Restrepo
     Sofia Rojo Salazar

---

## 📌 Descripción del Proyecto

Este proyecto implementa y compara experimentalmente tres algoritmos de ordenamiento:

### 🔵 1. DialSort (Counting Sort)

🧠 Algoritmo basado en conteo
📊 Crea un arreglo de contadores (*diales*) de tamaño **U**
⚙️ Reconstruye el arreglo ordenado a partir de frecuencias

---

### 🟢 2. RadixSort (LSD)

🔢 Ordenamiento por dígitos (de menor a mayor significancia)
♻️ Utiliza **Counting Sort** como subrutina estable
📦 Ideal para números enteros grandes

---

### 🔴 3. std::sort (Introsort)

⚡ Implementación optimizada de C++ STL
🔀 Combina:

* QuickSort 🧩
* HeapSort 🏗️
* InsertionSort 🪶

🎯 Garantiza complejidad **O(n log n)** en el peor caso

---

## 📈 Complejidad Algorítmica

| ⚙️ Algoritmo | 🟢 Mejor   | 🟡 Promedio | 🔴 Peor    | 💾 Espacio |
| ------------ | ---------- | ----------- | ---------- | ---------- |
| DialSort     | O(n + U)   | O(n + U)    | O(n + U)   | O(U)       |
| RadixSort    | O(d·(n+b)) | O(d·(n+b))  | O(d·(n+b)) | O(n+b)     |
| std::sort    | O(n log n) | O(n log n)  | O(n log n) | O(log n)   |

📌 Donde:

* **n** → número de elementos
* **U** → rango de valores posibles
* **d** → número de dígitos del valor máximo
* **b** → base (10 en esta implementación)

---

## 🧭 Uso del Programa

Al ejecutar, encontrarás un menú interactivo:

1️⃣ 🔍 **Visualizar DialSort**
2️⃣ 🔍 **Visualizar RadixSort**
3️⃣ 📊 **Benchmark completo**
4️⃣ ⚙️ **Benchmark personalizado**
5️⃣ 🚪 **Salir**

---

## ⚡ Configuración del Benchmark

* 📏 **Tamaños (n):**
  `100K | 500K | 1M | 5M | 10M`

* 🎯 **Universo (U):**
  `100 | 10K | 1M`

* 🔀 **Distribuciones:**

  * Uniforme
  * Ordenado
  * Inverso
  * Repetidos

* 🔁 **Repeticiones:** 5 por configuración

---

## 📊 Métricas Evaluadas

* ⏱️ **Tiempo promedio (ms)**
* 📉 **Desviación estándar (ms)**
* 🚀 **Throughput (elem/s)**

---

## 🧠 Resultados Esperados

* 🟢 **DialSort** → Excelente cuando **U es pequeño**
* 🔵 **RadixSort** → Competitivo con **n y U grandes**
* 🔴 **std::sort** → Mejor opción general 🚀

---

## 🗂️ Estructura del Proyecto

```
proyecto_dialsort/
├── 📄 main.cpp      # Código fuente
├── ⚙️ Makefile      # Compilación
└── 📘 README.md     # Documentación
```

---

## ⭐ Notas Finales

💡 Este proyecto permite entender cómo el **contexto de datos** impacta el rendimiento de los algoritmos de ordenamiento.

📌 Ideal para análisis experimental en estructuras de datos.

---

Si quieres, puedo darte una versión aún más “pro” tipo README de repositorio top (con badges, shields.io, GIFs y benchmarking plots).
