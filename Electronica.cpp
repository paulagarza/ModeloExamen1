//
// Created by Usuario on 17/05/2026.
//

#include "Electronica.h"
// Constructor por defecto

// Constructor parametrizado
Electronica::Electronica(const string& codigo, const string& nombre,
    double precioBase, int stock, double impuesto) : Producto(codigo, nombre, precioBase, stock), impuesto(impuesto) {
    if (impuesto < 0 || impuesto > 1) {
        throw invalid_argument("El impuesto no puede ser negativo.");
    }
}

// Getters
double Electronica::getImpuesto() const {
    return impuesto;
}

// Setters
void Electronica::setImpuesto(double impuesto) {
    if (impuesto < 0 || impuesto > 1) {
        throw invalid_argument("El impuesto no puede ser negativo.");
    }
    this->impuesto = impuesto;
}

// Sobrecarga del operador -- (prefijo)
Electronica &Electronica::operator--() {
    if (stock <= 0) {
        throw invalid_argument("No se puede descatalogar: stock insuficiente.");
    }
    // Utiliza encapsulación
    setStock(getStock()-1);
    // --stock; // Más limpia y más eficiente
    return *this;
}

// Método Calcular precio final
double Electronica::calcularPrecioFinal() const {
    return precioBase * (1 + impuesto);
}