#include "marca.h"
#include "colorAuto.h"
#include "servicios.h"
#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#endif // VALIDACIONES_H_INCLUDED

int validarSalida(char* opcion);
int validarMarca(eMarcas marcas[], int tamM, int idParametro);
int validarColor(eColor colores[], int tamM, int idParametro);
int validarModelo(int modeloParametro);
int validarPatente(int patenteParametro);
int validarDia(int diaParametro);
int validarMes(int mesParametro);
int validarAnio(int anioParametro);
int validarServicio(eServicio servicios[], int tamS, int servicioParametro);
