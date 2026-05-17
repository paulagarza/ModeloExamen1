//
// Created by Usuario on 17/05/2026.
//

#include "Producto.h"

Producto::Producto():codigo(" "), nombre(" "), precioBase(0.0), stock(0) {
}

Producto::Producto(const string &codigo, const string &nombre, double precioBase, int stock) : codigo(codigo), nombre(nombre), precioBase(precioBase), stock(stock) {
    if (precioBase < 0) {
        throw invalid_argument("Precio base NO puede ser negativo.");
    }
    if (stock < 0) {
        throw invalid_argument("Stock NO puede ser negativo.");
    }
}

Producto::Producto(const Producto &producto) {
    this->codigo = producto.codigo;
    this->nombre = producto.nombre;
    this->precioBase = producto.precioBase;
    this->stock = producto.stock;
}

string Producto::getCodigo() const {
    return codigo;
}

string Producto::getNombre() const {
    return nombre;
}

double Producto::getPrecioBase() const {
    return precioBase;
}

int Producto::getStock() const {
    return stock;
}

void Producto::setCodigo(const string &codigo) {
    this->codigo = codigo;
}

void Producto::setNombre(const string &nombre) {
    this->nombre = nombre;
}

void Producto::setPrecioBase(double precioBase) {
    if (precioBase < 0) {
    }
    this->precioBase = precioBase;
}

void Producto::setStock(int stock) {
    if (stock < 0) {
    }
    this->stock = stock;
}

//sobrecarga
ostream &operator <<(ostream &os, const Producto &obj) {
    os << "Nombre: " << obj.nombre << endl;
    os << "Codigo: " << obj.codigo << endl;
    os << "PrecioBase: " << obj.precioBase << endl;
    os << "Stock: " << obj.stock << endl;
    return os;
}

//metodos
void Producto::vender(int cantidad) {
    if (stock < cantidad) {
        throw runtime_error("Stock insuficiente.");
    }
    setStock(getStock() - cantidad);
}
