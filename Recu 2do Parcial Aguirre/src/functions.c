#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "Controller.h"
#include "LinkedList.h"
#include "parser.h"
#include "choferes.h"
#include "viajes.h"

int ShowMenu ()
{
	int option;

	printf("\n------------MENU DE OPCIONES------------\n");
	printf("1) Cargar lista de choferes.\n");
	printf("2) Cargar lista de viajes.\n");
	printf("3) Listar choferes.\n");
	printf("4) Listar viajes.\n");
	printf("5) Filtro: Viajes a partir de julio 2021, con mas de 70km\n");
	printf("6) Filtro: Choferes con auto de mas de 25 años.\n");
	printf("7) Cantidad de kilometros realizados por Antonio\n");
	printf("8) Promedio de edad de choferes con combi\n");
	printf("9) Salir\n");
	option = getIntLimit("Elija una opcion: ","Ingrese una opcion valida: ",1,9);

	return option;
}

int function_saveChoferList(LinkedList* listaFiltrada,FILE* pArchivo)
{
	int exito = -1;
	int len;
	int i;
	Chofer* aux;
	int id;
	char nombre[101];
	int edad;
	char vehiculo[101];

	if(listaFiltrada != NULL && pArchivo != NULL)
	{
		exito = 0;
		fprintf(pArchivo,"id,nombre,edad,vehiculo\n");
		len = ll_len(listaFiltrada);
		printf("%d",len);
		for(i=0;i<len;i++)
		{
			aux = ll_get(listaFiltrada,i);

			chofer_getId(aux,&id);
			chofer_getNombre(aux,nombre);
			chofer_getEdad(aux,&edad);
			chofer_getVehiculo(aux,vehiculo);

			fprintf(pArchivo,"%d,%s,%d,%s\n",id,nombre,edad,vehiculo);
		}
	}

	return exito;
}

int function_saveViajeList(LinkedList* listaFiltrada,FILE* pArchivo)
{
	int exito = -1;
	int len;
	int i;
	Viaje* aux;
	int id;
	Fecha fecha;
	int pasajeros;
	int idChofer;
	int kilometros;

	if(listaFiltrada != NULL && pArchivo != NULL)
	{
		exito = 0;
		fprintf(pArchivo,"id,fecha,pasajeros,idchofer,kilometros\n");
		len = ll_len(listaFiltrada);
		for(i=0;i<len;i++)
		{
			aux = ll_get(listaFiltrada,i);

			viajes_getId(aux,&id);
			viajes_getFecha(aux,&fecha);
			viajes_getPasajeros(aux,&pasajeros);
			viajes_getIdChofer(aux,&idChofer);
			viajes_getKilometros(aux,&kilometros);

			fprintf(pArchivo,"%d,%d/%d/%d,%d,%d,%d\n",id,fecha.dia,fecha.mes,fecha.anio,pasajeros,idChofer,kilometros);
		}
	}

	return exito;
}
