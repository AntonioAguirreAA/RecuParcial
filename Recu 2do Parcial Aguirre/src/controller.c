/*
 * controller.c
 */
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
#include "functions.h"

int controller_loadChoferesCsv(LinkedList* listaChoferes)
{
    int exito = -1;
    char path[101];
    FILE* pArchivo;

    if(listaChoferes != NULL)
    {
        ll_clear(listaChoferes);

        getString(path,"Ingrese el nombre del archivo: ");
        pArchivo = fopen(path,"r");

        exito = parser_choferesFromText(pArchivo,listaChoferes);

        fclose(pArchivo);
    }

    return exito;
}

int controller_loadViajesCsv(LinkedList* listaViajes)
{
    int exito = -1;
    char path[101];
    FILE* pArchivo;

    if(listaViajes != NULL)
    {
        ll_clear(listaViajes);

        getString(path,"Ingrese el nombre del archivo: ");
        pArchivo = fopen(path,"r");

        exito = parser_viajesFromText(pArchivo,listaViajes);

        fclose(pArchivo);
    }

    return exito;
}

int controller_listChoferes(LinkedList* listaChoferes)
{
    int exito = -1;
    Chofer* pAux;
    int len;
    int i;

    char nombre[101];
    int edad;
    char vehiculo[101];

    if(ll_isEmpty(listaChoferes)==0)
    {
        exito = 0;

        printf("\n    Nombre    | Edad | Vehiculo\n");
        printf("--------------------------------\n");
        len = ll_len(listaChoferes);
        for(i=0;i<len;i++)
        {
            pAux = ll_get(listaChoferes,i);
            chofer_getNombre(pAux,nombre);
            chofer_getEdad(pAux,&edad);
            chofer_getVehiculo(pAux,vehiculo);

            printf("%14s|%6d|%10s\n",nombre,edad,vehiculo);
        }
    }

    return exito;
}

int controller_listViajes(LinkedList* listaViajes,LinkedList* listaChoferes)
{
    int exito = -1;
    Viaje* pAux;
    int len;
    int i;

    Fecha fecha;
    int pasajeros;
    int idChofer;
    char chofer[101];
	int kilometros;

    if(ll_isEmpty(listaViajes)==0)
    {
        exito = 0;

        printf("\n   Fecha  | Pasajeros |    Chofer    | Km\n");
        printf("-----------------------------------------\n");
        len = ll_len(listaViajes);
        for(i=0;i<len;i++)
        {
            pAux = ll_get(listaViajes,i);
            viajes_getFecha(pAux,&fecha);
            viajes_getPasajeros(pAux,&pasajeros);
            viajes_getIdChofer(pAux,&idChofer);
            viajes_getKilometros(pAux,&kilometros);

            chofer_findNombre(listaChoferes,idChofer,chofer);

            printf("%4d/%d/%d|%11d|%14s|%4d\n",fecha.dia,
                                                fecha.mes,
                                                fecha.anio,
                                                pasajeros,
                                                chofer,
                                                kilometros);
        }
    }

    return exito;
}

int controller_filtroUno(LinkedList* listaViajes,LinkedList* listaFiltrada,LinkedList* listaChoferes)
{
    int exito = -1;

    if(listaViajes != NULL && listaFiltrada != NULL)
    {
        ll_clear(listaFiltrada);
        listaFiltrada = ll_filter(listaViajes,viajes_filtrarJulioKm);
        controller_listViajes(listaFiltrada,listaChoferes);
        if(getIntLimit("Desea guardarlo como archivo? 1)si 2)no : ","Seleccione una opcion correcta: ",1,2)==1)
        {
            controller_saveFilter(listaFiltrada,1);
			printf("\nLista guardada con el nombre filtroViajes.csv\n");					
        }
        exito = 0;
    }

    return exito;
}

int controller_filtroDos(LinkedList* listaFiltrada,LinkedList* listaChoferes)
{
    int exito = -1;

    if(listaFiltrada!=NULL && listaChoferes!=NULL)
    {
        ll_clear(listaFiltrada);
        listaFiltrada = ll_filter(listaChoferes,chofer_filtrarAutoAnios);
        controller_listChoferes(listaFiltrada);
        if(getIntLimit("Desea guardarlo como archivo? 1)si 2)no : ","Seleccione una opcion correcta: ",1,2)==1)
        {
            controller_saveFilter(listaFiltrada,0);
			printf("\nLista guardada con el nombre filtroChoferes.csv\n");					
        }
        exito = 0;
    }

    return exito;
}

int controller_saveFilter(LinkedList* listaFiltrada, int opcion)
{
    int exito = -1;
    FILE* pArchivo;

    if(listaFiltrada != NULL)
    {
        if(opcion == 1)
        {            
            pArchivo = fopen("filtroViajes.csv","w");
            if(function_saveViajeList(listaFiltrada,pArchivo)==0)
            {
                exito = 0;
            }
            fclose(pArchivo);
        }   else    {
            pArchivo = fopen("filtroChoferes.csv","w");
            if(function_saveChoferList(listaFiltrada,pArchivo)==0)
            {
                exito = 0;
            }
            fclose(pArchivo);
        }
    }

    return exito;
}

int controller_countKmAntonio(LinkedList* listaViajes)
{
	int exito = -1;
    int contador;

    if(listaViajes!=NULL)
    {
    	exito = 0;
        contador = ll_count(listaViajes,viajes_countKmAntonio);
        printf("\nCantidad de km recorridos por Antonio: %d km\n",contador);
    }
    return exito;
}

int controller_promCombiChoferes(LinkedList* listaChoferes)
{
    int exito;
    int contador;
    int acumulador;
    float promedio;

    if(listaChoferes!=NULL)
    {
        exito = 0;
        contador = ll_count(listaChoferes,chofer_contarCombi);
        acumulador = ll_count(listaChoferes,chofer_contarEdadCombi);
        promedio = ((float)acumulador / contador);
        printf("El promedio de edad de choferes de combi es de: %0.2f",promedio);
    }
    return exito;
}
