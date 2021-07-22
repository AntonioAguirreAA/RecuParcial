#ifndef CHOFERES_H_
#define CHOFERES_H_

#include "LinkedList.h"

typedef struct
{
	int id;
	char nombre[101];
	int edad;
	char vehiculo[101];
}Chofer;

Chofer* chofer_new();
Chofer* chofer_newParametros(char* idStr,char* nombreStr,char* edadStr,char* vehiculoStr);

int chofer_setId(Chofer* this,int id);
int chofer_getId(Chofer* this,int* id);

int chofer_setNombre(Chofer* this,char* nombre);
int chofer_getNombre(Chofer* this,char* nombre);

int chofer_setEdad(Chofer* this,int edad);
int chofer_getEdad(Chofer* this,int* edad);

int chofer_setVehiculo(Chofer* this,char* vehiculo);
int chofer_getVehiculo(Chofer* this,char* vehiculo);

void chofer_findNombre(LinkedList* this,int id,char* nombre);

int chofer_filtrarAutoAnios(void* pChofer);

int chofer_contarEdadCombi(void* pChofer);
int chofer_contarCombi(void* pChofer);

#endif /* CHOFERES_H_ */
