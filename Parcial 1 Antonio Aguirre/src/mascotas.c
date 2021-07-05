/*
 * mascotas.c
 *
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "funciones.h"
#include "mascotas.h"
#include "inputs.h"

#define DISPONIBLE 1
#define OCUPADO 0

/**
 * @fn void MostrarListaMascotas(eMascota[], int)
 * @brief Lista todas las mascotas
 *
 * @param listaMascotas
 * @param tamMascotas
 */
void MostrarListaMascotas(eMascota listaMascotas[],int tamMascotas)
{
	int i;

	printf("\nID   |Nombre   |Edad  |Raza\n");
	printf("----------------------------\n");
	for (i=0 ; i<tamMascotas ; i++)
	{
		if (listaMascotas[i].isEmpty == OCUPADO)
		{
			printf("%5d|%11s|%5d|%s\n", listaMascotas[i].id,
					listaMascotas[i].nombreMascota,
					listaMascotas[i].edad,
					listaMascotas[i].raza);
		}
	}
}

/**
 * @fn int PedirVerificarIdMascota(eMascota[], int)
 * @brief Pide al usuario una ID de mascota y verifica que esta exista
 *
 * @param listaMascotas
 * @param tamMascotas
 * @return ID ingresada
 */
int PedirVerificarIdMascota(eMascota listaMascotas[],int tamMascotas)
{
	int idMascota;
	int flag;
	int i;
	flag = 0;
	MostrarListaMascotas(listaMascotas, tamMascotas);
	idMascota = getInt("Ingrese ID de la mascota (debe estar en la lista)");
	while (flag == 0)
	{
		for (i=0 ; i<tamMascotas ; i++)
		{
			if (listaMascotas[i].isEmpty == OCUPADO && listaMascotas[i].id == idMascota)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			idMascota = getInt("Ingrese una ID de mascota válida: ");
		}
	}

	return idMascota;
}
