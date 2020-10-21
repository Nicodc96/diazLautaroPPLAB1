#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicios.h"

int harcodearServicios(eServicio servicios[], int tamS, int cantidad)
{
    int contador = 0;
        eServicio listaAuxiliar[] = {
            {20000, "Lavado", 250},
            {20001, "Pulido", 300},
            {20002, "Encerado", 400},
            {20003, "Completo", 600}
            };
    if (cantidad <= 5 && tamS >= cantidad)
    {
        for (int i = 0; i < cantidad; i++)
        {
            servicios[i] = listaAuxiliar[i];
            contador++;
        }
    }
    return contador;
}

void mostrarServicio(eServicio servicio)
{
    printf("  %d      %25s        %d\n", servicio.id, servicio.descripcion, servicio.precio);
}

void mostrarServicios(eServicio servicios[], int tamS)
{
    int i;
    printf("---------------------------------------------------\n");
    printf("----------- LISTA DE SERVICIOS DISPONIBLES --------\n");
    printf("---------------------------------------------------\n\n");
    printf("   ID                       DESCRIPCION     PRECIO\n");
    for (i = 0; i < tamS; i++)
    {
        if (servicios != NULL)
        {
            mostrarServicio(servicios[i]);
        }
    }
}

int buscarIDServicioEnArray(eServicio servicios[], int tamS, int idParametro)
{
    int i;
    int indice = -1;
    for (i = 0; i < tamS; i++)
    {
        if (servicios[i].id == idParametro)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int mostrarDescServicios(int id, eServicio servicio[], int tamS, char desc[])
{
    int isOk = 0;
    int i;
    for (i = 0; i < tamS; i++)
    {
        if (id == servicio[i].id)
        {
            strcpy(desc, servicio[i].descripcion);
            isOk = 1;
            break;
        }
    }
    return isOk;
}
