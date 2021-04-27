/**
 * @file Crear_notas.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-25
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
    int year[10];
    int day[365];
    int month[12];
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