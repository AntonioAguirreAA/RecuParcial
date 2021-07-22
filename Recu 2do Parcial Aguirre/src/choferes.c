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

Chofer* chofer_new()
{
	Chofer* pAux;
	pAux = (Chofer*)malloc(sizeof(Chofer));
	return pAux;
}

/**
 * @fn Chofer chofer_newParametros*(char*, char*, char*, char*)
 * @brief Recibe los datos leidos del csv en strings, los parsea y los asigna a un espacio creado en memoria dinamica
 *
 * @param idStr
 * @param nombreStr
 * @param edadStr
 * @param vehiculoStr
 * @return puntero a Chofer creado con los datos pasados como parametros = OK
 * NULL = no se pudo crear espacio en memoria dinamica o algun parametro era NULL
 */
Chofer* chofer_newParametros(char* idStr,char* nombreStr,char* edadStr,char* vehiculoStr)
{
	int id;
	int edad;

	Chofer* aux;

	//Crea Chofer en memoria dinamica
	aux = chofer_new();

	//Parseo de datos
	id = atoi(idStr);
	edad = atoi(edadStr);

	//Set en el espacio creado
	if(chofer_setId(aux,id)==-1 ||
		chofer_setNombre(aux,nombreStr)==-1 ||
		chofer_setEdad(aux,edad)==-1 ||
		chofer_setVehiculo(aux,vehiculoStr)==-1)
	{
		return NULL;
	}

	return aux;
}

//ID
int chofer_setId(Chofer* this,int id)
{
	int exito = -1;

	if(this != NULL)
	{
		exito = 0;
		this->id = id;
	}

	return exito;
}
int chofer_getId(Chofer* this,int* id)
{
	int exito = -1;

	if(this != NULL && id != NULL)
	{
		exito = 0;
		*id = this->id;
	}

	return exito;
}

//NOMBRE
int chofer_setNombre(Chofer* this,char* nombre)
{
	int exito = -1;

	if(this != NULL && nombre != NULL)
	{
		exito = 0;
		strcpy(this->nombre , nombre);
	}

	return exito;
}
int chofer_getNombre(Chofer* this,char* nombre)
{
	int exito = -1;

	if(this != NULL && nombre != NULL)
	{
		exito = 0;
		strcpy(nombre , this->nombre);
	}

	return exito;
}

//EDAD
int chofer_setEdad(Chofer* this,int edad)
{
	int exito = -1;

	if(this != NULL)
	{
		exito = 0;
		this->edad = edad;
	}

	return exito;
}
int chofer_getEdad(Chofer* this,int* edad)
{
	int exito = -1;

	if(this != NULL && edad != NULL)
	{
		exito = 0;
		*edad = this->edad;
	}

	return exito;
}

//VEHICULO
int chofer_setVehiculo(Chofer* this,char* vehiculo)
{
	int exito = -1;

	if(this != NULL && vehiculo != NULL)
	{
		exito = 0;
		strcpy(this->vehiculo , vehiculo);
	}

	return exito;
}
int chofer_getVehiculo(Chofer* this,char* vehiculo)
{
	int exito = -1;

	if(this != NULL && vehiculo != NULL)
	{
		exito = 0;
		strcpy(vehiculo , this->vehiculo);
	}

	return exito;
}

void chofer_findNombre(LinkedList* this,int id,char* nombre)
{
	int len;
	int i;
	int idAux;
	Chofer* pAux;

	len = ll_len(this);

	strcpy(nombre,"-");

	for(i=0;i<len;i++)
	{
		pAux = ll_get(this,i);
		chofer_getId(pAux,&idAux);
		if(idAux == id)
		{
			chofer_getNombre(pAux,nombre);
		}
	}
}

int chofer_filtrarAutoAnios(void* pChofer)
{
	int retorno = 0;
	int edadAux;
	char vehiculoAux[101];

	if(pChofer!=NULL)
	{
		chofer_getEdad(pChofer,&edadAux);
		chofer_getVehiculo(pChofer,vehiculoAux);
		if(edadAux >= 25 && strcmp(vehiculoAux,"Auto")==0)
		{
			retorno = 1;
		}
	}

	return retorno;
}

int chofer_contarEdadCombi(void* pChofer)
{
	int retorno = 0;
	char vehiculo[101];

	if(pChofer!=NULL)
	{
		chofer_getVehiculo(pChofer,vehiculo);
		if(strcmp(vehiculo,"Combi")==0)
		{
			chofer_getEdad(pChofer,&retorno);
		}
	}

	return retorno;
}

int chofer_contarCombi(void* pChofer)
{
	int retorno = 0;
	char vehiculo[101];

	if(pChofer!=NULL)
	{
		chofer_getVehiculo(pChofer,vehiculo);
		if(strcmp(vehiculo,"Combi")==0)
		{
			retorno = 1;
		}
	}

	return retorno;
}
