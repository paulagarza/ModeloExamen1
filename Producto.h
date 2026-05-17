//
// Created by Usuario on 17/05/2026.
//

#ifndef MODELOEXAMEN1_PRODUCTO_H
#define MODELOEXAMEN1_PRODUCTO_H


#include <iostream>
#include <stdexcept>
using namespace std;

class Producto {
protected:
    string codigo;
    string nombre;
    double precioBase;
    int stock;
public:
    // Constructor por defecto
    Producto();

    // Constructor parametrizado
    Producto(const string& codigo, const string& nombre, double precioBase, int stock);
    // Constructor copia
    Producto(const Producto& other);

    // Destructor

    // Getters
    string getCodigo() const;
    string getNombre() const;
    double getPrecioBase() const;
    int getStock() const;

    // Setters
    void setCodigo(const string& codigo);
    void setNombre(const string& nombre);
    void setPrecioBase(double precioBase);
    void setStock(int stock);

    // Sobrecarga del operador <<
    friend ostream& operator<< (ostream& os, const Producto& obj);

    // Método virtual puro
    virtual double calcularPrecioFinal() const = 0;

    // Método virtual vender
    virtual void vender(int cantidad);
};
#endif //MODELOEXAMEN1_PRODUCTO_H