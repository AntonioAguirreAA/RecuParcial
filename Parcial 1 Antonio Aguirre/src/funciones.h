/*
 *
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include "trabajos.h"
#include "fechas.h"
#include "servicios.h"
#include "mascotas.h"
#include "inputs.h"
#include "veterinarios.h"

int MostrarMenu();

int BuscarLibre(eTrabajo[],int);
eTrabajo IngresoTrabajo(eServicio[],int,int,eMascota[],int,eVeterinario[],int);
int AltaTrabajos(eTrabajo[],int,eServicio[],int,int,eMascota[],int,eVeterinario[],int);

int ModificacionTrabajo(eTrabajo[],int,eServicio[],int,eMascota[],int,eVeterinario[],int);

int BajaTrabajo(eTrabajo[],int,eMascota[],int,eServicio[],int,eVeterinario[],int);

int OrdenarTrabajoNombre(eTrabajo[],int,eMascota[],int);

void ObtenerNombreMascota(eMascota[],int,int,char[]);
void ObtenerServicio(eServicio[],int,int,char[]);
void ObtenerVeterinario(eVeterinario[],int,int,char[]);
int OrdenarTrabajoAnio(eTrabajo[],int,eMascota[],int);
void MostrarListaTrabajos(eTrabajo[],int,eMascota[],int,eServicio[],int,eVeterinario[],int);

int MostrarPrecioTotal(eTrabajo[],int,eServicio[],int);

int ObtenerCantidades(eTrabajo[],int,eServicio[],int,eAuxiliarServicios[]);
int ServiciosConMasTrabajos(eTrabajo[],int,eServicio[],int);

void BuscarConcatenarMascotasServicio(eTrabajo[],int,eMascota[],int,int,char[]);
int listarServiciosMascotas(eTrabajo[],int,eMascota[],int,eServicio[],int);

float SacarPromedio(eTrabajo[],int,eMascota[],int,int);
int PromedioEdadServicio(eTrabajo[],int,eMascota[],int,eServicio[],int);

int TrabajosTurnoManana(eTrabajo[],int,eServicio[],int,eMascota[],int,eVeterinario[],int);

void BuscarConcatenarMascotasVeterinario(eTrabajo[],int,eMascota[],int,int,char[]);
int ListarVeterinariosMascotas(eTrabajo[],int,eServicio[],int,eMascota[],int,eVeterinario[],int);

#endif /* FUNCIONES_H_ */
