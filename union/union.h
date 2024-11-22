//
// Created by Ezekiel on 22/11/2024.
//

#ifndef UNION_H
#define UNION_H

#include <stdbool.h>

// Definición de la unión para almacenar diferentes tipos
typedef union {
    int entero;
    float flotante;
    char cadena[50];
} MiUnion;

// Declaraciones de funciones para manejar la unión
void asignarEntero(MiUnion *u, int valor);
void asignarFlotante(MiUnion *u, float valor);
void asignarCadena(MiUnion *u, const char *cadena);
void imprimirUnion(const MiUnion *u, const char *tipo);

#endif // UNION_H

