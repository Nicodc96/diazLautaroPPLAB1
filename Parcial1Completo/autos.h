#include "colorAuto.h"
#include "marca.h"
#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED

typedef struct
{
    int id;
    int patente;
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;

}eAuto;


#endif // AUTOS_H_INCLUDED

int altaAuto(eAuto vehiculos[], int tamA, int idAuto, eMarcas marcas[], int tamM, eColor colores[], int tamC);
int buscarLibreAuto(eAuto vehiculos[], int tamA);
int checkAuto(eAuto vehiculos[], int tamA);
eAuto nuevoAuto(int id, int patente, int idMarca, int idColor, int modelo);
void inicializarAutos(eAuto vehiculos[], int tamA);
void mostrarAuto(eAuto vehiculos, eMarcas marca[], int tamM, eColor colores[], int tamC);
void mostrarAutos(eAuto vehiculos[], int tamA, eMarcas marcas[], int tamM, eColor color[], int tamC);
void preOrdenarVehiculos(eAuto vehiculos[], int tamA, eMarcas marcas[], int tamM, eColor color[], int tamC);
int buscarIDAutoEnArray(eAuto vehiculos[], int tamA, int idParametro);
int bajaAuto(eAuto vehiculos[], int tamA, eMarcas marcas[], int tamM, eColor color[], int tamC);
int buscarPatenteAutoEnArray(eAuto vehiculos[], int tamA, int patenteParametro);
void modificarVehiculos(eAuto vehiculos[], int tamA, eMarcas marcas[], int tamM, eColor color[], int tamC);


// ----- FUNCION DE PRUEBA
int harcodearAutos(eAuto vehiculos[], int tamA, int cantidad);
