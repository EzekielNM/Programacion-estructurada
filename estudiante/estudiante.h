//
// Created by Ezekiel on 22/11/2024.
//
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <stdbool.h>

// Definición de la estructura Estudiante
typedef struct {
    char nombre[50];
    int edad;
    float promedio;
} Estudiante;

// Declaraciones de funciones
Estudiante crearEstudiante(const char *nombre, int edad, float promedio);
Estudiante copiarEstudiante(const Estudiante *original);
void imprimirEstudiante(const Estudiante *estudiante);
bool agregarEstudiante(Estudiante **lista, int *cantidad, const Estudiante *nuevo);
bool eliminarEstudiante(Estudiante **lista, int *cantidad, int indice);
void liberarLista(Estudiante **lista, int *cantidad);

#endif // ESTUDIANTE_H
