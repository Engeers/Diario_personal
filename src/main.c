/************************************************************/
/*           Programacion para mecatronicos                 */
/*  Nombre: Engeers Odalis Rossis de la cruz                */
/*  Matricula: 2020-10573                                   */
/*  Seccion: Miercoles                                      */
/*  Nombre proyecto final sistema de gestion de Diario/notas*/
/*  Fecha: 22/04/2021                                       */
/************************************************************/

/**
 * @file main.c
 * @author your name Engeers O. Rossis De la Cruz
 * @brief  
 * @version 0.1
 * @date 2021-04-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/login_diario.h"
#include "../include/login_diario.h"
#include <stdbool.h>
#include "../include/crear_notas.h"

int main(int argc, char *const argv[])
{
#ifdef __linux__
	printf("\033[100m"
		   "\033[34m"); // Cambia el color de la letra en linux.
						 // Para mas info: https://opensource.com/article/19/9/linux-terminal-colors
#else
	system("color 20"); //cambia el color, el numero cambia el fondo
						// y la letra cambia el color de letra
						// https://www.geeksforgeeks.org/how-to-print-colored-text-in-c/
#endif // __linux__
	system("cls||clear");//limpiar pantalla
	/**
	 * TODO: Hacer algo.
	 */
	if (argv[1] ? !strcmp(argv[1], "1234") : 0)
		login_menu();
	else
		login_user();

	return 0;
}