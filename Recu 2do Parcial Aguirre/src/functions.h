/*
 * functions.h
 *
 *
 */

#ifndef SRC_FUNCTIONS_H_
#define SRC_FUNCTIONS_H_

#include "Controller.h"
#include "LinkedList.h"
#include "parser.h"
#include "choferes.h"
#include "viajes.h"

int ShowMenu ();

int function_saveChoferList(LinkedList* listaFiltrada,FILE* pArchivo);
int function_saveViajeList(LinkedList* listaFiltrada,FILE* pArchivo);

#endif /* SRC_FUNCTIONS_H_ */
