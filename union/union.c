//
// Created by Ezekiel on 22/11/2024.
//
#include "union.h"
#include <stdio.h>
#include <string.h>

// Asignar un valor entero a la unión
void asignarEntero(MiUnion *u, int valor) {
    u->entero = valor;
}

// Asignar un valor flotante a la unión
void asignarFlotante(MiUnion *u, float valor) {
    u->flotante = valor;
}

// Asignar una cadena de caracteres a la unión
void asignarCadena(MiUnion *u, const char *cadena) {
    strncpy(u->cadena, cadena, sizeof(u->cadena) - 1);
    u->cadena[sizeof(u->cadena) - 1] = '\0'; // Asegurar terminación nula
}

// Imprimir el valor de la unión según el tipo especificado
void imprimirUnion(const MiUnion *u, const char *tipo) {
    if (strcmp(tipo, "entero") == 0) {
        printf("Valor entero: %d\n", u->entero);
    } else if (strcmp(tipo, "flotante") == 0) {
        printf("Valor flotante: %.2f\n", u->flotante);
    } else if (strcmp(tipo, "cadena") == 0) {
        printf("Valor cadena: %s\n", u->cadena);
    } else {
        printf("Tipo no reconocido.\n");
    }
}
