/*
 *	Programa: Recuperatorio Segundo Parcial
 *
 *	Objetivo:
 *		Crear una aplicaci�n que permita gestionar mediante dos listas
 *		enlazadas, dos entidades relacionadas entre s�.
 *		1. Cargar ambas listas desde sus respectivos archivos csv.
 *		2. Listar los datos relacionados. No se deben visualizar Ids.
 *		3. Utilizar la funci�n ll_filter para realizar dos filtros distintos.
 *		4. Utilizar la funci�n ll_count para realizar dos c�lculos (contador/acumulador)
 *		5. Guardar en un archivo csv los datos de alguno de los dos filtros del punto 3.
 *
 *	Version 0.1
 *
 *	Autor: Antonio Aguirre
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "controller.h"
#include "LinkedList.h"
#include "parser.h"
#include "choferes.h"
#include "viajes.h"
#include "functions.h"


int main(void)
{
	setbuf(stdout, NULL);
	int opcion;

	opcion = 0;

	LinkedList* listaChoferes;
	listaChoferes = ll_newLinkedList();

	LinkedList* listaViajes;
	listaViajes = ll_newLinkedList();

	LinkedList* listaFiltrada;
	listaFiltrada = ll_newLinkedList();

	while(opcion!=9)
	{
		opcion = ShowMenu();
		switch (opcion)
		{
		case 1:
			if(controller_loadChoferesCsv(listaChoferes)==0)
			{
				printf("\nLista choferes cargada.\n");
			}	else	{
				printf("\nError al cargar la lista\n");
			}
			break;

		case 2:
			if(ll_isEmpty(listaChoferes)==1)
			{
				printf("\nDebe cargar la lista de choferes primero.\n");
			}	else	{
				if(controller_loadViajesCsv(listaViajes)==0)
				{
					printf("\nLista viajes cargada.\n");
				}	else	{
					printf("\nError al cargar la lista de viajes.\n");
				}
			}
			break;

		
		case 3:
			if(controller_listChoferes(listaChoferes)==-1)
			{
				printf("\nDebe cargar una lista primero.\n");
			}
			break;

		case 4:
			if(controller_listViajes(listaViajes,listaChoferes)==-1)
			{
				printf("\nDebe cargar una lista primero.\n");
			}
			break;

		case 5:
			if(ll_isEmpty(listaViajes)==0)
			{
				controller_filtroUno(listaViajes,listaFiltrada,listaChoferes);
			}	else	{
				printf("\nDebe cargar la lista de viajes primero.\n");
			}
			break;

		case 6:
			if(ll_isEmpty(listaChoferes)==0)
			{
				controller_filtroDos(listaFiltrada,listaChoferes);
			}	else	{
				printf("\nDebe cargar la lista de choferes primero.\n");
			}
			break;

		case 7:
			if(ll_isEmpty(listaViajes)==0)
			{
				controller_countKmAntonio(listaViajes);
			}	else	{
				printf("\nDebe cargar la lista de viajes primero.\n");
			}
			break;

		case 8:
			if(ll_isEmpty(listaChoferes)==0)
			{
				controller_promCombiChoferes(listaChoferes);
			}	else	{
				printf("\nDebe cargar la lista de choferes primero.\n");
			}
			break;
		}
	}

	printf("\nFin del programa.\n");

	return EXIT_SUCCESS;
}
