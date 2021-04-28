#include "../include/users.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Numero maximo para el array.
#define MAX_USERS 50

const char *file_name = "usarios.txt";

struct Users user[MAX_USERS];

void __init_usersarr__()
{
    for (size_t i = 0; i < MAX_USERS; i++)
    {
        user[i].full = 0;
    }
}

void __save_into_file__(const char *username, const char *password)
{
    // Creacion del archivo en modo escritura.
    FILE *__fp = fopen(file_name, "w");

    // Escribe el username y el password dentro del fichero.
    fprintf(__fp, "%s\t", username);
    fprintf(__fp, "%s\n", password);

    // Cierra el fichero.
    fclose(__fp);
}

void add_user(const char *username, const char *password)
{
    for (size_t i = 0; i < MAX_USERS; ++i)
    {
        if (user[i].full == 0)
        {
            // Copia los usuarios y contraseñas a sus repectivas struct.
            strcpy(user[i].username, username);
            strcpy(user[i].password, password);

            // Guarda los datos de los usuarios.
            __save_into_file__(user[i].username, user[i].password);
        }
    }
}

int validate_user(const char *username, const char *password)
{
    for (size_t i = 0; i < MAX_USERS; i++)
    {
        if (!strcmp(username, user[i].username) &&
            !strcmp(password, user[i].password))
            return registered;
        else if (strcmp(username, user[i].username))
            return invalid_user;
        else if (strcmp(password, user[i].password))
            return invalid_password;
    }

    return -1;
}

int validate_from_file(const char *username, const char *password)
{
    char c;
    char self_user[255], self_pass[255];
    short to_password = 0;
    /**Abre el archivo en modo lectura */
    FILE *__fp = fopen(file_name, "r");
    if (!__fp)
    {
        fprintf(stderr, "Error el abrir el archivo.");
        exit(-1);
    }

    for (size_t i = 0; (c = fgetc(__fp)) != EOF; ++i)
    {

        if (c != '\n' && c != '\t')
        {
            self_user[i] = c;
        }
        else
        {
            self_user[i] = '\0';
            break;
        }
    }

    for (size_t i = 0; (c = fgetc(__fp)) != EOF; i++)
    {
        if (c != '\t' && c != '\n')
        {
            self_pass[i] = c;
        }
        else
        {
            self_pass[i] = '\0';
            break;
        }
    }

    if (!strcmp(self_user, username) && !strcmp(self_pass, password))
        return 1;
    else
        return 0;
}