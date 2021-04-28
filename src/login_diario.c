#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdint.h>
#ifdef __WIN32
#include <windows.h> /* Windows dectetado. */
#include <conio.h>
#else
#include <unistd.h>
#endif //__WIN32
#include "../include/login_diario.h"
#include <stdbool.h>
#include "../include/crear_notas.h"
//El usuario actual que esta ejecutando el programa.
static struct actual_user actual_user;
enum menu_opciones;

//El liempo que durara el copilador parado.
const short time = 2;

#define LONGITUD 50

void set_password(char *const password)
{
	char c;
	for (size_t i = 0; (c = getchar()); ++i)
	{
		if (c == '\n' || c == '\r')
		{
			password[i] = '\0';
			return;
		}
		else if (c == 8)

            {
                if (i > 0)
                {
                    printf("\b \b"); //mueve el cursor hacia la izquierda
                }
            }
            else if (i < LONGITUD)
                        
                {
                    printf("*");
                    password[i] = c;
                   
                }
    }

}

// *-*-*-*-*-*-*-*-*-*-*-*- Login para el Menu de notas *-*-*-*-*-*-*-*-*-*-*-*-

int login_menu()
{
	/**Este es el inicio, luego de entrar al sistema
	 * 
	 */
	unsigned options = 0;

	fflush(stdout);
	system("cls||clear");

	// mensaje de espera en la carga.
	printf("Por favor espere...\n");
	system_loading(time);

	/**+-+-+-+-+-+-Empieza el menu+-+-+-+-+-+- */

	for (size_t i = 3; i > 0 || options > 5; --i)
	{
		system("cls||clear");

		if ((options <= 0 && i != 3) || options > 5)
			printf("Debes eligir una opcion correcta!!!\n"
				   "Porque, pues te quedan %zu intentos.\n",
				   i);

		printf("\n\tSeleccione una opcion:  \n"
			   "\n\t1- Crear notas \n"
			   "\t2- Editar notas   \n"
			   "\t3- Historial      \n"
			   "\t4- Salir \n"); // El usuario saldra cuando presione 4.
		scanf(" %d", &options);
		getchar();

		if (options >= CREAR_NOTAS && options <= SALIR)
			break;
	}

	switch (options)
	{
	case CREAR_NOTAS:
		if (!crear_nots())
			login_menu();
    break; 
	case EDIT_NOTAS:
    break; //nada por el momento
	case HISTORIAL:
		save_notas();
		break; 
	case SALIR:
		fflush(stdout);
		system("cls||clear");
		printf("Saliendo...\n");
		exit(0);
	default:
		fprintf(stderr, "Verifica que hayas ingresado una contraseña valida o "
						"envia un issue detallando el posible bug.\n");
		break;
	}
	putchar('\n');
	return 0;
}

// *-*-*-*-*-*-*-*-*-*-*-*- Login para el Menu de user *-*-*-*-*-*-*-*-*-*-*-*-
/** IMPORTANT: Esta debe ser la primiera pantalla que el usario vea. */

int login_user()
{

	/**Donde se guardara la opcion eligida por el usuario. */
	unsigned temp = 0;
	int temp_validate;
	/** Cuenta las veces que intenta el usuario*/
	int chances = 0;

	// Para que no se sienta la espera.
	printf("Iniciando...\n");
	system_loading(time);
	do
	{ /**Mientras el usuario no entre una opcion valida el loop se repetira. */
		printf("\n\t\t\t\aLogin de Diario/Notas\n"
			   "\tSi ya estas registrado ingresa (2).\n"
			   "\tSi eres nuevo ingresa (1).\n"
			   "\t(1) Registrarse.\n"
			   "\t(2) Logearse.\n"
			   "\tOpcion: ");
		scanf(" %d", &temp);
		getchar();
		system("cls||clear");

		/**Imprime al usuario que escoga una opcion correcta. */
		if (temp > 2)
			printf("Selecciona una opcion correcta.\n");
	} while (temp > 2);

	/**Dependiendo del valor en temp, el usuario se logeara o registrara. */
	switch (temp)
	{
	case 1: // Registrarse.

		printf("\t\t\aAqui podras registrarte. Ingrese lo siguiente:\n"
			   "Nombre: ");
		fgets(actual_user.username, sizeof(actual_user.username), stdin);
		// Cambiar \n con \0
		actual_user.username[strcspn(actual_user.username, "\n")] = 0;
		(void)get_username();
		printf("Clave: ");
		set_password(actual_user.password);

		system("clear||cls");
		// Anade al usuario.
		//add_user(actual_user.username, actual_user.password, actual_user.is_admin);

		// Luego entra en un blucle hasta que presione la letra de salir.
		for (; login_menu();)
			;

		return 0;

	case 2: //Es para Logearse.
		for (size_t i = 3; i > 0;)
		{
			printf("\t\t\aEstas actualmente en el login. digita tus "
				   "datos para iniciar\n\n");

			if (i != 3 && i >= 1)
				printf("\t\t\aUyyyyyy! Tus datos no se encuetran en la base de datos.\n"
					   "\t\aAsegurate de haber ingresado tus datos correctamente. "
					   "Intentos restantes: %zu \n\n",
					   i);

			printf("\t\aNombre: ");
			fgets(actual_user.username, sizeof(actual_user.username), stdin);
			// Cambiar \n con \0
			actual_user.username[strcspn(actual_user.username, "\n")] = 0;

			printf("\t\aClave: ");
			set_password(actual_user.password);

			/**temp_validate = validate(actual_user.username, actual_user.password);
			if (!temp_validate)
			// TODO: mostrar el login menu y/o mostrar un mensaje de que se ha logeado.
			{
				for (; login_menu();)
					;
				return 0;
			}
			else if (temp_validate == -1)//esto valida si estas loguearte pero no estabas logueado por 1ra vez.
			{
				system("cls||clear");
				printf("\t\t\aUps! Esta es la primera vez que estas ejucutando el programa.\n\n"
					   "\tPor favor registrarse primero.\n"
					   "\tPresione cualquier tecla para finalizar la ejecucion...\n");
				getchar();
				exit(-1);
			}
			else
			{
				--i;
			}
			// Limpia la pantalla para la segunda vuelta.
			system("cls||clear"); */
		}
	}

	return -1; // Error
}

void system_loading(int time)
{
#ifdef __WIN32
	time += time * 1000;
#endif //__WIN32

	for (size_t i = 0; i <= 100; i++)
	{
		if (i % 25 == 0)
		{
			fflush(stdout);
			printf("Cargando.. %zu%% .\r", i); /* impresion de 
			carga */
		}
		else
			continue;

		if (i == 100)
		{
			fflush(stdout);
			system("cls||clear");
		};
#ifdef __WIN32
		Sleep(time);
#else
		sleep(time);
#endif //__WIN32
	}
}

char *get_username()
{
	return actual_user.username;
}

void clear_screen()
{
	fflush(stdout);
	system("cls||clear");
}