#include "estudiante/estudiante.h"
#include "union/union.h"
#include <stdio.h>
#include <stdlib.h>

void menuEstudiantes();
void menuUniones();

int main() {
    int opcion;

    do {
        printf("\n1. Manejar estudiantes\n");
        printf("2. Manejar unión\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                menuEstudiantes();
                break;
            case 2:
                menuUniones();
                break;
            case 3:
                printf("Programa finalizado.\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 3);

    return 0;
}

// Menú para manejar estudiantes
void menuEstudiantes() {
    Estudiante *lista = NULL;
    int cantidad = 0;
    int opcion;

    do {
        printf("\n1. Agregar estudiante\n");
        printf("2. Ver estudiantes\n");
        printf("3. Eliminar estudiante\n");
        printf("4. Regresar\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            char nombre[50];
            int edad;
            float promedio;

            printf("Ingrese nombre: ");
            scanf(" %[^\n]", nombre);
            printf("Ingrese edad: ");
            scanf("%d", &edad);
            printf("Ingrese promedio: ");
            scanf("%f", &promedio);

            Estudiante nuevo = crearEstudiante(nombre, edad, promedio);
            if (agregarEstudiante(&lista, &cantidad, &nuevo)) {
                printf("Estudiante agregado exitosamente.\n");
            } else {
                printf("Error al agregar estudiante.\n");
            }
        } else if (opcion == 2) {
            printf("\nLista de estudiantes:\n");
            for (int i = 0; i < cantidad; i++) {
                printf("%d. ", i + 1);
                imprimirEstudiante(&lista[i]);
            }
        } else if (opcion == 3) {
            int indice;
            printf("Ingrese el índice del estudiante a eliminar: ");
            scanf("%d", &indice);

            if (eliminarEstudiante(&lista, &cantidad, indice - 1)) {
                printf("Estudiante eliminado exitosamente.\n");
            } else {
                printf("Índice inválido.\n");
            }
        }
    } while (opcion != 4);

    liberarLista(&lista, &cantidad);
}

// Menú para manejar uniones
void menuUniones() {
    MiUnion miUnion;
    int opcion;

    do {
        printf("\n1. Asignar valor entero\n");
        printf("2. Asignar valor flotante\n");
        printf("3. Asignar valor cadena\n");
        printf("4. Imprimir valor\n");
        printf("5. Regresar\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            int valor;
            printf("Ingrese un entero: ");
            scanf("%d", &valor);
            asignarEntero(&miUnion, valor);
            printf("Valor entero asignado.\n");
        } else if (opcion == 2) {
            float valor;
            printf("Ingrese un flotante: ");
            scanf("%f", &valor);
            asignarFlotante(&miUnion, valor);
            printf("Valor flotante asignado.\n");
        } else if (opcion == 3) {
            char cadena[50];
            printf("Ingrese una cadena: ");
            scanf(" %[^\n]", cadena);
            asignarCadena(&miUnion, cadena);
            printf("Cadena asignada.\n");
        } else if (opcion == 4) {
            printf("¿Qué tipo desea imprimir? (entero/flotante/cadena): ");
            char tipo[10];
            scanf("%s", tipo);
            imprimirUnion(&miUnion, tipo);
        }
    } while (opcion != 5);
}
