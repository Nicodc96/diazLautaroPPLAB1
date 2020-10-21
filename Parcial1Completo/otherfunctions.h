#include "validaciones.h"
#include "autos.h"
#include "marca.h"
#include "colorAuto.h"
#include "servicios.h"
#include "trabajo.h"
#ifndef OTHERFUNCTIONS_H_INCLUDED
#define OTHERFUNCTIONS_H_INCLUDED
#endif // OTHERFUNCTIONS_H_INCLUDED

char menuDeOpciones();
int menuDeInformes();
void menuDeInformesCases(eAuto vehiculos[], int tamA, eColor coloresAuto[], int tamC, eMarcas marcasAutos[], int tamM, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS);
