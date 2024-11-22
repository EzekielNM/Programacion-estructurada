//
// Created by Ezekiel on 22/11/2024.
//
#include "estudiante.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función para crear un estudiante
Estudiante crearEstudiante(const char *nombre, int edad, float promedio) {
    Estudiante e;
    strncpy(e.nombre, nombre, sizeof(e.nombre) - 1);
    e.nombre[sizeof(e.nombre) - 1] = '\0'; // Asegurar terminación nula
    e.edad = edad;
    e.promedio = promedio;
    return e;
}

// Función para copiar un estudiante
Estudiante copiarEstudiante(const Estudiante *original) {
    return *original;
}

// Función para imprimir los datos de un estudiante
void imprimirEstudiante(const Estudiante *estudiante) {
    printf("Nombre: %s, Edad: %d, Promedio: %.2f\n",
           estudiante->nombre, estudiante->edad, estudiante->promedio);
}

// Función para agregar un estudiante a la lista
bool agregarEstudiante(Estudiante **lista, int *cantidad, const Estudiante *nuevo) {
    Estudiante *temp = realloc(*lista, (*cantidad + 1) * sizeof(Estudiante));
    if (!temp) return false;

    *lista = temp;
    (*lista)[*cantidad] = *nuevo;
    (*cantidad)++;
    return true;
}

// Función para eliminar un estudiante de la lista
bool eliminarEstudiante(Estudiante **lista, int *cantidad, int indice) {
    if (indice < 0 || indice >= *cantidad) return false;

    for (int i = indice; i < *cantidad - 1; i++) {
        (*lista)[i] = (*lista)[i + 1];
    }

    Estudiante *temp = realloc(*lista, (*cantidad - 1) * sizeof(Estudiante));
    if (temp || *cantidad - 1 == 0) {
        *lista = temp;
        (*cantidad)--;
    }
    return true;
}

// Función para liberar la memoria de la lista
void liberarLista(Estudiante **lista, int *cantidad) {
    free(*lista);
    *lista = NULL;
    *cantidad = 0;
}
