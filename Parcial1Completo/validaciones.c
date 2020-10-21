#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "validaciones.h"
#include "marca.h"
#include "colorAuto.h"
#include "servicios.h"

int validarSalida(char* opcion)
{
    int isOk = 0;
    char auxChar = ' ';

    auxChar = *opcion;
    while(auxChar != 'n' && auxChar != 's')
    {
        printf("Opcion seleccionada incorrecta! Reingrese: ");
        fflush(stdin);
        scanf("%c", &auxChar);
    }
    if(auxChar == 's' || auxChar == 'n')
    {
        *opcion = auxChar;
        isOk = 1;
    }
    return isOk;
}

int validarMarca(eMarcas marcas[], int tamM, int idParametro)
{
    int isOk = 0;
    int i;
    for (i = 0; i < tamM; i++)
    {
        if (marcas[i].id == idParametro)
        {
            isOk = 1;
            break;
        }
    }
    return isOk;
}

int validarColor(eColor colores[], int tamM, int idParametro)
{
    int isOk = 0;
    int i;
    for (i = 0; i < tamM; i++)
    {
        if (colores[i].id == idParametro)
        {
            isOk = 1;
            break;
        }
    }
    return isOk;
}

int validarModelo(int modeloParametro)
{
    int isOk = 1;
    if(modeloParametro < 1930 || modeloParametro > 2020)
    {
        isOk = 0;
    }
    return isOk;
}

int validarPatente(int patenteParametro)
{
    int isOk = 1;
    if(patenteParametro < 100000 || patenteParametro > 999999)
    {
        isOk = 0;
    }
    return isOk;
}

int validarDia(int diaParametro)
{
    int isOk = 1;
    if (diaParametro < 1 || diaParametro > 31)
    {
        isOk = 0;
    }
    return isOk;
}

int validarMes(int mesParametro)
{
    int isOk = 1;
    if (mesParametro < 1 || mesParametro > 12)
    {
        isOk = 0;
    }
    return isOk;
}

int validarAnio(int anioParametro)
{
    int isOk = 1;
    if (anioParametro < 2000 || anioParametro > 2035)
    {
        isOk = 0;
    }
    return isOk;
}

int validarServicio(eServicio servicios[], int tamS, int servicioParametro)
{
    int isOk = 0;
    int i;
    for (i = 0; i < tamS; i++)
    {
        if (servicios[i].id == servicioParametro)
        {
            isOk = 1;
            break;
        }
    }
    return isOk;
}
