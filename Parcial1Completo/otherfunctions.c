#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "otherfunctions.h"
#include "validaciones.h"
#include "informes.h"
#include "autos.h"
#include "marca.h"
#include "colorAuto.h"
#include "servicios.h"
#include "trabajo.h"

char menuDeOpciones()
{
    char opcion;
    system("cls");

    printf("------------------------------------------------------\n");
    printf("------------------ MENU DE OPCIONES ------------------\n");
    printf("------------------------------------------------------\n\n");
    printf("A) ALTA AUTO\n");
    printf("B) MODIFICAR AUTO\n");
    printf("C) BAJA AUTO\n");
    printf("D) LISTAR AUTOS\n");
    printf("E) LISTAR MARCAS\n");
    printf("F) LISTAR COLORES\n");
    printf("G) LISTAR SERVICIOS\n");
    printf("H) ALTA TRABAJOS\n");
    printf("I) LISTAR TRABAJOS\n");
    printf("J) MENU INFORMES\n");
    printf("Z) SALIR\n\n");
    printf("Elija una opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = tolower(opcion);

    return opcion;
}

void menuDeInformesCases(eAuto vehiculos[], int tamA, eColor coloresAuto[], int tamC, eMarcas marcasAutos[], int tamM, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS)
{
    char salir = 'n';
    int auxID;
    int auxID2;
    int contadorAux = 0;
    char descAux[20];
    char descAux2[20];
    eFecha auxFecha;
    do
    {
        switch(menuDeInformes())
        {
        case 1:
            system("cls");
            mostrarColores(coloresAuto, tamC);
            printf("Ingrese el ID del color del vehiculo a mostrar: ");
            scanf("%d", &auxID);
            if (validarColor(coloresAuto, tamM, auxID))
            {
                if (!informarAutosColor(vehiculos, tamA, coloresAuto, tamC, marcasAutos, tamM, auxID))
                {
                    printf("No se han encontrado vehiculos del color solicitado!\n\n");
                }
            } else
                {
                    printf("Se ha ingresado un color incorrecto! Volviendo al menu...\n\n");
                }
            break;
        case 2:
            system("cls");
            mostrarMarcas(marcasAutos, tamM);
            printf("Ingrese el ID de la marca a mostrar: ");
            scanf("%d", &auxID);
            if(validarMarca(marcasAutos, tamM, auxID))
            {
                if(!informarAutosMarca(vehiculos,tamA,coloresAuto,tamC,marcasAutos,tamM,auxID))
                {
                    printf("No se han encontrado vehiculos de la marca solicitada!\n\n");
                }
            } else
                {
                    printf("Se ha ingresado una marca incorrecta! Volviendo al menu...\n\n");
                }
            break;
        case 3:
            system("cls");
            if(!informarAutosViejos(vehiculos,tamA,coloresAuto,tamC,marcasAutos,tamM))
            {
                printf("No se han encontrado vehiculos antiguos!\n\n");
            }
            break;
        case 4:
            system("cls");
            {
                if(!informarAutosSegunMarca(vehiculos,tamA,coloresAuto,tamC,marcasAutos,tamM))
                {
                    printf("No se han encontrado vehiculos disponibles!\n\n");
                }
            }
            break;
        case 5:
            system("cls");
            mostrarColores(coloresAuto, tamC);
            printf("Ingrese el color del vehiculo a contar: ");
            scanf("%d", &auxID);
            if(!validarColor(coloresAuto, tamM, auxID))
            {
                printf("ID del color incorrecto! Volviendo al menu...\n");
            } else
                {
                    printf("\n");
                    mostrarMarcas(marcasAutos, tamM);
                    printf("Ingrese la marca del vehiculo a contar: ");
                    scanf("%d", &auxID2);
                    if (!validarMarca(marcasAutos, tamM, auxID2))
                    {
                        printf("ID de la marca incorrecta! Volviendo al menu...\n");
                    } else
                        {
                            contadorAux = informarCantidadAutosSegunMarcaYColor(vehiculos,tamA,coloresAuto,tamC,marcasAutos,tamM,auxID2,auxID);
                            if (!contadorAux)
                            {
                                printf("No se han encontrado vehiculos disponibles!\n");
                            } else
                                {
                                    mostrarDescColor(auxID, coloresAuto, tamC, descAux);
                                    mostrarDescMarca(auxID2, marcasAutos, tamM, descAux2);
                                    printf("\nCantidad de vehiculos de color %s y marca %s: %d\n\n", descAux, descAux2, contadorAux);
                                }
                        }
                }
            break;
        case 6:
            system("cls");
            informarAutosMasSolicitados(vehiculos,tamA,coloresAuto,tamC,marcasAutos,tamM);
            break;
        case 7:
            system("cls");
            mostrarAutos(vehiculos, tamA, marcasAutos, tamM, coloresAuto, tamC);
            printf("Ingrese el ID del vehiculo a informar: ");
            scanf("%d", &auxID);
            if (buscarIDAutoEnArray(vehiculos,tamA, auxID) == -1)
            {
                printf("No se ha encontrado el vehiculo con el ID ingresado, volviendo al menu...");
            } else
                {
                    if (!informarTrabajosEnAuto(vehiculos, tamA, trabajos, tamT, auxID, servicios, tamS))
                    {
                        printf("No se han encontrado trabajos realizados a ese vehiculo!\n");
                    }
                }
            break;
        case 8:
            system("cls");
            mostrarAutos(vehiculos, tamA, marcasAutos, tamM, coloresAuto, tamC);
            printf("Ingrese el ID del vehiculo a calcular precio de trabajos: ");
            scanf("%d", &auxID);
            if (buscarIDAutoEnArray(vehiculos,tamA, auxID) == -1)
            {
                printf("No se ha encontrado el vehiculo con el ID ingresado, volviendo al menu...");
            } else
                {
                    contadorAux = informarSumaTrabajos(vehiculos,tamA,trabajos, tamT, auxID,servicios, tamS);
                    if (!contadorAux)
                    {
                        printf("No se han encontrado trabajos realizados a ese vehiculo!\n");
                    } else
                        {
                            printf("Suma de trabajos realizados al vehiculo: $%d\n", contadorAux);
                        }
                }
            break;
        case 9:
            system("cls");
            mostrarServicios(servicios, tamS);
            printf("Ingrese el ID del servicio a informar: ");
            scanf("%d", &auxID);
            if (!validarServicio(servicios, tamS, auxID))
            {
                printf("ID del servicio ingresado incorrecto! Volviendo al menu...\n");
            } else
                {
                    if(!informarServiciosRealizados(vehiculos, tamA, trabajos, tamT, auxID, servicios, tamS))
                    {
                        printf("No se han encontrado trabajos realizados a ese vehiculo!\n");
                    }
                }
            break;
        case 10:
            system("cls");
            mostrarTrabajos(trabajos, tamT, servicios, tamS);
            printf("Ingrese una fecha de trabajo a informar:\n");
            printf("Dia: ");
            fflush(stdin);
            scanf("%d", &auxFecha.dia);
            while(!validarDia(auxFecha.dia))
            {
                printf("Dia ingresado incorrecto, reingrese: ");
                fflush(stdin);
                scanf("%d", &auxFecha.dia);
            }
            printf("Mes: ");
            fflush(stdin);
            scanf("%d", &auxFecha.mes);
            while(!validarMes(auxFecha.mes))
            {
                printf("Mes ingresado incorrecto, reingrese: ");
                fflush(stdin);
                scanf("%d", &auxFecha.mes);
            }
            printf("Anio: ");
            fflush(stdin);
            scanf("%d", &auxFecha.anio);
            while(!validarAnio(auxFecha.anio))
            {
                printf("Anio ingresado incorrecto, reingrese: ");
                fflush(stdin);
                scanf("%d", &auxFecha.anio);
            }
            if (!informarServiciosPorFecha(trabajos, tamT, servicios, tamS, auxFecha))
            {
                printf("No se han encontrado servicio(s) realizado(s) en esa fecha!\n");
            }
            break;
        case 11:
            printf("Confirmar salida (s/n): ");
            fflush(stdin);
            scanf("%c", &salir);
            salir = tolower(salir);
            validarSalida(&salir);
            break;
            default:
                printf("Opcion ingresada incorrecta! Volviendo al menu...\n");
        }
    system("pause");
    }while(salir == 'n');
}

int menuDeInformes()
{
    int opcion;
    system("cls");

    printf("------------------------------------------------------\n");
    printf("------------------ MENU DE INFORMES ------------------\n");
    printf("------------------------------------------------------\n\n");
    printf("1) Listar vehiculos segun el color\n");
    printf("2) Mostrar vehiculos segun la marca\n");
    printf("3) Informar el/los vehiculos antiguos\n");
    printf("4) Mostrar listado de los autos separados por marca\n");
    printf("5) Contar cuantos vehiculos existen segun marca y color\n");
    printf("6) Mostrar la/s marca/s mas elegidas por los clientes\n");
    printf("7) Mostrar trabajos realizados a un vehiculo en especifico\n");
    printf("8) Mostrar importe total de los trabajos realizados a un vehiculo en especifico\n");
    printf("9) Mostrar vehiculos segun servicio especifico\n");
    printf("10) Mostrar servicios realizados segun fecha especifica\n");
    printf("11) SALIR\n\n");
    printf("Elija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
