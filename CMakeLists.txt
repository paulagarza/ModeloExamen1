cmake_minimum_required(VERSION 4.1)
project(ModeloExamen1)

set(CMAKE_CXX_STANDARD 11)

add_executable(ModeloExamen1 main.cpp
        Producto.h
        Producto.cpp
        Electronica.h
        Electronica.cpp
        Ropa.h
        Ropa.cpp
        CajaEnvio.h)
