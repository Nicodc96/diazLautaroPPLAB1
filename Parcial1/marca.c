#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"

int harcodearMarcas(eMarcas marcas[], int tamM, int cantidad)
{
    int contador = 0;
        eMarcas listaAuxiliar[] = {
            {1000, "Renault"},
            {1001, "Fiat"},
            {1002, "Ford"},
            {1003, "Chevrolet"},
            {1004, "Peugeot"}
            };
    if (cantidad <= 5 && tamM >= cantidad)
    {
        for (int i = 0; i < cantidad; i++)
        {
            marcas[i] = listaAuxiliar[i];
            contador++;
        }
    }
    return contador;
}

void mostrarMarca(eMarcas marca)
{
    printf("  %d      %10s\n", marca.id, marca.descripcion);
}

void mostrarMarcas(eMarcas marca[], int tamM)
{
    int i;
    printf("-------------------------------------------------\n");
    printf("----------- LISTA DE MARCAS DISPONIBLES --------\n");
    printf("-------------------------------------------------\n\n");
    printf(" ID MARCA     DESCRIPCION\n\n");
    for(i = 0; i < tamM; i++)
        {
            if (marca != NULL)
            {
                mostrarMarca(marca[i]);
            }
        }
}

int mostrarDescMarca(int id, eMarcas marca[], int tamM, char desc[])
{
    int isOk = 0;

    for (int i = 0; i < tamM; i++){
        if (id == marca[i].id){
            strcpy(desc, marca[i].descripcion);
            isOk = 1;
            break;
        }
    }
    return isOk;
}

