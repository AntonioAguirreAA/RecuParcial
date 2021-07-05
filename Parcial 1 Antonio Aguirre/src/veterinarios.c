/*
 * veterinarios.c
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "funciones.h"
#include "veterinarios.h"
#include "inputs.h"

#define DISPONIBLE 1
#define OCUPADO 0

#define MANANA 1
#define TARDE 0

/**
 * @fn void MostrarListaVeterinarios(eVeterinario[], int)
 * @brief Lista todos los veterinarios
 *
 * @param listaVet
 * @param tamVet
 */
void MostrarListaVeterinarios(eVeterinario listaVet[],int tamVet)
{
	int i;
	char turno[51];

	printf("\n| ID |   Nombre  |   Turno  |\n");
	printf("-----------------------------\n");
	for(i=0;i<tamVet;i++)
	{
		if(listaVet[i].isEmpty == OCUPADO)
		{
			if(listaVet[i].turno == MANANA)
			{
				strcpy(turno,"Mañana");
			}	else	{
				strcpy(turno,"Tarde");
			}
			printf("|%4d|%11s|%10s|\n",listaVet[i].id,
									listaVet[i].nombre,
									turno);
		}
	}
}

/**
 * @fn int PedirVerificarIdVeterinario(eVeterinario[], int)
 * @brief Pide al usuario una ID de veterinario y comprueba que esta exista
 *
 * @param listaVet
 * @param tamVet
 * @return ID ingresada
 */
int PedirVerificarIdVeterinario(eVeterinario listaVet[],int tamVet)
{
	int idVet;
	int flag;
	int i;
	flag = 0;
	MostrarListaVeterinarios(listaVet,tamVet);
	idVet = getInt("Ingrese ID del veterinario (debe estar en la lista)");
	while (flag == 0)
	{
		for (i=0 ; i<tamVet ; i++)
		{
			if (listaVet[i].isEmpty == OCUPADO && listaVet[i].id == idVet)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			idVet = getInt("Ingrese una ID de veterinario válida: ");
		}
	}

	return idVet;
}

/**
 * @fn int ObtenerTurnoId(eVeterinario[], int, int)
 * @brief Obtiene el turno segun la ID ingresada
 *
 * @param listaVet
 * @param tamVet
 * @param idSolicitada
 * @return Turno
 */
int ObtenerTurnoId(eVeterinario listaVet[],int tamVet,int idSolicitada)
{
	int turno;
	int i;

	for(i=0;i<tamVet;i++)
	{
		if(listaVet[i].id==idSolicitada)
		{
			turno = listaVet[i].turno;
			break;
		}
	}

	return turno;
}
