/*
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "funciones.h"
#include "trabajos.h"
#include "inputs.h"

#define DISPONIBLE 1
#define OCUPADO 0

/**
 * @fn void InicializarTrabajos(eTrabajo[], int)
 * @brief Determina todos los registros de la lista de trabajos como DISPONIBLE.
 *
 * @param listaTrabajos
 * @param tamTrabajos
 */
void InicializarTrabajos (eTrabajo listaTrabajos[],int tamTrabajos)
{
	int i;
	for(i=0 ; i<tamTrabajos ; i++)
	{
		listaTrabajos[i].isEmpty = DISPONIBLE;
	}
}

/**
 * @fn int VerificarVacio(eTrabajo[], int)
 * @brief Verifica si hay registros ingresados en la lista de trabajos.
 *
 * @param listaTrabajos
 * @param tamTrabajos
 * @return Retorna 0 si no hay espacio
 * 1 si hay espacio
 */
int VerificarVacio(eTrabajo listaTrabajos[],int tamTrabajos)
{
	int flagVacio;
	int i;

	flagVacio = 0;

	for (i=0 ; i<tamTrabajos ; i++)
	{
		if(listaTrabajos[i].isEmpty == OCUPADO)
		{
			flagVacio = 1;
			break;
		}
	}

	return flagVacio;
}

/**
 * @fn int pedirVerificarId(eTrabajo[], int)
 * @brief Pide una ID al usuario y verifica que esta exista
 *
 * @param listaTrabajos
 * @param tamTrabajos
 * @return INDEX de la ID ingresada
 */
int pedirVerificarId(eTrabajo listaTrabajos[],int tamTrabajos)
{
	int id;
	int flag;
	int i;
	flag = 0;
	id = getInt("Ingrese ID del trabajo (debe estar en la lista): ");
	while (flag == 0)
	{
		for (i=0 ; i<tamTrabajos ; i++)
		{
			if (listaTrabajos[i].isEmpty == OCUPADO && listaTrabajos[i].id == id)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			id = getInt("Ingrese una ID válida: ");
		}
	}

	return i;
}
