/*
 *
 */

#ifndef SERVICIOS_H_
#define SERVICIOS_H_

typedef struct
{
	int isEmpty;
	int id;//PK
	char descripcion[25];
	int precio;
}eServicio;

typedef struct
{
	int idServicio;//PK
	int cantidadTrabajos;
}eAuxiliarServicios;

void MostrarListaServicios(eServicio[],int);

int PedirVerificarIdServicio(eServicio[],int);

#endif /* SERVICIOS_H_ */
