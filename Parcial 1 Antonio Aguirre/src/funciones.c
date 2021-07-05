/*
 *
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "funciones.h"

#define DISPONIBLE 1
#define OCUPADO 0

/**
 * @fn int MostrarMenu()
 * @brief Muestra el menú principal y lee la eleccion del usuario
 *
 * @return Opcion a ejecutar
 */
int MostrarMenu()
{
	int opcion;
	printf("\n1. Alta\n");
	printf("2. Modificacion\n");
	printf("3. Baja\n");
	printf("4. Mostrar trabajos\n");
	printf("5. Mostrar servicios\n");
	printf("6. Precio total por servicio\n");
	printf("7. Listado por nombre\n");
	printf("8. Servicio/s con mas trabajos\n");
	printf("9. Listado de servicios con las mascotas que lo realizaron\n");
	printf("10. Promedio de edad de mascotas que realizaron un servicio\n");
	printf("11. Listado de trabajos realizados en el turno mañana\n");
	printf("12. Listado de veterinarios con las mascotas que atendieron\n");
	printf("13. Salir\n");
	opcion = getIntLimit("Ingrese una opcion: ","Ingrese una opcion valida.",1,13);
	return opcion;
}

/**
 * @fn int BuscarLibre(eTrabajo[], int)
 * @brief Busca el index de algun espacio disponible en la lista de trabajos
 *
 * @param listaTrabajos
 * @param tamTrabajos
 * @return indexDisponible
 * -1 si no hay espacio
 */
int BuscarLibre(eTrabajo listaTrabajos[],int tamTrabajos)
{
	int i;
	int indexDisponible;
	indexDisponible = -1;
	for (i=0 ; i<tamTrabajos ; i++)
	{
		if(listaTrabajos[i].isEmpty == DISPONIBLE)
		{
			indexDisponible = i;
			break;
		}
	}
	return indexDisponible;
}

/**
 * @fn eTrabajo IngresoTrabajo(eServicio[], int, int)
 * @brief Pide los datos de la nueva estructura al usuario.
 *
 * @param listaServicios
 * @param tamServicios
 * @param idTrabajoGlobal
 * @return eTrabajo con los datos ingresados
 */
eTrabajo IngresoTrabajo(eServicio listaServicios[],int tamServicios,int idTrabajoGlobal,eMascota listaMascotas[], int tamMascotas,eVeterinario listaVet[],int tamVet)
{
	eTrabajo trabajoIngresado;

	trabajoIngresado.isEmpty = OCUPADO;
	trabajoIngresado.id = idTrabajoGlobal;
	trabajoIngresado.idMascota = PedirVerificarIdMascota(listaMascotas, tamMascotas);
	trabajoIngresado.idServicio = PedirVerificarIdServicio(listaServicios, tamServicios);
	trabajoIngresado.fecha.dia = getIntLimit("Ingrese el dia: ","Ingrese un dia válido: ",1,31);
	trabajoIngresado.fecha.mes = getIntLimit("Ingrese el mes: ","Ingrese un mes válido: ",1,12);
	trabajoIngresado.fecha.anio = getInt("Ingrese el año: ");
	while (trabajoIngresado.fecha.anio < 2021)
	{
		trabajoIngresado.fecha.anio = getInt("Ingrese un año válido: ");
	}
	trabajoIngresado.idVeterinario = PedirVerificarIdVeterinario(listaVet,tamVet);
	return trabajoIngresado;
}

/**
 * @fn int AltaTrabajos(eTrabajo[], int, eServicio[], int, int)
 * @brief Verifica que haya lugar para ingresar registros y pide los datos o informa que no hay lugar
 *
 * @param listaTrabajos
 * @param tamTrabajos
 * @param listaServicios
 * @param tamServicios
 * @param idTrabajoGlobal
 * @return 0 si no hay espacio, 1 si se pudo agregar
 */
int AltaTrabajos(eTrabajo listaTrabajos[],int tamTrabajos,eServicio listaServicios[],int tamServicios,int idTrabajoGlobal,eMascota listaMascotas[], int tamMascotas,eVeterinario listaVet[],int tamVet)
{
	int exito = 0;
	int indexDisponible;
	indexDisponible = BuscarLibre(listaTrabajos,tamTrabajos);
	if (indexDisponible == -1)
	{
		printf("No hay espacio disponible para ingresar una nueva nacionalidad.\n");
	}	else	{
		listaTrabajos[indexDisponible] = IngresoTrabajo(listaServicios,tamServicios,idTrabajoGlobal,listaMascotas,tamMascotas,listaVet,tamVet);
		exito = 1;
	}
	return exito;
}

/**
 * @fn int ModificacionTrabajo(eTrabajo[], int, eServicio[], int)
 * @brief Pide un id para luego modificar el campo que desee el usuario.
 *
 * @param listaTrabajos
 * @param tamTrabajos
 * @param listaServicios
 * @param tamServicios
 * @return -
 */
int ModificacionTrabajo(eTrabajo listaTrabajos[],int tamTrabajos,eServicio listaServicios[], int tamServicios,eMascota listaMascotas[], int tamMascotas,eVeterinario listaVet[],int tamVet)
{
	int indexMod;
	int opcion;

	MostrarListaTrabajos(listaTrabajos,tamTrabajos,listaMascotas,tamMascotas,listaServicios,tamServicios,listaVet,tamVet);
	indexMod = pedirVerificarId(listaTrabajos,tamTrabajos);

	printf("\n¿Que campo desea modificar?\n");
	printf("1)Mascota 2)Servicio 3)Veterinario\n");
	opcion = getIntLimit("Ingrese una opcion: ","Ingrese una opcion válida: ",1,3);
	switch(opcion)
	{
		case 1:
			listaTrabajos[indexMod].idMascota = PedirVerificarIdMascota(listaMascotas, tamMascotas);
			break;

		case 2:
			listaTrabajos[indexMod].idServicio = PedirVerificarIdServicio(listaServicios, tamServicios);
			break;

		case 3:
			listaTrabajos[indexMod].idVeterinario = PedirVerificarIdVeterinario(listaVet,tamVet);
	}

	return 0;
}

/**
 * @fn int BajaTrabajo(eTrabajo[], int)
 * @brief Pide y verifica un id para eliminar ese registro.
 *
 * @param listaTrabajos
 * @param tamTrabajos
 * @return -
 */
int BajaTrabajo(eTrabajo listaTrabajos[],int tamTrabajos,eMascota listaMascotas[],int tamMascotas,eServicio listaServicios[],int tamServicios,eVeterinario listaVet[],int tamVet)
{
	int indexBaja;

	MostrarListaTrabajos(listaTrabajos,tamTrabajos,listaMascotas,tamMascotas,listaServicios,tamServicios,listaVet,tamVet);
	indexBaja = pedirVerificarId(listaTrabajos,tamTrabajos);
	listaTrabajos[indexBaja].isEmpty = DISPONIBLE;

	return 0;
}

/**
 * @fn void ObtenerNombreMascota(eMascota[], int, int, char[])
 * @brief Recorre la lista Mascotas y asigna el nombre de la id indicada
 *
 * @param listaMascotas
 * @param tamMascotas
 * @param idMascotaSolicitada
 * @param nombreMascota
 */
void ObtenerNombreMascota(eMascota listaMascotas[],int tamMascotas, int idMascotaSolicitada, char nombreMascota[])
{
	int i;

	for(i=0 ; i<tamMascotas ; i++)
	{
		if(idMascotaSolicitada == listaMascotas[i].id)
		{
			strcpy(nombreMascota,listaMascotas[i].nombreMascota);
			break;
		}
	}
}

/**
 * @fn void ObtenerServicio(eServicio[], int, int, char[])
 * @brief Recorre la lista Servicios y asigna la descripcion de la ID indicada
 *
 * @param listaServicios
 * @param tamServicios
 * @param idSolicitada
 * @param nombreServicio
 */
void ObtenerServicio(eServicio listaServicios[],int tamServicios,int idSolicitada,char nombreServicio[])
{
	int i;

	for(i=0;i<tamServicios;i++)
	{
		if(idSolicitada == listaServicios[i].id)
		{
			strcpy(nombreServicio,listaServicios[i].descripcion);
			break;
		}
	}
}

/**
 * @fn void ObtenerVeterinario(eVeterinario[], int, int, char[])
 * @brief Recorre la lista Veterinario y asigna el nombre de la ID indicada
 *
 * @param listaVet
 * @param tamVet
 * @param idSolicitada
 * @param nombre
 */
void ObtenerVeterinario(eVeterinario listaVet[],int tamVet,int idSolicitada,char nombre[])
{
	int i;

	for(i=0;i<tamVet;i++)
	{
		if(idSolicitada == listaVet[i].id)
		{
			strcpy(nombre,listaVet[i].nombre);
			break;
		}
	}
}

/**
 * @fn int OrdenarTrabajoAnio(eTrabajo[], int)
 * @brief Ordena la lista de trabajos por año y por nombre.
 *
 * @param listaTrabajos
 * @param tamTrabajos
 * @return -
 */
int OrdenarTrabajoAnio(eTrabajo listaTrabajos[],int tamTrabajos,eMascota listaMascotas[],int tamMascotas)
{
	int i;
	int j;
	eTrabajo aux;
	char nombreMascotaI[26];
	char nombreMascotaJ[26];

	for (i=1 ; i<tamTrabajos ; i++)
	{
		for (j=0 ; j<tamTrabajos-i ; j++)
		{
			if (listaTrabajos[j].fecha.anio > listaTrabajos[j+1].fecha.anio)
			{
				aux = listaTrabajos[j];
				listaTrabajos[j] = listaTrabajos[j+1];
				listaTrabajos[j+1] = aux;
			}	else	{
				if (listaTrabajos[j].fecha.anio == listaTrabajos[j+1].fecha.anio)
				{
					ObtenerNombreMascota(listaMascotas,tamMascotas, listaTrabajos[j].idMascota,nombreMascotaI);
					ObtenerNombreMascota(listaMascotas,tamMascotas, listaTrabajos[j+1].idMascota,nombreMascotaJ);
					if(strcmp(nombreMascotaI,nombreMascotaJ)>0)
					{
						aux = listaTrabajos[j];
						listaTrabajos[j] = listaTrabajos[j+1];
						listaTrabajos[j+1] = aux;
					}
				}
			}
		}
	}
	return 0;
}

/**
 * @fn int OrdenarTrabajoNombre(eTrabajo[], int, eMascota[], int)
 * @brief Ordena la lista de trabajos por nombre.
 *
 * @param listaTrabajos
 * @param tamTrabajos
 * @param listaMascotas
 * @param tamMascotas
 * @return -
 */
int OrdenarTrabajoNombre(eTrabajo listaTrabajos[],int tamTrabajos,eMascota listaMascotas[],int tamMascotas)
{
	int i;
	int j;
	eTrabajo aux;
	char nombreMascotaI[26];
	char nombreMascotaJ[26];

	for (i=1 ; i<tamTrabajos ; i++)
	{
		for (j=0 ; j<tamTrabajos-i ; j++)
		{

			ObtenerNombreMascota(listaMascotas,tamMascotas, listaTrabajos[j].idMascota,nombreMascotaI);
			ObtenerNombreMascota(listaMascotas,tamMascotas, listaTrabajos[j+1].idMascota,nombreMascotaJ);
			if(strcmp(nombreMascotaI,nombreMascotaJ)>0)
			{
				aux = listaTrabajos[j];
				listaTrabajos[j] = listaTrabajos[j+1];
				listaTrabajos[j+1] = aux;
			}
		}
	}

	return 0;
}

/**
 * @fn void MostrarListaTrabajos(eTrabajo[], int)
 * @brief Muestra una lista con todos los registros de la lista de trabajos
 *
 * @param listaTrabajos
 * @param tamTrabajos
 */
void MostrarListaTrabajos(eTrabajo listaTrabajos[],int tamTrabajos,eMascota listaMascotas[],int tamMascotas,eServicio listaServicios[],int tamServicios,eVeterinario listaVet[],int tamVet)
{
	int i;
	char nombreMascota[26];
	char servicio[51];
	char veterinario[51];

	printf("\nID |  Nombre   |  Servicio  |  Fecha  | Veterinario \n");
	printf("---------------------------------------------------------------\n");
	for (i=0 ; i<tamTrabajos ; i++)
	{
		if (listaTrabajos[i].isEmpty==OCUPADO)
		{
			ObtenerNombreMascota(listaMascotas,tamMascotas, listaTrabajos[i].idMascota,nombreMascota);
			ObtenerServicio(listaServicios,tamServicios,listaTrabajos[i].idServicio,servicio);
			ObtenerVeterinario(listaVet,tamVet,listaTrabajos[i].idVeterinario,veterinario);
			printf("%3d|%11s|%12s|%d/%d/%d|%14s\n", listaTrabajos[i].id,
								nombreMascota,
								servicio,
								listaTrabajos[i].fecha.dia,
								listaTrabajos[i].fecha.mes,
								listaTrabajos[i].fecha.anio,
								veterinario);
		}
	}
}

/**
 * @fn int MostrarPrecioTotal(eTrabajo[], int, eServicio[], int)
 * @brief Acumula el precio de todos los trabajos y lo muestra.
 *
 * @param listaTrabajos
 * @param tamTrabajos
 * @param listaServicios
 * @param tamServicios
 * @return -
 */
int MostrarPrecioTotal(eTrabajo listaTrabajos[],int tamTrabajos,eServicio listaServicios[], int tamServicios)
{
	int i;
	int j;
	int acumuladorPrecioTotal;

	acumuladorPrecioTotal = 0;

	for (i=0 ; i<tamTrabajos ; i++)
	{
		for (j=0 ; j<tamServicios ; j++)
		{
			if (listaTrabajos[i].isEmpty == OCUPADO && listaTrabajos[i].idServicio == listaServicios[j].id)
			{
				acumuladorPrecioTotal = acumuladorPrecioTotal + listaServicios[j].precio;
			}
		}
	}

	printf("\nTotal en pesos por los servicios prestados : $%d\n",acumuladorPrecioTotal);

	return 0;
}

/**
 * @fn int ObtenerCantidades(eTrabajo[], int, eServicio[], int, eAuxiliarServicios[])
 * @brief Cuenta cúantos trabajos realizo cada servicio y devuelve la cantidad maxima
 *
 * @param listaTrabajos
 * @param tamTrabajos
 * @param listaServicios
 * @param tamServicios
 * @param auxiliar
 * @return cantidadMaxima
 */
int ObtenerCantidades(eTrabajo listaTrabajos[],int tamTrabajos,eServicio listaServicios[], int tamServicios,eAuxiliarServicios auxiliar[])
{
	int cantidadMaxima;
	int i;
	int j;
	cantidadMaxima=0;

	for(i=0; i<tamServicios ; i++)
	{
		auxiliar[i].idServicio = listaServicios[i].id;
		auxiliar[i].cantidadTrabajos = 0;
		for(j=0 ; j<tamTrabajos ; j++)
		{
			if(listaTrabajos[j].isEmpty == OCUPADO && listaTrabajos[j].idServicio == auxiliar[i].idServicio)
			{
				auxiliar[i].cantidadTrabajos ++;
				if(auxiliar[i].cantidadTrabajos > cantidadMaxima)
				{
					cantidadMaxima = auxiliar[i].cantidadTrabajos;
				}
			}
		}
	}

	return cantidadMaxima;
}

/**
 * @fn int ServiciosConMasTrabajos(eTrabajo[], int, eServicio[], int)
 * @brief Imprime el/los servicios con mas trabajos realizados y su cantidad
 *
 * @param listaTrabajos
 * @param tamTrabajos
 * @param listaServicios
 * @param tamServicios
 * @return -
 */
int ServiciosConMasTrabajos(eTrabajo listaTrabajos[],int tamTrabajos,eServicio listaServicios[], int tamServicios)
{
	eAuxiliarServicios auxiliar[tamServicios];
	int i;
	int cantidadMaxima;

	cantidadMaxima = ObtenerCantidades(listaTrabajos,tamTrabajos,listaServicios,tamServicios,auxiliar);

	for (i=0;i<tamServicios;i++)
	{
		if(auxiliar[i].cantidadTrabajos == cantidadMaxima)
		{
			printf("\nServicio [%s]: %d trabajos.\n",listaServicios[i].descripcion,auxiliar[i].cantidadTrabajos);
		}
	}

	return 1;
}

/**
 * @fn void BuscarConcatenarMascotasServicio(eTrabajo[], int, eMascota[], int, int, char[])
 * @brief Concatena en un string las mascota que utilizaron el servicio indicado
 *
 * @param listaTrabajos
 * @param tamTrabajos
 * @param listaMascotas
 * @param tamMascotas
 * @param idSolicitada
 * @param mascotas
 */
void BuscarConcatenarMascotasServicio(eTrabajo listaTrabajos[],int tamTrabajos,eMascota listaMascotas[],int tamMascotas,int idSolicitada,char mascotas[])
{
	int i;
	int j;
	char mascotaActual[51];

	for(i=0;i<tamMascotas;i++)
	{
		for(j=0;j<tamTrabajos;j++)
		{
			if(listaTrabajos[j].idServicio == idSolicitada && listaMascotas[i].id==listaTrabajos[j].idMascota && listaTrabajos[j].isEmpty == OCUPADO)
			{
				ObtenerNombreMascota(listaMascotas,tamMascotas,listaTrabajos[j].idMascota,mascotaActual);
				strcat(mascotas,mascotaActual);
				strcat(mascotas," ");
				break;
			}
		}
	}
}

/**
 * @fn int listarServiciosMascotas(eTrabajo[], int, eMascota[], int, eServicio[], int)
 * @brief Lista los servicios con las mascotas que se lo realizaron
 *
 * @param listaTrabajos
 * @param tamTrabajos
 * @param listaMascotas
 * @param tamMascotas
 * @param listaServicios
 * @param tamServicios
 * @return -
 */
int listarServiciosMascotas(eTrabajo listaTrabajos[],int tamTrabajos,eMascota listaMascotas[],int tamMascotas,eServicio listaServicios[],int tamServicios)
{
	int i;
	char mascotas[251] = "";

	printf("\n|ID   |Descripcion    |Precio\n");
	printf("----------------------------\n");
	for (i=0 ; i<tamServicios ; i++)
	{
		if (listaServicios[i].isEmpty == OCUPADO)
		{
			strcpy(mascotas,"");
			BuscarConcatenarMascotasServicio(listaTrabajos,tamTrabajos,listaMascotas,tamMascotas,listaServicios[i].id,mascotas);
			printf("|%3d|%15s|$%5d\n", listaServicios[i].id,
									listaServicios[i].descripcion,
									listaServicios[i].precio);
			printf("|Mascotas que usaron el servicio: %s\n",mascotas);
		}
	}

	return 1;
}

/**
 * @fn float SacarPromedio(eTrabajo[], int, eMascota[], int, int)
 * @brief Obtiene el promedio de edades de las mascotas que utilizaron un servicio
 *
 * @param listaTrabajos
 * @param tamTrabajos
 * @param listaMascotas
 * @param tamMascotas
 * @param idSolicitada
 * @return promedio
 */
float SacarPromedio(eTrabajo listaTrabajos[],int tamTrabajos,eMascota listaMascotas[],int tamMascotas,int idSolicitada)
{
	float promedio = 0;
	int acum = 0;
	int cont = 0;

	int i;
	int j;

	for(i=0;i<tamMascotas;i++)
	{
		for(j=0;j<tamTrabajos;j++)
		{
			if(listaTrabajos[j].idServicio == idSolicitada && listaTrabajos[j].idMascota == listaMascotas[i].id && listaTrabajos[j].isEmpty == OCUPADO)
			{
				acum += listaMascotas[i].edad;
				cont++;
				promedio = (acum + 0.0) / cont;

				break;
			}
		}
	}

	return promedio;
}

/**
 * @fn int PromedioEdadServicio(eTrabajo[], int, eMascota[], int, eServicio[], int)
 * @brief Imprime el promedio de edad de las mascotas que utilizaron el servicio indicado por el usuario
 *
 * @param listaTrabajos
 * @param tamTrabajos
 * @param listaMascotas
 * @param tamMascotas
 * @param listaServicios
 * @param tamServicios
 * @return
 */
int PromedioEdadServicio(eTrabajo listaTrabajos[],int tamTrabajos,eMascota listaMascotas[],int tamMascotas,eServicio listaServicios[],int tamServicios)
{
	int idServicio;
	float promedio;
	idServicio = PedirVerificarIdServicio(listaServicios, tamServicios);

	promedio = SacarPromedio(listaTrabajos,tamTrabajos,listaMascotas,tamMascotas,idServicio);

	if(promedio==0)
	{
		printf("\nNo hay mascotas que hayan recibido este servicio\n");
	}	else	{
		printf("\nPromedio de edades que utilizaron el servicio: %.2f\n",promedio);
	}

	return 1;
}

/**
 * @fn int TrabajosTurnoManana(eTrabajo[], int, eServicio[], int, eMascota[], int, eVeterinario[], int)
 * @brief Lista todos los trabajos realizados por veterinarios del turno mañana
 *
 * @param listaTrabajos
 * @param tamTrabajos
 * @param listaServicios
 * @param tamServicios
 * @param listaMascotas
 * @param tamMascotas
 * @param listaVet
 * @param tamVet
 * @return -
 */
int TrabajosTurnoManana(eTrabajo listaTrabajos[],int tamTrabajos,eServicio listaServicios[],int tamServicios,eMascota listaMascotas[], int tamMascotas,eVeterinario listaVet[],int tamVet)
{
	eTrabajo listaManana[tamTrabajos];
	InicializarTrabajos(listaManana,tamTrabajos);

	int i;

	for(i=0;i<tamTrabajos;i++)
	{
		if(listaTrabajos[i].isEmpty == OCUPADO)
		{
			if(ObtenerTurnoId(listaVet,tamVet,listaTrabajos[i].idVeterinario)==1)
			{
				listaManana[i] = listaTrabajos[i];
			}
		}
	}

	printf("\nTrabajos realizados por el turno mañana: ");
	MostrarListaTrabajos(listaManana,tamTrabajos,listaMascotas,tamMascotas,listaServicios,tamServicios,listaVet,tamVet);

	return 1;
}

/**
 * @fn void BuscarConcatenarMascotasVeterinario(eTrabajo[], int, eMascota[], int, int, char[])
 * @brief Concatena en un string las mascotas que fueron atendidas por el veterinario indicado
 *
 * @param listaTrabajos
 * @param tamTrabajos
 * @param listaMascotas
 * @param tamMascotas
 * @param idSolicitada
 * @param mascotas
 */
void BuscarConcatenarMascotasVeterinario(eTrabajo listaTrabajos[],int tamTrabajos,eMascota listaMascotas[],int tamMascotas,int idSolicitada,char mascotas[])
{
	int i;
	int j;
	char mascotaActual[51];

	for(i=0;i<tamMascotas;i++)
	{
		for(j=0;j<tamTrabajos;j++)
		{
			if(listaTrabajos[j].idVeterinario == idSolicitada && listaMascotas[i].id==listaTrabajos[j].idMascota && listaTrabajos[j].isEmpty == OCUPADO)
			{
				ObtenerNombreMascota(listaMascotas,tamMascotas,listaTrabajos[j].idMascota,mascotaActual);
				strcat(mascotas,mascotaActual);
				strcat(mascotas," ");
				break;
			}
		}
	}
}

/**
 * @fn int ListarVeterinariosMascotas(eTrabajo[], int, eServicio[], int, eMascota[], int, eVeterinario[], int)
 * @brief Lista los veterinarios y las mascotas que atendieron
 *
 * @param listaTrabajos
 * @param tamTrabajos
 * @param listaServicios
 * @param tamServicios
 * @param listaMascotas
 * @param tamMascotas
 * @param listaVet
 * @param tamVet
 * @return -
 */
int ListarVeterinariosMascotas(eTrabajo listaTrabajos[],int tamTrabajos,eServicio listaServicios[],int tamServicios,eMascota listaMascotas[], int tamMascotas,eVeterinario listaVet[],int tamVet)
{
	int i;
	char mascotas[251];
	char turno[51];

	printf("\n| ID |   Nombre  |   Turno  |\n");
	printf("-----------------------------\n");
	for (i=0 ; i<tamVet ; i++)
	{
		if (listaVet[i].isEmpty == OCUPADO)
		{
			if(listaVet[i].turno == 1)
			{
				strcpy(turno,"Mañana");
			}	else	{
				strcpy(turno,"Tarde");
			}
			strcpy(mascotas,"");
			BuscarConcatenarMascotasVeterinario(listaTrabajos,tamTrabajos,listaMascotas,tamMascotas,listaVet[i].id,mascotas);
			printf("|%3d|%12s|%7s\n", listaVet[i].id,
					listaVet[i].nombre,
					turno);
			printf("|Mascotas atendidas: %s\n",mascotas);
			printf("|----------------------------\n");
		}
	}

	return 1;
}
