#ifndef VIAJES_H_
#define VIAJES_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
}Fecha;

typedef struct
{
	int id;
	Fecha fecha;
	int pasajeros;
	int idChofer;
	int kilometros;
}Viaje;

Viaje* viajes_new();
Viaje* viajes_newParametros(char* id,char* dia,char* mes,char* anio,char* pasajeros,char* idChofer,char* kilometros);

int viajes_setId(Viaje* this,int id);
int viajes_getId(Viaje* this,int* id);

int viajes_setFecha(Viaje* this,Fecha* fecha);
int viajes_getFecha(Viaje* this,Fecha* fecha);

int viajes_setPasajeros(Viaje* this,int pasajeros);
int viajes_getPasajeros(Viaje* this,int* pasajeros);

int viajes_setIdChofer(Viaje* this,int idChofer);
int viajes_getIdChofer(Viaje* this,int* idChofer);

int viajes_setKilometros(Viaje* this,int kilometros);
int viajes_getKilometros(Viaje* this,int* kilometros);

int viajes_filtrarJulioKm(void* pViaje);

int viajes_countKmAntonio(void* pViaje);

#endif /* VIAJES_H_ */
