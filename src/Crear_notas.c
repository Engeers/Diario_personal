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
struct Crear_notas;


    bool crear_notas()
{
    char _temp = true;
    char temp;
    char titulo[100]; //cantidad maxima del titulo// 
    char cuerpo[1000]; //cuerpocon maximo de escritura 
    float fecha[10]; // valor limite de la fecha en flotante

    clear_screen();
    printf("Titulo/Nombre: ");
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = 0;

    printf("Cuerpo/Notas: ");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%u", &precio);

    printf("Cantidad del producto: ");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%u", &cantidad);

    for (size_t i = 0; i < MAX_COMPRAS && _temp; i++)
    {
        if (!suplir_producto[i].full)
        {
            suplir_producto[i].full = true;
            suplir_producto[i].id = i + 1;
            strcpy(suplir_producto->producto_titulo, titulo);
            suplir_producto[i].precio = precio;
            suplir_producto[i].cantidad = cantidad;

            if (!save_product(suplir_producto[i].producto_titulo,
                              suplir_producto[i].precio, suplir_producto[i].cantidad))
                fprintf(stderr, "problema dectetado.\n");

            _temp = false;
        }
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
}