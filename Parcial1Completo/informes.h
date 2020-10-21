#include "autos.h"
#include "colorAuto.h"
#include "marca.h"
#include "trabajo.h"
#include "servicios.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#endif // INFORMES_H_INCLUDED

int informarAutosColor(eAuto autos[], int tamA, eColor coloresAuto[], int tamC, eMarcas marcasAutos[], int tamM, int idColor);
int informarAutosMarca(eAuto autos[], int tamA, eColor coloresAuto[], int tamC, eMarcas marcasAutos[], int tamM, int idMarca);
int informarAutosViejos(eAuto autos[], int tamA, eColor coloresAuto[], int tamC, eMarcas marcasAutos[], int tamM);
int informarAutosSegunMarca(eAuto autos[], int tamA, eColor coloresAuto[], int tamC, eMarcas marcasAutos[], int tamM);
int informarCantidadAutosSegunMarcaYColor(eAuto autos[], int tamA, eColor coloresAuto[], int tamC, eMarcas marcasAutos[], int tamM, int idMarca, int idColor);
void informarAutosMasSolicitados(eAuto autos[], int tamA, eColor coloresAuto[], int tamC, eMarcas marcasAutos[], int tamM);
int informarTrabajosEnAuto(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, int idAuto, eServicio servicios[], int tamS);
int informarSumaTrabajos(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, int idAuto, eServicio servicios[], int tamS);
int informarServiciosRealizados(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, int idServicio, eServicio servicios[], int tamS);
int informarServiciosPorFecha(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, eFecha fechaParametro);
