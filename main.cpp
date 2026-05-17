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
        cout << "Creación del Inventario" << endl;
        // Vector polimórfico de punteros inteligentes, pueden almacenar objetos Electronica y Ropa porque ambos heredan de Producto
        vector<shared_ptr<Producto>> inventario;

        // Creación del objeto Electronica
        shared_ptr<Electronica> movil = make_shared<Electronica>("E001", "iPhone", 900.0, 5, 0.21);

        // Uso del operador -- (prefijo sobrecargado)
        --(*movil);

        // Se añade el puntero al vector de inventario
        inventario.push_back(movil);

        // Creación del objeto Ropa
        shared_ptr<Ropa> camiseta = make_shared<Ropa>("E002", "Camiseta", 20.00, 2, "M", 5.0);

        // Se añade al inventario
        inventario.push_back(camiseta);

        // Mostrar productos
        cout << endl;
        cout << "--- Mostrar productos ---" << endl;

        // Recorrido del vector polimorfico
        for (const auto &producto : inventario) {
            cout << *producto << endl;
            // Llamada polimorfica, cada clase ejecutsa SU version de calcularPrecioFinal()
            cout << "Precio final: " << producto->calcularPrecioFinal() << endl;
        }

        // Venta correcta
        cout << endl;
        cout << "Venta Correcta: " << endl;

        // Venta válida
        camiseta->vender(1);

        // Se muestra el stock restante
        cout << "Stock después de vender camisetas: " << camiseta->getStock() << endl;

        // Venta incorrecta
        cout << endl;
        cout << "Venta Incorrecta: " << endl;

        // Try local para controlar excepciones de venta
        try {
            // Se intenta vender más stocl del disponible
            movil->vender(100);
        } catch (const exception& e) {
            cout << "Error capturado: " << e.what() << endl;
        }

        // Cada de envio (template)
        cout << endl;
        cout << "Caja de envio: " << endl;

        // Instancia del template
        CajaEnvio<shared_ptr<Producto>> caja;

        // Se añaden productos a la caja
        for (const auto &producto : inventario) {
            caja.agregarElemento(producto);
        }

        // Se muestran los productos almacenados
        caja.mostrarContenido();

        // Validaciones
        cout << endl;
        cout << "Validaciones: " << endl;

        // Precio negativo
        try {
            Electronica productoMalPrecio ("E003", "Tablet", -200.0, 2, 0.21);

        } catch (const exception& e) {
            cout << "Error capturado: " << e.what() << endl;
        }

        // Stock negativo
        try {
            Electronica productoMalStock ("E003", "Tablet", 200.0, -2, 0.21);

        } catch (const exception& e) {
            cout << "Error capturado: " << e.what() << endl;
        }

        // Inpuesto inválido
        try {
            Electronica productoMalInpuesto ("E003", "Tablet", 200.0, 5, 1.5);

        } catch (const exception& e) {
            cout << "Error capturado: " << e.what() << endl;
        }

        // Descuento inválido
        try {
            Ropa productoMalDescuento ("E003", "Pantalon", 200.0, 3, "L", 50.0);

        } catch (const exception& e) {
            cout << "Error capturado: " << e.what() << endl;
        }

        cout << endl;

    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}