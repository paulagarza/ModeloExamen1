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
    // 1. Crear un vector de punteros inteligentes
    vector<shared_ptr<Producto>> inventario;

    // 2. Crear un puntero inteligente a un objeto Electronica y usar el operador --
    shared_ptr<Electronica> movil = make_shared<Electronica>("E001", "iPhone", 900.0, 5, 0.21);
    --(*movil);
    inventario.push_back(movil);

    // 3. Añadir un objeto Ropa al vector
    shared_ptr<Ropa> camiseta = make_shared<Ropa>("R001", "Camiseta", 20.00, 2, "M", 5.0);
    inventario.push_back(camiseta);

    // 4. Usar un bucle para mostrar el precio final invocando al polimorfismo
    cout << "--- Precios Finales ---" << endl;
    for (const auto &producto : inventario) {
        cout << *producto;
        cout << "Precio final: " << producto->calcularPrecioFinal() << "\n\n";
    }

    // 5. En un bloque try-catch, intentar vender una cantidad mayor a la del stock
    cout << "--- Intento de Venta ---" << endl;
    try {
        movil->vender(100);
    } catch (const exception& e) {
        cout << "Error capturado: " << e.what() << endl;
    }

    // 6. Instanciar una CajaEnvio, añadir ambos punteros e invocar mostrarContenido()
    cout << "\n--- Contenido de la Caja de Envio ---" << endl;
    CajaEnvio<shared_ptr<Producto>> caja;
    for (const auto &producto : inventario) {
        caja.agregarElemento(producto);
    }
    caja.mostrarContenido();
    return 0;
}