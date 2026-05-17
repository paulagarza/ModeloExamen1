#include <functional>
#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>

#include "Producto.h"
#include "Electronica.h"
#include "Ropa.h"
#include "CajaEnvio.h"

int main() {
    // Try general del programa
    try {
        vector<shared_ptr<Producto>> inventario;

        shared_ptr<Electronica> movil = make_shared<Electronica>("E001", "iPhone", 900.0, 5, 0.21);
        --(*movil);
        inventario.push_back(movil);

        inventario.push_back(camiseta);

        for (const auto &producto : inventario) {
        }

        try {
            movil->vender(100);
        } catch (const exception& e) {
            cout << "Error capturado: " << e.what() << endl;
        }

        CajaEnvio<shared_ptr<Producto>> caja;
        for (const auto &producto : inventario) {
            caja.agregarElemento(producto);
        }
        caja.mostrarContenido();
        cout << endl;

    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}