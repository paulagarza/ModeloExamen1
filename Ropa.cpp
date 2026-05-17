//
// Created by Usuario on 17/05/2026.
//

#include "Ropa.h"
// Constructor por defecto
Ropa::Ropa() {

}

// Constructor parametrizado
Ropa::Ropa(const string& codigo, const string& nombre,
    double precioBase, int stock, const string& talla,
    double descuento) : Producto(codigo, nombre, precioBase, stock), talla(talla), descuento(descuento) {

    if (descuento < 0 || descuento > precioBase) {
        throw invalid_argument("Descuento inválido.");
    }
}

// Getters
string Ropa::getTalla() const {
    return talla;
}

double Ropa::getDescuento() const {
    return descuento;
}

// Setters
void Ropa::setTalla(const string& talla) {
    this->talla = talla;
}

void Ropa::setDescuento(double descuento) {

    if (descuento < 0 || descuento > getPrecioBase()) {
        throw invalid_argument ("Descuento inválido.");
    }
    this->descuento = descuento;
}

// Método Calcular precio final
double Ropa::calcularPrecioFinal() const {
    return getPrecioBase() - descuento;
}

// Sobreescribir Método vender
void Ropa::vender(int cantidad) {

    Producto::vender(cantidad);
    if (getStock() == 0) {
    }
}