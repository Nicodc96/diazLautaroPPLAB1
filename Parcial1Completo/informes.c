#include <stdio.h>
#include <stdlib.h>
#include "autos.h"
#include "colorAuto.h"
#include "marca.h"
#include "trabajo.h"
#include "servicios.h"

int informarAutosColor(eAuto autos[], int tamA, eColor coloresAuto[], int tamC, eMarcas marcasAutos[], int tamM, int idColor)
{
    int existenAutos = 0;
    int i;
    system("cls");
    printf("----------------------------------------------------------------------\n");
    printf("------------------ LISTADO DE VEHICULOS DISPONIBLES ------------------\n");
    printf("----------------------------------------------------------------------\n");
    printf("ID AUTO   PATENTE     MARCA      COLOR   MODELO\n\n");
    for (i = 0; i < tamA; i++)
    {
        if (autos[i].idColor == idColor)
        {
            mostrarAuto(autos[i], marcasAutos, tamM, coloresAuto, tamC);
            existenAutos = 1;
        }
    }
    return existenAutos;
}

int informarAutosMarca(eAuto autos[], int tamA, eColor coloresAuto[], int tamC, eMarcas marcasAutos[], int tamM, int idMarca)
{
    int existenAutos = 0;
    int i;
    system("cls");
    printf("----------------------------------------------------------------------\n");
    printf("------------------ LISTADO DE VEHICULOS DISPONIBLES ------------------\n");
    printf("----------------------------------------------------------------------\n");
    printf("ID AUTO   PATENTE     MARCA      COLOR   MODELO\n\n");
    for (i = 0; i < tamA; i++)
    {
        if (autos[i].idMarca == idMarca && autos[i].isEmpty == 0)
        {
            mostrarAuto(autos[i], marcasAutos, tamM, coloresAuto, tamC);
            existenAutos = 1;
        }
    }
    return existenAutos;
}

int informarAutosViejos(eAuto autos[], int tamA, eColor coloresAuto[], int tamC, eMarcas marcasAutos[], int tamM)
{
    int existenAutos = 0;
    int i;
    system("cls");
    printf("-------------------------------------------------------------------\n");
    printf("------------------ LISTADO DE VEHICULOS ANTIGUOS ------------------\n");
    printf("-------------------------------------------------------------------\n");
    printf("ID AUTO   PATENTE     MARCA      COLOR   MODELO\n\n");
    for (i = 0; i < tamA; i++)
    {
        if (autos[i].modelo <= 2000 && autos[i].isEmpty == 0)
        {
            mostrarAuto(autos[i], marcasAutos, tamM, coloresAuto, tamC);
            existenAutos = 1;
        }
    }
    return existenAutos;
}

int informarAutosSegunMarca(eAuto autos[], int tamA, eColor coloresAuto[], int tamC, eMarcas marcasAutos[], int tamM)
{
    int existenAutos = 0;
    int i, j;
    system("cls");
    printf("--------------------------------------------------------------------\n");
    printf("------------------ LISTADO DE VEHICULOS POR MARCA ------------------\n");
    printf("--------------------------------------------------------------------\n");
    for(i = 0; i < tamM; i++)
    {
        printf("\n----------- MARCA %s -----------\n", marcasAutos[i].descripcion);
        printf("ID AUTO   PATENTE     MARCA      COLOR   MODELO\n\n");
        for (j = 0; j < tamA; j++)
        {
            if (autos[j].idMarca == marcasAutos[i].id && autos[j].isEmpty == 0)
            {
                mostrarAuto(autos[j], marcasAutos, tamM, coloresAuto, tamC);
                existenAutos = 1;
            }
        }
    }

    return existenAutos;
}

int informarCantidadAutosSegunMarcaYColor(eAuto autos[], int tamA, eColor coloresAuto[], int tamC, eMarcas marcasAutos[], int tamM, int idMarca, int idColor)
{
    int contador = 0;
    int i;

    for (i = 0; i < tamA; i++)
    {
        if (autos[i].idColor == idColor && autos[i].idMarca == idMarca && autos[i].isEmpty == 0)
        {
            contador++;
        }
    }
    return contador;
}

void informarAutosMasSolicitados(eAuto autos[], int tamA, eColor coloresAuto[], int tamC, eMarcas marcasAutos[], int tamM)
{
    int cantidades[tamM];
    int i, j;
    int maxMarca;
    int flag = 0;
    printf("---------------------------------------------------------\n");
    printf("------------------ MARCAS MAS ELEGIDOS ------------------\n");
    printf("---------------------------------------------------------\n");

    for (i = 0; i < tamM; i++)
    {
        cantidades[i] = 0;
    }
    for (i = 0; i < tamM; i++)
    {
        for (j = 0; j < tamA; j++)
        {
            if (autos[j].isEmpty == 0 && autos[j].idMarca == marcasAutos[i].id)
            {
                cantidades[i]++;
            }
        }
    }
    for (i = 0; i < tamM; i++)
    {
        if (cantidades[i] > maxMarca || flag == 0)
        {
            maxMarca = cantidades[i];
            flag = 1;
        }
    }
    printf("Marcas mas elegidas:\n");
    for (i = 0; i < tamM; i++)
    {
        if (cantidades[i] == maxMarca)
        {
            printf("- %s\n", marcasAutos[i].descripcion);
        }
    }
    printf("\n");
}

int informarTrabajosEnAuto(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, int idAuto, eServicio servicios[], int tamS)
{
    int existeTrabajos = 0;
    int i, j;
    printf("---------------------------------------------------\n");
    printf("----------- LISTA DE TRABAJOS REALIZADOS ----------\n");
    printf("---------------------------------------------------\n\n");
    printf("     ID     PATENTE DEL VEHICULO          TRABAJO       FECHA DE TRABAJO\n");
    for (i = 0; i < tamT; i++)
    {
        for (j = 0; j < tamA; j++)
        {
            if (autos[j].patente == trabajos[i].patente && autos[j].isEmpty == 0 && autos[j].id == idAuto)
            {
                mostrarTrabajo(trabajos[i], servicios, tamS);
                existeTrabajos = 1;
            }
        }
    }
    return existeTrabajos;
}

int informarSumaTrabajos(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, int idAuto, eServicio servicios[], int tamS)
{
    int sumadorPrecios = 0;
    int i, j, k;

    for (i = 0; i < tamT; i++)
    {
        for (j = 0; j < tamS; j++)
        {
           for (k = 0; k < tamA; k++)
            {
                if (autos[k].isEmpty == 0 && autos[k].id == idAuto && autos[k].patente == trabajos[i].patente && servicios[j].id == trabajos[i].idServicio)
                {
                    sumadorPrecios+=servicios[j].precio;
                }
            }
        }
    }
    return sumadorPrecios;
}

int informarServiciosRealizados(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, int idServicio, eServicio servicios[], int tamS)
{
    int checkServicio = 0;
    int i, j, k;
    printf("----------------------------------------------------------------\n");
    printf("--------------------- SERVICIOS REALIZADOS ---------------------\n");
    printf("----------------------------------------------------------------\n\n");
    printf("  ID AUTO                   SERVICIO       FECHA DEL SERVICIO\n");
    for (i = 0; i < tamT; i++)
    {
        for (j = 0; j < tamS; j++)
        {
           for (k = 0; k < tamA; k++)
            {
                if (autos[k].isEmpty == 0 && servicios[j].id == idServicio && autos[k].patente == trabajos[i].patente && servicios[j].id == trabajos[i].idServicio)
                {
                    printf("   %d        %20s           %02d/%02d/%d\n", autos[k].id, servicios[j].descripcion, trabajos[i].fechaDeTrabajo.dia, trabajos[i].fechaDeTrabajo.mes, trabajos[i].fechaDeTrabajo.anio);
                    checkServicio = 1;
                }
            }
        }
    }
    return checkServicio;
}

int informarServiciosPorFecha(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, eFecha fechaParametro)
{
    int checkServicio = 0;
    int i, j;
    printf("----------------------------------------------------------------\n");
    printf("--------------------- SERVICIOS REALIZADOS ---------------------\n");
    printf("----------------------------------------------------------------\n\n");
    printf(" FECHA DEL SERVICIO           SERVICIO\n");
    for (i = 0; i < tamT; i++)
    {
        for (j = 0; j < tamS; j++)
        {
            if (fechaParametro.dia == trabajos[i].fechaDeTrabajo.dia &&
                fechaParametro.mes == trabajos[i].fechaDeTrabajo.mes &&
                fechaParametro.anio == trabajos[i].fechaDeTrabajo.anio
                && trabajos[i].idServicio == servicios[j].id)
            {
                printf("    %02d/%02d/%d   %20s\n", trabajos[i].fechaDeTrabajo.dia,trabajos[i].fechaDeTrabajo.mes,trabajos[i].fechaDeTrabajo.anio, servicios[j].descripcion);
                checkServicio = 1;
            }
        }
    }
    return checkServicio;
}
