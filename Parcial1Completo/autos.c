#include <stdio.h>
#include <stdlib.h>
#include "autos.h"
#include "marca.h"
#include "colorAuto.h"
#include "validaciones.h"

void inicializarAutos(eAuto vehiculos[], int tamA)
{
    for(int i = 0; i < tamA; i++)
    {
        vehiculos[i].isEmpty = 1;
    }
}

int buscarLibreAuto(eAuto vehiculos[], int tamA)
{
    int indice = -1;
    for(int i = 0; i < tamA; i++)
    {
        if(vehiculos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int checkAuto(eAuto vehiculos[], int tamA)
{
    int isOk = 0;
    int i;
    for(i = 0; i < tamA; i++)
    {
        if (vehiculos[i].isEmpty == 0)
        {
            isOk = 1;
        }
    }
    return isOk;
}

eAuto nuevoAuto(int id, int patente, int idMarca, int idColor, int modelo)
{
    eAuto x;
    x.id = id;
    x.patente = patente;
    x.idColor = idColor;
    x.idMarca = idMarca;
    x.modelo = modelo;
    x.isEmpty = 0;
    return x;
}

int altaAuto(eAuto vehiculos[], int tamA, int idAuto, eMarcas marcas[], int tamM, eColor colores[], int tamC)
{
    int isOk = 0;
    int auxPatente;
    int auxIdMarca;
    int auxIdColor;
    int auxModelo;
    int indiceAuto;
    system("cls");
    printf("-----------------------------------------------------\n");
    printf("--------------------- ALTA AUTO ---------------------\n");
    printf("-----------------------------------------------------\n\n");
    indiceAuto = buscarLibreAuto(vehiculos, tamA);
    if (indiceAuto == -1)
    {
        printf("No hay espacio para agregar mas vehiculos!\n");
    } else
        {
            printf("Ingrese la patente del vehiculo (Ej. 777455): ");
            fflush(stdin);
            scanf("%d", &auxPatente);
            while(!validarPatente(auxPatente))
            {
                printf("Se ha ingresado una patente incorrecta!\n");
                printf("Reingrese (Ej. 777455): ");
                fflush(stdin);
                scanf("%d", &auxPatente);
            }
            mostrarMarcas(marcas, tamM);
            printf("Ingrese el ID de la marca del vehiculo: ");
            fflush(stdin);
            scanf("%d", &auxIdMarca);
            while(!validarMarca(marcas, tamM, auxIdMarca))
            {
                printf("Marca ingresada incorrecta! Reingrese: ");
                fflush(stdin);
                scanf("%d", &auxIdMarca);
            }
            mostrarColores(colores, tamC);
            printf("Ingrese el ID del color del vehiculo: ");
            fflush(stdin);
            scanf("%d", &auxIdColor);
            while(!validarColor(colores, tamC, auxIdColor))
            {
                printf("Color ingresado incorrecta! Reingrese: ");
                fflush(stdin);
                scanf("%d", &auxIdColor);
            }
            printf("Ingrese el anio de fabricacion del vehiculo (1930-2020): ");
            fflush(stdin);
            scanf("%d", &auxModelo);
            while (!validarModelo(auxModelo))
            {
                printf("Ingrese un anio correcto! (1930-2020): ");
                fflush(stdin);
                scanf("%d", &auxModelo);
            }
            vehiculos[indiceAuto] = nuevoAuto(idAuto, auxPatente, auxIdMarca, auxIdColor, auxModelo);
            printf("Se ha dado de ALTA a un nuevo auto correctamente.\n");
            isOk = 1;
        }

    return isOk;
}

void mostrarAuto(eAuto vehiculos, eMarcas marca[], int tamM, eColor colores[], int tamC)
{
    char descColores[20];
    char descMarca[20];

    mostrarDescColor(vehiculos.idColor, colores, tamC, descColores);
    mostrarDescMarca(vehiculos.idMarca, marca, tamM, descMarca);

    printf("  %d    %d %10s   %8s   %d\n",
            vehiculos.id,
            vehiculos.patente,
            descMarca,
            descColores,
            vehiculos.modelo);
}

void mostrarAutos(eAuto vehiculos[], int tamA, eMarcas marcas[], int tamM, eColor color[], int tamC)
{
    int i;
    printf("----------------------------------------------------------------\n");
    printf("----------------- LISTADO DE VEHICULOS ACTIVOS -----------------\n");
    printf("----------------------------------------------------------------\n");
    printf("---------- VEHICULOS ORDENADOS SEGUN MARCA Y PATENTE -----------\n\n");
    printf("ID AUTO   PATENTE     MARCA      COLOR   MODELO\n\n");
    for(i = 0; i < tamA; i++)
    {
        if (vehiculos[i].isEmpty == 0)
        {
            mostrarAuto(vehiculos[i], marcas, tamM, color, tamC);
        }
    }
}

int buscarIDAutoEnArray(eAuto vehiculos[], int tamA, int idParametro)
{
    int i;
    int indice = -1;
    for (i = 0; i < tamA; i++)
    {
        if (vehiculos[i].id == idParametro)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int bajaAuto(eAuto vehiculos[], int tamA, eMarcas marcas[], int tamM, eColor color[], int tamC)
{
    system("cls");
    int isOk = 0;
    int indiceAuto;
    int auxIDAuto;
    char respuesta;

    printf("-----------------------------------------------------\n");
    printf("--------------------- BAJA AUTO ---------------------\n");
    printf("-----------------------------------------------------\n\n");
    mostrarAutos(vehiculos, tamA, marcas, tamM, color, tamC);
    printf("Ingrese el ID del vehiculo a realizar la baja: ");
    fflush(stdin);
    scanf("%d", &auxIDAuto);
    indiceAuto = buscarIDAutoEnArray(vehiculos, tamA, auxIDAuto);
    if(indiceAuto != -1)
    {
        printf("ID AUTO   PATENTE     MARCA      COLOR   MODELO\n\n");
        mostrarAuto(vehiculos[indiceAuto], marcas, tamM, color, tamC);
        printf("Confirmar baja (s/n): ");
        fflush(stdin);
        scanf("%c", &respuesta);
        validarSalida(&respuesta);
        if(respuesta == 's')
        {
            vehiculos[indiceAuto].isEmpty = 1;
            printf("Se ha dado de baja correctamente al vehiculo!\n");
            isOk = 1;
        } else
            {
                printf("Se ha cancelado la operacion.\n");
            }
    } else
        {
            printf("ID del vehiculo no encontrado!\n");
        }
    return isOk;
}

int buscarPatenteAutoEnArray(eAuto vehiculos[], int tamA, int patenteParametro)
{
    int i;
    int indice = -1;
    for (i = 0; i < tamA; i++)
    {
        if (vehiculos[i].patente == patenteParametro)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void modificarVehiculos(eAuto vehiculos[], int tamA, eMarcas marcas[], int tamM, eColor color[], int tamC)
{
    int auxPatente;
    int auxColor;
    int auxMarca;
    int indice;
    int opcion;
    system("cls");

    printf("----------------------------------------------------------\n");
    printf("--------------------- MODIFICAR AUTO ---------------------\n");
    printf("----------------------------------------------------------\n\n");
    mostrarAutos(vehiculos, tamA, marcas, tamM, color, tamC);
    printf("Ingrese la patente del vehiculo: ");
    fflush(stdin);
    scanf("%d", &auxPatente);

    indice = buscarPatenteAutoEnArray(vehiculos, tamA, auxPatente);
    if(indice != -1)
    {
        printf("ID AUTO   PATENTE     MARCA      COLOR   MODELO\n\n");
        mostrarAuto(vehiculos[indice], marcas, tamM, color, tamC);
        printf("\n1) Modificar Color\n");
        printf("2) Modificar Modelo\n");
        printf("3) Cancelar operacion\n\n");
        printf("Elija una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            mostrarColores(color, tamC);
            printf("Ingrese el ID del nuevo color a modificar: ");
            fflush(stdin);
            scanf("%d", &auxColor);
            if(validarColor(color, tamM, auxColor))
            {
                vehiculos[indice].idColor = auxColor;
                printf("Se ha modificado el color del vehiculo correctamente!\n");
                system("pause");
            } else
                {
                    printf("ID del color incorrecto! Saliendo del menu..\n");
                    system("pause");
                }
            break;
        case 2:
            mostrarMarcas(marcas, tamM);
            printf("Ingrese el ID de la nueva marca a modificar: ");
            fflush(stdin);
            scanf("%d", &auxMarca);
            if(validarMarca(marcas, tamM, auxMarca))
            {
                vehiculos[indice].idMarca = auxMarca;
                printf("Se ha modificado la marca del vehiculo correctamente!\n");
                system("pause");
            } else
                {
                    printf("ID de la marca incorrecta! Saliendo del menu..\n");
                    system("pause");
                }
            break;
        case 3:
            printf("Se ha cancelado la operacion correctamente\n");
            break;
        default:
            printf("Opcion seleccionada incorrecta! Saliendo del menu..\n");
            system("pause");
        }
    } else
        {
            printf("Patente del vehiculo no encontrado.\n");
        }
}

void preOrdenarVehiculos(eAuto vehiculos[], int tamA, eMarcas marcas[], int tamM, eColor color[], int tamC)
{
    int i, j;
    eAuto auxVehiculo;
    for (i = 0; i < tamA-1; i++)
    {
        for (j = i+1; j < tamA; j++)
        {
            if(vehiculos[i].idMarca > vehiculos[j].idMarca && !vehiculos[i].isEmpty && !vehiculos[i].isEmpty)
            {
                auxVehiculo = vehiculos[i];
                vehiculos[i] = vehiculos[j];
                vehiculos[j] = auxVehiculo;
            }
            if (vehiculos[i].idMarca == vehiculos[j].idMarca && vehiculos[i].patente > vehiculos[j].patente && !vehiculos[i].isEmpty && !vehiculos[i].isEmpty)
            {
                auxVehiculo = vehiculos[i];
                vehiculos[i] = vehiculos[j];
                vehiculos[j] = auxVehiculo;
            }
        }
    }
}

int harcodearAutos(eAuto vehiculos[], int tamA, int cantidad)
{
    int contador;
    int i;
    eAuto listaAuxiliar[] = {
        {7000, 511511, 1000, 5002, 2004, 0},
        {7001, 852451, 1002, 5004, 2015, 0},
        {7002, 996463, 1001, 5003, 2001, 0},
        {7003, 178435, 1000, 5001, 1970, 0},
        {7004, 567314, 1004, 5004, 2019, 0},
        {7005, 330005, 1003, 5002, 2012, 0},
        {7006, 661777, 1001, 5003, 2000, 0},
        {7007, 464111, 1000, 5000, 1974, 0},
        {7008, 917743, 1003, 5001, 2009, 0},
        {7009, 325745, 1003, 5004, 2019, 0}
    };
    if (cantidad <= 10 && tamA >= cantidad)
    {
        for (i = 0; i < cantidad; i++)
        {
            vehiculos[i] = listaAuxiliar[i];
            contador++;
        }
    }
    return contador;
}
