/*
 *	Parcial 1 - Programacion
 *
 *	Antonio Aguirre 1°C
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "funciones.h"

#define DISPONIBLE 1
#define OCUPADO 0

#define TAMSERVICIOS 3
#define TAMTRABAJOS 5
#define TAMMASCOTAS 5
#define TAMVETERINARIOS 3

/**
 * @fn int main(void)
 * @brief Funcion main, contiene un case que ejecuta la opcion elegida del menú.
 *
 * @return
 */
int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	int idTrabajoGlobal;
	int flagOpcionesAlta;

	flagOpcionesAlta = 0;

	idTrabajoGlobal=0;

	eServicio listaServicios[TAMSERVICIOS] = {{OCUPADO,20000,"Corte",250},
			{OCUPADO,20001,"Desparasitado",300},
			{OCUPADO,20002,"Castrado",400}};

	eTrabajo listaTrabajos[TAMTRABAJOS];

	eMascota listaMascotas[TAMMASCOTAS] = {{OCUPADO,15,"Tyrone",2,"Collie"},
			{OCUPADO,16,"Hanna",7,"Caniche"},
			{OCUPADO,17,"Rocco",8,"Labrador"},
			{OCUPADO,18,"Claudio",6,"Rottweiler"},
			{OCUPADO,19,"Mancha",9,"Dalmata"}};

	eVeterinario listaVeterinarios[TAMVETERINARIOS] = {{OCUPADO,1,"Claudia",1},
														{OCUPADO,2,"Marcelo",0},
														{OCUPADO,3,"Hernan",1}};

	InicializarTrabajos(listaTrabajos,TAMTRABAJOS);

	while (opcion != 13)
	{
		opcion = MostrarMenu();
		switch (opcion)
		{
			case 1:
				idTrabajoGlobal++;
				flagOpcionesAlta = AltaTrabajos(listaTrabajos, TAMTRABAJOS, listaServicios, TAMSERVICIOS, idTrabajoGlobal,listaMascotas,TAMMASCOTAS,listaVeterinarios,TAMVETERINARIOS);
				break;

			case 2:
				if (flagOpcionesAlta == 1)
				{
					ModificacionTrabajo(listaTrabajos, TAMTRABAJOS,listaServicios, TAMSERVICIOS,listaMascotas,TAMMASCOTAS,listaVeterinarios,TAMVETERINARIOS);
				}	else	{
					printf("Debe dar de alta algún trabajo primero.");
				}
				break;

			case 3:
				if (flagOpcionesAlta == 1)
				{
					BajaTrabajo(listaTrabajos, TAMTRABAJOS,listaMascotas,TAMMASCOTAS,listaServicios, TAMSERVICIOS,listaVeterinarios,TAMVETERINARIOS);
					flagOpcionesAlta = VerificarVacio(listaTrabajos, TAMTRABAJOS);
				}	else	{
					printf("Debe dar de alta algún trabajo primero.");
				}
				break;

			case 4:
				if (flagOpcionesAlta == 1)
				{
					OrdenarTrabajoAnio(listaTrabajos,TAMTRABAJOS,listaMascotas,TAMMASCOTAS);
					MostrarListaTrabajos(listaTrabajos, TAMTRABAJOS,listaMascotas,TAMMASCOTAS,listaServicios, TAMSERVICIOS,listaVeterinarios,TAMVETERINARIOS);
				}	else	{
					printf("Debe dar de alta algún trabajo primero.");
				}
				break;

			case 5:
				MostrarListaServicios(listaServicios,TAMSERVICIOS);
				break;

			case 6:
				if (flagOpcionesAlta == 1)
				{
					MostrarPrecioTotal(listaTrabajos, TAMTRABAJOS,listaServicios, TAMSERVICIOS);
				}	else	{
					printf("Debe dar de alta algún trabajo primero.");
				}
				break;

			case 7:
				if (flagOpcionesAlta == 1)
				{
					OrdenarTrabajoNombre(listaTrabajos, TAMTRABAJOS,listaMascotas,TAMMASCOTAS);
					MostrarListaTrabajos(listaTrabajos, TAMTRABAJOS,listaMascotas,TAMMASCOTAS,listaServicios, TAMSERVICIOS,listaVeterinarios,TAMVETERINARIOS);
				}	else	{
					printf("Debe dar de alta algún trabajo primero.");
				}
				break;

			case 8:
				if (flagOpcionesAlta == 1)
				{
					ServiciosConMasTrabajos(listaTrabajos, TAMTRABAJOS,listaServicios, TAMSERVICIOS);
				}	else	{
					printf("Debe dar de alta algún trabajo primero.");
				}
				break;

			case 9:
				if (flagOpcionesAlta == 1)
				{
					listarServiciosMascotas(listaTrabajos,TAMTRABAJOS,listaMascotas,TAMMASCOTAS,listaServicios,TAMSERVICIOS);
				}	else	{
					printf("Debe dar de alta algún trabajo primero.");
				}
				break;

			case 10:
				if (flagOpcionesAlta == 1)
				{
					PromedioEdadServicio(listaTrabajos,TAMTRABAJOS,listaMascotas,TAMMASCOTAS,listaServicios,TAMSERVICIOS);
				}	else	{
					printf("Debe dar de alta algún trabajo primero.");
				}
				break;

			case 11:
				if (flagOpcionesAlta == 1)
				{
					TrabajosTurnoManana(listaTrabajos, TAMTRABAJOS,listaServicios, TAMSERVICIOS,listaMascotas,TAMMASCOTAS,listaVeterinarios,TAMVETERINARIOS);
				}	else	{
					printf("Debe dar de alta algún trabajo primero.");
				}
				break;

			case 12:
				if (flagOpcionesAlta == 1)
				{
					ListarVeterinariosMascotas(listaTrabajos, TAMTRABAJOS,listaServicios, TAMSERVICIOS,listaMascotas,TAMMASCOTAS,listaVeterinarios,TAMVETERINARIOS);
				}	else	{
					printf("Debe dar de alta algún trabajo primero.");
				}
				break;
		}
	}

	return EXIT_SUCCESS;
}
