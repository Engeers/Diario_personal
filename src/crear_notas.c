#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdint.h>
#ifdef __WIN32
#include <windows.h> /*se ha dectetado Windows. */
#include <conio.h>
#include <unistd.h>
#endif //__WIN32
#include "../include/login_diario.h"
#include <stdbool.h>
#include "../include/crear_notas.h"
#include <time.h>
#define MAX 1000 // sera el maximo de caracteres soportados

/**
 * @brief Constantes para el submenu de editar notas.
 * 
 */
enum
{
    TITULO = 1, /**Opcion para cambiar el titulo. */
    CUERPO,     /**Opcion para editiar el cuerpo. */
    ANIO,       /**Opcion para editar el anio. */
    MES,        /**Opcion para modificar el mes. */
    DIA         /**Para cambiar el dia. */
};

struct crear notas[MAX];

/**Para almacenar el input del usuario con fgets. */
char line[sizeof(double)];

void save_notas()
{
    clear_screen();

    for (size_t i = 0; i < MAX; i++)
    {
        if (notas[i].lleno)
            printf("Nuevo diario\n"
                   "%s\n%s\n%d %d %d\n",
                   notas[i].titulo, notas[i].cuerpo, notas[i].year, notas[i].day,
                   notas[i].month,
                   "\n ====================");
    }
}

bool crear_nots()
{
    char line[sizeof(double)];
    int opc; //variable para opcion de salir de crear nota

    for (size_t i = 0; i < MAX; i++) //condiciones para opciones de crea_nots
    {
        clear_screen();

        /**Verifica que la estructura este vacia. */
        if (!notas[i].lleno)
        {
            printf("Titulo/Nombre: ");
            fgets(notas[i].titulo, sizeof(notas[i].titulo), stdin);
            notas[i].titulo[strcspn(notas[i].titulo, "\n")] = 0;

            printf("Cuerpo/Notas: ");
            fgets(notas[i].cuerpo, sizeof(notas[i].cuerpo), stdin);
            notas[i].cuerpo[strcspn(notas[i].cuerpo, "\n")] = 0;

            printf("year: ");
            fgets(line, sizeof(line), stdin);
            sscanf(line, "%d", &notas[i].year);

            printf("day: ");
            fgets(line, sizeof(line), stdin);
            sscanf(line, "%d", &notas[i].day);

            printf("month: ");
            fgets(line, sizeof(line), stdin);
            sscanf(line, "%d", &notas[i].month);

            notas[i].lleno = true;
        }

        printf("si quieres continuar presiona 1\n");
        printf("Si no quieres continuar presiona 0\n");
        scanf("%d", &opc);
        getchar();

        switch (opc) //switch para decidir si se quiere continuar presionando s y n si se quiere terminar la ejecucion
        {
        case 1:
            return crear_nots(); //con esto me terminara la ejecucion de crear_nots

        case 0:
            return false; //con esta me continuara la ejecucion de crear_nots

        default:
            printf("Haz colocado una letra inavalida\n");
            break;
        }

        break; // Sale del loop.
    }

    return -1; // Error.
}

//! Editar notas

void editar_notas()
{
    clear_screen();

    /**Almacenara la opcion del usuario. */
    unsigned eleccion;
    /**Pedira el titulo de una estructura. */
    printf("Ingrese el titulo de la nota a editar: ");
    fgets(line, sizeof(line), stdin);
    line[strcspn(line, "\n")] = 0;

    /**
     * @brief Primera verificara que haya una estructura llena; cuando encuentre
     * una llena verificara el titulo de ella con el titulo introducido por el
     * usuario.
     * 
     */
    for (size_t i = 0; i < MAX; i++)
    {
        /**Verifica que haya una estructura llena. */
        if (notas[i].lleno)
        {
            /**Verifica que los titulos sean iguales. */
            if (!strcmp(notas[i].titulo, line))
            {
                /**Loop para q el input este dentro del rango 1-5. */
                while (true)
                {
                    printf("Que quieres modificar: \n"
                           "1- Titulo.\n"
                           "2- Cuerpo.\n"
                           "3- Anio.\n"
                           "4- Mes.\n"
                           "5- Dia.\n"
                           "Eleccion: ");
                    fgets(line, sizeof(line), stdin);
                    sscanf(line, "%u", &eleccion);

                    /**
                     * @brief Si la eleccion esta fuera de rango imprimira un mensaje,
                     * notificandolo, y volvera a pedir el input.
                     * 
                     */
                    if (eleccion < TITULO || eleccion > DIA)
                    {
                        clear_screen();
                        printf("Elige una opcion correcta\n");
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }

                clear_screen();

                /**Vere que opcion elige el usuario. */
                switch (eleccion)
                {
                case TITULO:
                    printf("Titulo/Nombre: ");
                    fgets(notas[i].titulo, sizeof(notas[i].titulo), stdin);
                    notas[i].titulo[strcspn(notas[i].titulo, "\n")] = 0;

                    break;
                case CUERPO:
                    printf("Cuerpo/Notas: ");
                    fgets(notas[i].cuerpo, sizeof(notas[i].cuerpo), stdin);
                    notas[i].cuerpo[strcspn(notas[i].cuerpo, "\n")] = 0;
                    break;

                case ANIO:
                    printf("year: ");
                    fgets(line, sizeof(line), stdin);
                    sscanf(line, "%d", &notas[i].year);
                    break;

                case DIA:
                    printf("day: ");
                    fgets(line, sizeof(line), stdin);
                    sscanf(line, "%d", &notas[i].day);
                    break;

                case MES:
                    printf("month: ");
                    fgets(line, sizeof(line), stdin);
                    sscanf(line, "%d", &notas[i].month);
                    break;
                default:
                    fprintf(stderr, "Esto luce como un error!\n");
                    exit(-1);
                }

                clear_screen();

                printf("\aModificacion exitosa!\n");
                getchar();
                return (void)login_menu();
            }
        }
    }

    fprintf(stderr, "\aNo hay ninguna entrada de diaro!\n"
                    "Intenta anadir uno primero!\n");
    getchar();
    return (void)login_menu();
}
