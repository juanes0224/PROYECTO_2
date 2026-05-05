cmake_minimum_required(VERSION 3.20)
project(PROYECTO_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(PROYECTO_2
        main.cpp
        BenchmarkResult.h
        DataGenerator.h
        DataGenerator.cpp
        Sorters.h
        Sorters.cpp
        Visualizer.h
        Visualizer.cpp
        Benchmark.h
        Benchmark.cpp
)
