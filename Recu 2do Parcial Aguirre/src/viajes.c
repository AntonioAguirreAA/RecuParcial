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

Viaje* viajes_new()
{
    Viaje* pAux;
	pAux = (Viaje*)malloc(sizeof(Viaje));
	return pAux;
}

Viaje* viajes_newParametros(char* idStr,char* diaStr,char* mesStr,char* anioStr,char* pasajerosStr,char* idChoferStr,char* kilometrosStr)
{
    int id;
	Fecha fecha;
    int pasajeros;
    int idChofer;
    int kilometros;

	Viaje* aux;

	//Crea Chofer en memoria dinamica
	aux = viajes_new();

	//Parseo de datos
	id = atoi(idStr);
	fecha.dia = atoi(diaStr);
    fecha.mes = atoi(mesStr);
    fecha.anio = atoi(anioStr);
    pasajeros = atoi(pasajerosStr);
    idChofer = atoi(idChoferStr);
    kilometros = atoi(kilometrosStr);

	//Set en el espacio creado
	if(viajes_setId(aux,id)==-1 ||
		viajes_setFecha(aux,&fecha)==-1 ||
		viajes_setPasajeros(aux,pasajeros)==-1 ||
		viajes_setIdChofer(aux,idChofer)==-1 ||
        viajes_setKilometros(aux,kilometros)==-1)
	{
		return NULL;
	}

	return aux;
}

//ID
int viajes_setId(Viaje* this,int id)
{
	int exito = -1;

	if(this != NULL)
	{
		exito = 0;
		this->id = id;
	}

	return exito;
}
int viajes_getId(Viaje* this,int* id)
{
	int exito = -1;

	if(this != NULL && id != NULL)
	{
		exito = 0;
		*id = this->id;
	}

	return exito;
}

//Fecha
int viajes_setFecha(Viaje* this,Fecha* fecha)
{
    int exito = -1;

    if(this != NULL && fecha != NULL)
    {
        exito = 0;
        this->fecha.dia = fecha->dia;
        this->fecha.mes = fecha->mes;
        this->fecha.anio = fecha->anio;
    }

    return exito;
}
int viajes_getFecha(Viaje* this,Fecha* fecha)
{
    int exito = -1;

    if(this != NULL && fecha != NULL)
    {
        exito = 0;
        fecha->dia = this->fecha.dia;
        fecha->mes = this->fecha.mes;
        fecha->anio = this->fecha.anio;
    }

    return exito;
}

//Pasajeros
int viajes_setPasajeros(Viaje* this,int pasajeros)
{
	int exito = -1;

	if(this != NULL)
	{
		exito = 0;
		this->pasajeros = pasajeros;
	}

	return exito;
}
int viajes_getPasajeros(Viaje* this,int* pasajeros)
{
	int exito = -1;

	if(this != NULL && pasajeros != NULL)
	{
		exito = 0;
		*pasajeros = this->pasajeros;
	}

	return exito;
}

//IdChofer
int viajes_setIdChofer(Viaje* this,int idChofer)
{
	int exito = -1;

	if(this != NULL)
	{
		exito = 0;
		this->idChofer = idChofer;
	}

	return exito;
}
int viajes_getIdChofer(Viaje* this,int* idChofer)
{
	int exito = -1;

	if(this != NULL && idChofer != NULL)
	{
		exito = 0;
		*idChofer = this->idChofer;
	}

	return exito;
}

//Kilometros
int viajes_setKilometros(Viaje* this,int kilometros)
{
	int exito = -1;

	if(this != NULL)
	{
		exito = 0;
		this->kilometros = kilometros;
	}

	return exito;
}
int viajes_getKilometros(Viaje* this,int* kilometros)
{
	int exito = -1;

	if(this != NULL && kilometros != NULL)
	{
		exito = 0;
		*kilometros = this->kilometros;
	}

	return exito;
}

int viajes_filtrarJulioKm(void* pViaje)
{
	int retorno = 0;
	Fecha fechaAux;
	int kilometrosAux;

	if(pViaje!=NULL)
	{
		viajes_getFecha(pViaje,&fechaAux);
		viajes_getKilometros(pViaje,&kilometrosAux);
		if(fechaAux.anio>=2021 &&
			fechaAux.mes>=7 &&
			kilometrosAux>70)
			{
				retorno = 1;
			}
	}

	return retorno;
}

int viajes_countKmAntonio(void* pViaje)
{
	int retorno = 0;
	int idChofer;

	if(pViaje!=NULL)
	{
		viajes_getIdChofer(pViaje,&idChofer);
		if(idChofer==1)
		{
			viajes_getKilometros(pViaje,&retorno);
		}
	}

	return retorno;
}
