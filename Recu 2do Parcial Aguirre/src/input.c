/*
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

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
	char checkInt[151] = "";
	int esNumero;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]",checkInt);

	esNumero=validarNumero(checkInt);

	while(esNumero==-1 || strlen(checkInt)==0)
	{
		printf("Ingrese un numero válido: ");
		fflush(stdin);
		scanf("%[^\n]",checkInt);

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
	char checkInt[151] = "";
	int esNumero;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]",checkInt);

	esNumero=validarNumero(checkInt);

	while(esNumero==-1 || strlen(checkInt)==0)
	{
		printf("Ingrese un numero válido: ");
		fflush(stdin);
		scanf("%[^\n]",checkInt);

		esNumero=validarNumero(checkInt);
	}
	aux = atof(checkInt);

	return aux;
}

void getString(char cadena[],char mensaje[])
{
	strcpy(cadena,"");
	int esCaracter;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]",cadena);

	esCaracter=validarCaracteres(cadena);

	while(esCaracter==-1 || strlen(cadena)==0)
	{
		printf("Ingrese una cadena valida: ");
		fflush(stdin);
		scanf("%[^\n]",cadena);

		esCaracter=validarCaracteres(cadena);
	}
}
