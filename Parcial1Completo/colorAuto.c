#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colorAuto.h"

int harcodearColores(eColor colores[], int tamC, int cantidad)
{
    int i;
    int contador = 0;
        eColor listaAuxiliar[] = {
            {5000, "Negro"},
            {5001, "Blanco"},
            {5002, "Gris"},
            {5003, "Rojo"},
            {5004, "Azul"}
            };
    if (cantidad <= 5 && tamC >= cantidad)
    {
        for (i = 0; i < cantidad; i++)
        {
            colores[i] = listaAuxiliar[i];
            contador++;
        }
    }
    return contador;
}

void mostrarColor(eColor col)
{
    printf("  %d    %10s\n", col.id, col.nombre);
}

void mostrarColores(eColor colores[], int tamC)
{
    int i;
    printf("-------------------------------------------------\n");
    printf("----------- LISTA DE COLORES DISPONIBLES --------\n");
    printf("-------------------------------------------------\n\n");
    printf("ID COLOR     DESCRIPCION\n\n");
    for(i = 0; i < tamC; i++)
        {
            if (colores != NULL)
            {
                mostrarColor(colores[i]);
            }
        }
    printf("\n");
}

int mostrarDescColor(int id, eColor color[], int tamC, char desc[])
{
    int isOk = 0;

    for (int i = 0; i < tamC; i++){
        if (id == color[i].id){
            strcpy(desc, color[i].nombre);
            isOk = 1;
            break;
        }
    }
    return isOk;
}
