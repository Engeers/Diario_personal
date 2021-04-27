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
char day[31];
char month[12];
void save_notas()
{
    for (size_t i = 0; i < MAX; i++)
    {
        printf("Nuevo diario\n"
               "%s\n %s\n %d %d %d\n",
               notas[i].titulo, notas[i].cuerpo, notas[i].year, notas[i].day,
               notas[i].month,
               "\n ====================");
    }
}

bool crear_nots()
{
    char _temp = true;
    char temp;
    char titulo[100];  //cantidad maxima del titulo//
    char cuerpo[1000]; //cuerpo con maximo de escritura
    int year[sizeof(double)];
    char day[31];
    char month[12];
    int opc; //variable para opcion de salir de crear nota
    clear_screen();
    for (size_t i = 0; i < MAX; i++)//condiciones para opciones de crea_nots 
    {
        do
        {
            printf("Titulo/Nombre: ");
            fgets(titulo, sizeof(titulo), stdin);
            titulo[strcspn(titulo, "\n")] = 0;
            strcpy(notas[i].titulo, titulo);

            printf("Cuerpo/Notas: ");
            fgets(cuerpo, sizeof(cuerpo), stdin);
            cuerpo[strcspn(cuerpo, "\n")] = 0;
            strcpy(notas[i].cuerpo, cuerpo);

            printf("year: ");
            fgets(year, sizeof(year), stdin);
            sscanf(year, "%d",year);

            printf("day: ");
            fgets(day, sizeof(day), stdin);
            sscanf(day, "%d",day);

            printf("month: ");
            fgets(month, sizeof(month), stdin);
            sscanf(month, "%d",month);

            printf("si quieres continuar presiona 1\n");
            printf("Si no quieres continuar presiona 0\n");
            scanf("%d", opc);
            getchar();
        }while (opc != '1' );
        switch (opc)//switch para decidir si se quiere continuar presionando s y n si se quiere terminar la ejecucion
        {
        case 1:
        exit(EXIT_SUCCESS);//con esto me terminara la ejecucion de crear_nots

        case 0: 
        return crear_nots();//con esta me continuara la ejecucion de crear_nots

        default: 
        printf("Haz colocado una letra inavalida\n");
            break;
        }
    }
    return false;
}
