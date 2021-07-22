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

int parser_choferesFromText(FILE* pArchivo,LinkedList* listaChoferes)
{
    int exito = -1;

    char id[101];
    char nombre[101];
    char edad[101];
    char vehiculo[101];
    Chofer* pAux;

    if(pArchivo!= NULL && listaChoferes!=NULL)
    {
        //Lectura en blanco de la cabecera
        fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,edad,vehiculo); 

        //Lectura de datos
        while(!feof(pArchivo))
        {
            if(fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,edad,vehiculo)!=0)
            {
                pAux = chofer_newParametros(id,nombre,edad,vehiculo);
                exito = ll_add(listaChoferes,pAux);
            } 
        }
    }

    return exito;
}

int parser_viajesFromText(FILE* pArchivo,LinkedList* listaViajes)
{
    int exito = -1;

    char id[101];
    char dia[101];
    char mes[101];
    char anio[101];
    char pasajeros[101];
    char idChofer[101];
    char kilometros[101];
    Viaje* pAux;

    if(pArchivo!= NULL && listaViajes!=NULL)
    {
        //Lectura en blanco de la cabecera
        fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,dia,pasajeros,idChofer,kilometros); 

        //Lectura de datos
        while(!feof(pArchivo))
        {
            if(fscanf(pArchivo,"%[^,],%[^/]/%[^/]/%[^,],%[^,],%[^,],%[^\n]\n",id,dia,mes,anio,pasajeros,idChofer,kilometros)!=0)
            {
                pAux = viajes_newParametros(id,dia,mes,anio,pasajeros,idChofer,kilometros);
                exito = ll_add(listaViajes,pAux);
            } 
        }
    }

    return exito;
}
