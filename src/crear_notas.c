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
#include "../include/crear_notas.h"
#include <time.h>
#define MAX 1000 // sera el maximo de caracteres soportados
struct crear notas[MAX];
char _temp = true;
char temp;
char titulo[100];
char cuerpo[1000];
char year[sizeof(double)];
char line[sizeof(double)];
char day[31];
char month[12];

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
