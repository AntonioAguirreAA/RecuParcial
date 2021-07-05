/*
 * veterinarios.h
 *
 *  Created on: 4 jul. 2021
 *      Author: Tony
 */

#ifndef VETERINARIOS_H_
#define VETERINARIOS_H_

typedef struct
{
	int isEmpty;
	int id; //PK
	char nombre[51];
	int turno; //1 - MAÑANA 0 - TARDE
}eVeterinario;

void MostrarListaVeterinarios(eVeterinario[],int);
int PedirVerificarIdVeterinario(eVeterinario[],int);

int ObtenerTurnoId(eVeterinario[],int,int);

#endif /* VETERINARIOS_H_ */
