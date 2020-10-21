#include <stdio.h>
#include <stdlib.h>
#include "trabajo.h"
#include "autos.h"
#include "servicios.h"
#include "marca.h"
#include "colorAuto.h"
#include "validaciones.h"

int altaTrabajo(eTrabajo trabajo[], int tamT, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarcas marcas[], int tamM, eColor colores[], int tamC, int idTrabajo)
{
    int isOk = 0;
    int auxIdVehiculo;
    int auxIdServicio;
    int indiceAuto;
    int indiceServicio;
    int indiceTrabajo;
    eFecha auxFecha;

    system("cls");
    printf("--------------------------------------------------------\n");
    printf("--------------------- ALTA TRABAJO ---------------------\n");
    printf("-------------------------------------------------------\n\n");
    indiceTrabajo = buscarLibreTrabajo(trabajo, tamT);
    if (indiceTrabajo == -1)
    {
        printf("No han espacio disponible para mas trabajos!\n");
    } else
        {
            mostrarAutos(autos, tamA, marcas, tamM, colores, tamC);
        printf("Ingrese el ID del vehiculo para realizar un trabajo: ");
        fflush(stdin);
        scanf("%d", &auxIdVehiculo);
        indiceAuto = buscarIDAutoEnArray(autos, tamA, auxIdVehiculo);
        if(indiceAuto != -1)
        {
            mostrarServicios(servicios, tamS);
            printf("Ingrese el ID del servicio a aplicar: ");
            fflush(stdin);
            scanf("%d", &auxIdServicio);
            indiceServicio = buscarIDServicioEnArray(servicios, tamS, auxIdServicio);
            if (indiceServicio != -1)
            {
                printf("Ingrese la fecha del trabajo:\n");
                printf("Dia: ");
                fflush(stdin);
                scanf("%d", &auxFecha.dia);
                while(!validarDia(auxFecha.dia))
                {
                    printf("Ingrese un dia correcto!\n");
                    printf("Dia: ");
                    scanf("%d", &auxFecha.dia);
                }
                printf("Mes: ");
                fflush(stdin);
                scanf("%d", &auxFecha.mes);
                while(!validarMes(auxFecha.mes))
                {
                    printf("Ingrese un mes correcto!\n");
                    printf("Mes: ");
                    scanf("%d", &auxFecha.mes);
                }
                printf("Anio: ");
                fflush(stdin);
                scanf("%d", &auxFecha.anio);
                while(!validarAnio(auxFecha.anio))
                {
                    printf("Ingrese un anio correcto!\n");
                    printf("Anio: ");
                    scanf("%d", &auxFecha.anio);
                }
                trabajo[indiceTrabajo] = cargarTrabajo(idTrabajo, autos[indiceAuto].patente, servicios[indiceServicio].id, auxFecha);
                printf("Se ha cargado un trabajo correctamente!\n");
                isOk = 1;
            } else
                {
                    printf("No se ha encontrado el servicio con ese ID!\n");
                }
        } else
            {
                printf("No se ha encontrado un vehiculo con ese ID!\n");
            }
        }
    return isOk;
}

eTrabajo cargarTrabajo(int id, int patente, int servicio, eFecha fecha)
{
    eTrabajo x;
    x.id = id;
    x.patente = patente;
    x.idServicio = servicio;
    x.fechaDeTrabajo = fecha;
    x.isEmpty = 0;
    return x;
}

void inicializarTrabajos(eTrabajo trabajos[], int tamT)
{
    int i;
    for (i = 0; i < tamT; i++)
    {
        trabajos[i].isEmpty = 1;
    }
}

int buscarLibreTrabajo(eTrabajo trabajos[], int tamT)
{
    int indice = -1;
    int i;
    for (i = 0; i < tamT; i++)
    {
        if(trabajos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamS)
{
    char descServicio[20];
    mostrarDescServicios(trabajo.idServicio, servicios, tamS, descServicio);

    printf("   %d          %d      %20s        %02d/%02d/%d\n", trabajo.id,
            trabajo.patente,
            descServicio,
            trabajo.fechaDeTrabajo.dia,
            trabajo.fechaDeTrabajo.mes,
            trabajo.fechaDeTrabajo.anio);
}

int mostrarTrabajos(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS)
{
    int i;
    int isOk = 0;
    printf("-------------------------------------------------\n");
    printf("----------- LISTA DE TRABAJOS ACTUALES ----------\n");
    printf("-------------------------------------------------\n\n");
    printf("     ID     PATENTE DEL VEHICULO          TRABAJO       FECHA DE TRABAJO\n");
    for(i = 0; i < tamT; i++)
    {
        if (trabajos[i].isEmpty == 0)
        {
            mostrarTrabajo(trabajos[i], servicios, tamS);
            isOk = 1;
        }
    }
    return isOk;
}

int harcodearTrabajos(eTrabajo trabajos[], int tamT, int cantidad)
{
    int contador = 0;
    int i;
        eTrabajo listaAuxiliar[] = {
            {10000, 852451, 20001, {15,3,2005}},
            {10001, 178435, 20000, {22,1,2016}},
            {10002, 511511, 20000, {13,10,2009}},
            {10003, 330005, 20002, {22,1,2016}},
            {10004, 917743, 20003, {7,7,2013}},
            {10005, 178435, 20003, {15,1,2017}}
            };
    if (cantidad <= 6 && tamT >= cantidad)
    {
        for (i = 0; i < cantidad; i++)
        {
            trabajos[i] = listaAuxiliar[i];
            contador++;
        }
    }
    return contador;
}
