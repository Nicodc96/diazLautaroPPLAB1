#include "autos.h"
#include "servicios.h"
#include "marca.h"
#include "colorAuto.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int id;
    int patente;
    int idServicio;
    eFecha fechaDeTrabajo;
    int isEmpty;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED

int altaTrabajo(eTrabajo trabajo[], int tamT, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarcas marcas[], int tamM, eColor colores[], int tamC, int idTrabajo);
eTrabajo cargarTrabajo(int id, int patente, int servicio, eFecha fecha);
void inicializarTrabajos(eTrabajo trabajos[], int tamT);
int buscarLibreTrabajo(eTrabajo trabajos[], int tamT);
void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamS);
int mostrarTrabajos(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS);
int harcodearTrabajos(eTrabajo trabajos[], int tamT, int cantidad);
