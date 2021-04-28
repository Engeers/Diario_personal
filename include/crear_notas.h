/**
 * @file Crear_notas.h
 * @author your name (Engeers Odalis Rossis)
 * @brief 
 * @version 0.1
 * @date 2021-04-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
struct crear //struct
{
    char titulo[100];
    char cuerpo[1000];
    int year;
    int day;
    int month;
    bool lleno; // true lleno; false vacio.
};

/**
 * @brief Esta funcion me va a indicar que si puedo crear notas y podre guardar notas.
 * 
 * @return true me va abrir todo correctamente si no hay un valor fuera del codigo
 * @return false no se va a ejecutar si introduces el valor indicado.
 */
bool crear_nots();

/**
 * @brief esta funcion me va a imprimir en el historial
 * 
 */
void save_notas();