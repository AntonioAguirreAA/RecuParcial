/*
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

int validarNumero(char checkInt[])
{
	int exito = 0;
	int len;

	len = strlen(checkInt);

	for(int i=0 ; i<len ; i++)
	{
		if(!isdigit(checkInt[i]))
		{
			exito = -1;
			break;
		}
	}

	return exito;
}

int validarCaracteres(char checkInt[])
{
	int exito = 0;
	int len;

	len = strlen(checkInt);

	for(int i=0 ; i<len ; i++)
	{
		if(isdigit(checkInt[i]))
		{
			exito = -1;
			break;
		}
	}

	return exito;
}

int getInt(char mensaje[])
{
	int aux;
	char checkInt[151];
	int esNumero;

	printf("%s", mensaje);
	scanf("%s",checkInt);

	esNumero=validarNumero(checkInt);

	while(esNumero==-1)
	{
		printf("Ingrese un numero válido: ");
		scanf("%s",checkInt);

		esNumero=validarNumero(checkInt);
	}
	aux = atoi(checkInt);

	return aux;
}

int getIntLimit(char mensaje[],char mensajeError[],int min,int max)
{
	int aux;

	aux = getInt(mensaje);
	while(aux<min || aux>max)
	{
		aux = getInt(mensajeError);
	}

	return aux;
}

float getFloat(char mensaje[])
{
	float aux;
	char checkInt[151];
	int esNumero;

	printf("%s", mensaje);
	scanf("%s",checkInt);

	esNumero=validarNumero(checkInt);

	while(esNumero==-1)
	{
		printf("Ingrese un numero válido: ");
		scanf("%s",checkInt);

		esNumero=validarNumero(checkInt);
	}
	aux = atof(checkInt);

	return aux;
}

void getString(char mensaje[], char cadena[])
{
	int esCaracter;

	printf("%s", mensaje);
	scanf("%s",cadena);

	esCaracter=validarCaracteres(cadena);

	while(esCaracter==-1)
	{
		printf("Ingrese una cadena sin numeros: ");
		scanf("%s",cadena);

		esCaracter=validarCaracteres(cadena);
	}
}
