#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdint.h>
#ifdef __WIN32
#include <windows.h> /* Windows dectetado. */
#include <conio.h>
#include <unistd.h>
#endif //__WIN32
#include "../include/login_diario.h"
#include <stdbool.h>
#include "../include/Crear_notas.h"
#define MAX 1000
struct crear_notas notas[MAX];
void save_notas()
{
    for (size_t i = 0; i < MAX; i++)
    {
        printf("Nuevo diario\n"
        "%s\n %s\n %f\n",notas[i].titulo,notas[i].cuerpo,notas[i].fecha,
        "\n ====================");
    }
    
}

    bool crear_notas()
{
    char _temp = true;
    char temp;
    char titulo[100]; //cantidad maxima del titulo// 
    char cuerpo[1000]; //cuerpo con maximo de escritura 
    float fecha[10]; // valor limite de la fecha en flotante

    clear_screen();
    for (size_t i = 0; i < MAX; i++)
    {
        printf("Titulo/Nombre: ");
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = 0;
    strcpy(notas[i].titulo,titulo);

    printf("Cuerpo/Notas: ");
    fgets(cuerpo, sizeof(cuerpo), stdin);
    cuerpo[strcspn(cuerpo, "\n")] = 0;
    strcpy(notas[i].cuerpo,cuerpo);

    printf("Cantidad del producto: ");
    fgets(fecha, sizeof(fecha), stdin);
    fecha[strcspn(fecha, "\n")] = 0;
    strcpy(notas[i].fecha,fecha);
    }



    clear_screen();
    printf("Deseas arreglar algo?\n"
           "Para si 's'; cualquier otro tecla para no...\n%d",
           suplir_producto[0].full);
    for (; (c = getchar()) != '\n' || (c = getchar()) != '\r';)
        if (c == 's' || c == 'S')
            return crear_notas();
        else
            return false;

    return false;
}
