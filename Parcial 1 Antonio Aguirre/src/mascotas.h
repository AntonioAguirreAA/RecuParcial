/*
 * mascotas.h
 *
 *
 */

#ifndef MASCOTAS_H_
#define MASCOTAS_H_

typedef struct
{
	int isEmpty;
	int id;//PK
	char nombreMascota[26];
	int edad;
	char raza[20];
}eMascota;

void MostrarListaMascotas(eMascota[],int);

int PedirVerificarIdMascota(eMascota[],int);

#endif /* MASCOTAS_H_ */
