//
// Created by Usuario on 17/05/2026.
//

#ifndef MODELOEXAMEN1_ROPA_H
#define MODELOEXAMEN1_ROPA_H
#include "Producto.h"


class Ropa : public Producto {
private:
    // Atributos
    string talla;
    double descuento;

public:
    // Constructor por defecto
    Ropa();

    // Constructor parametrizado
    Ropa(const string& codigo, const string& nombre, double precioBase, int stock, const string& talla, double descuento);

    // Destructor
    ~Ropa() override = default;

    // Getters
    string getTalla() const;
    double getDescuento() const;

    // Setters
    void setTalla(const string& talla);
    void setDescuento(double descuento);

    // Método Calcular precio final
    double calcularPrecioFinal() const override;

    // Sobreescribir Método vender
    void vender(int cantidad) override;

};


#endif //MODELOEXAMEN1_ROPA_H