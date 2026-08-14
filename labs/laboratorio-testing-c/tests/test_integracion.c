#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_compra_con_descuento(void){
    printf("\nTest de integracion: compra con descuento\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 2}; 
    Producto q = {"Pan", 200, 3};
    carrito_agregar(&c, p);
    carrito_agregar(&c, q);
    ASSERT_IGUAL(1300, carrito_total(&c));
    ASSERT_IGUAL(1170, carrito_descuento(carrito_total(&c), 10));
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_agregar_hasta_llenar(void){
    printf("\nTest de integracion: verificar limite de compra\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1}; 
    Producto q = {"Pan", 200, 1};
    Producto r = {"Pan", 200, 1};
    Producto s = {"Pan", 200, 1};
    Producto t = {"Pan", 200, 1};
    carrito_agregar(&c, p);
    carrito_agregar(&c, q);
    carrito_agregar(&c, r);
    carrito_agregar(&c, s);
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
    ASSERT_IGUAL(0, carrito_agregar(&c, t));
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();  
    test_agregar_hasta_llenar();  
    RESUMEN();
    return EXIT_CODE();
}
