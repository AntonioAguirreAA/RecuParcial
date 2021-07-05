/*
 * trabajos.h
 */

#ifndef TRABAJOS_H_
#define TRABAJOS_H_

#include "fechas.h"

typedef struct
{
	int isEmpty;
	int id;//PK
	int idMascota;//FK
	int idServicio;//FK
	eFecha fecha;
	int idVeterinario;//FK
}eTrabajo;

void InicializarTrabajos (eTrabajo[],int);

int VerificarVacio(eTrabajo[],int);

int pedirVerificarId(eTrabajo[],int);

#endif /* TRABAJOS_H_ */
