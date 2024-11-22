cmake_minimum_required(VERSION 3.29)
project(Programacion_estructurada C)

set(CMAKE_C_STANDARD 11)

include_directories(estudiante)

add_executable(Programacion_estructurada
    estudiante/estudiante.c
    estudiante/estudiante.h
    main.c
        union/union.h
        union/union.c)
