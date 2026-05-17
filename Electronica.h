//
// Created by Usuario on 17/05/2026.
//

#ifndef MODELOEXAMEN1_ELECTRONICA_H
#define MODELOEXAMEN1_ELECTRONICA_H
#include "Producto.h"


class Electronica : public Producto {
private:
    // Atributos
    double impuesto;

public:
    // Constructor por defecto

    // Constructor parametrizado
    Electronica(const string& codigo, const string& nombre, double precioBase, int stock, double impuesto);

    // Destructor
    ~Electronica() override = default;

    // Getters
    double getImpuesto() const;

    // Setters
    void setImpuesto(double impuesto);

    // Sobrecarga del operador -- (prefijo)
    Electronica& operator--();

    // Método Calcular precio final
    double calcularPrecioFinal() const override;
};


#endif //MODELOEXAMEN1_ELECTRONICA_H