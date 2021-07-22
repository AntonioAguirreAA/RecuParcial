/*
 * controller.h
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"
#include "parser.h"
#include "choferes.h"
#include "viajes.h"

int controller_loadChoferesCsv(LinkedList* listaChoferes);

int controller_loadViajesCsv(LinkedList* listaViajes);

int controller_listChoferes(LinkedList* listaChoferes);

int controller_listViajes(LinkedList* listaViajes,LinkedList* listaChoferes);

int controller_filtroUno(LinkedList* listaViajes,LinkedList* listaFiltrada,LinkedList* listaChoferes);

int controller_filtroDos(LinkedList* listaFiltrada,LinkedList* listaChoferes);

int controller_saveFilter(LinkedList* listaFiltrada, int opcion);

int controller_countKmAntonio(LinkedList* listaViajes);

int controller_promCombiChoferes(LinkedList* listaChoferes);

#endif /* CONTROLLER_H_ */
