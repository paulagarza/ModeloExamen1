//
// Created by Usuario on 17/05/2026.
//

#ifndef MODELOEXAMEN1_CAJAENVIO_H
#define MODELOEXAMEN1_CAJAENVIO_H

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class CajaEnvio {
private:
    // Atributos
    vector<T> elementos;

public:
    // Constructor por defecto
    CajaEnvio() = default;

    // Constructor parametrizado
    CajaEnvio(const vector<T>& elementos) {
        this->elementos = elementos;
    }

    // Getters
    vector<T> getElementos() const {
        return elementos;
    }

    // Setters
    void setElementos(const vector<T>& elementos) {
        this->elementos = elementos;
    }
    // Método agregar elemento
    void agregarElemento(const T& elemento) {
        elementos.push_back(elemento);
    }

    // Método mostrar contenido
    void mostrarContenido() const {
        for (const auto &elemento : elementos) {
            cout << *elemento << endl; // Dame el objeto real al que apunta el puntero
        }
    }
};


#endif //MODELOEXAMEN1_CAJAENVIO_H