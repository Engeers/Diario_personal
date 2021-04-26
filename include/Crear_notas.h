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

/**
 * @brief Esta funcion me va a indicar que si puedo crear notas y podre guardar notas.
 * 
 * @return true me va abrir todo correctamente si no hay un valor fuera del codigo
 * @return false no se va a ejecutar si introduces el valor indicado.
 */
bool crear_notas();

struct crear_notas 
{
    char titulo[100];
    char cuerpo[1000];
    float fecha[10];
};

/**
 * @brief esta funcion me va a imprimir en el historial
 * 
 */
void save_notas();