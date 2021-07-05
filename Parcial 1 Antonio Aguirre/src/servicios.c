/*
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "funciones.h"
#include "servicios.h"
#include "inputs.h"

#define DISPONIBLE 1
#define OCUPADO 0

/**
 * @fn void MostrarListaServicios(eServicio[], int)
 * @brief Muestra una lista con todos los registros de la lista de servicios.
 *
 * @param listaServicios
 * @param tamServicios
 */
void MostrarListaServicios(eServicio listaServicios[],int tamServicios)
{
	int i;

	printf("\nID   |Descripcion    |Precio\n");
	printf("----------------------------\n");
	for (i=0 ; i<tamServicios ; i++)
	{
		if (listaServicios[i].isEmpty == OCUPADO)
		{
			printf("%3d|%15s|$%5d\n", listaServicios[i].id,
									listaServicios[i].descripcion,
									listaServicios[i].precio);
		}
	}
}

/**
 * @fn int PedirVerificarIdServicio(eServicio[], int)
 * @brief Pide la id del servicio al usuario y verifica que esta exista.
 *
 * @param listaServicios
 * @param tamServicios
 * @return
 */
int PedirVerificarIdServicio(eServicio listaServicios[],int tamServicios)
{
	int idServicio;
	int flag;
	int i;
	flag = 0;
	MostrarListaServicios(listaServicios, tamServicios);
	idServicio = getInt("Ingrese ID del servicio (debe estar en la lista)");
	while (flag == 0)
	{
		for (i=0 ; i<tamServicios ; i++)
		{
			if (listaServicios[i].isEmpty == OCUPADO && listaServicios[i].id == idServicio)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			idServicio = getInt("Ingrese una ID de servicio válida: ");
		}
	}

	return idServicio;
}
