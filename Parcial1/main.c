#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// ------------ BIBLIOTECAS
#include "otherfunctions.h"
#include "validaciones.h"
#include "autos.h"
#include "colorAuto.h"
#include "marca.h"
#include "servicios.h"
#include "trabajo.h"
// ------------------------

#define TAMAUTO 1000
#define TAMMARCA 5
#define TAMCOLORES 5
#define TAMTRABAJO 100
#define TAMSERVICIO 4


int main()
{
    eAuto listaAutos[TAMAUTO];
    eMarcas listaMarcas[TAMMARCA];
    eColor listaColores[TAMCOLORES];
    eServicio listaServicios[TAMSERVICIO];
    eTrabajo listaTrabajos[TAMTRABAJO];

    int idMarca = 1000;
    int idColor = 5000;
    int idAuto = 7000;
    int idServicio = 20000;
    int idTrabajo = 10000;
    char salir = 'n';

    inicializarAutos(listaAutos, TAMAUTO);
    inicializarTrabajos(listaTrabajos, TAMTRABAJO);

    idMarca = idMarca + harcodearMarcas(listaMarcas, TAMMARCA, 5);
    idColor = idColor + harcodearColores(listaColores, TAMCOLORES, 5);
    idAuto = idAuto + harcodearAutos(listaAutos, TAMAUTO, 7);
    idServicio = idServicio + harcodearServicios(listaServicios, TAMSERVICIO, 4);

    do
    {
        switch(menuDeOpciones())
        {
        case 'a':
            if(altaAuto(listaAutos, TAMAUTO, idAuto, listaMarcas, TAMMARCA, listaColores, TAMCOLORES))
            {
                idAuto++;
            }
            break;
        case 'b':
            if(checkAuto(listaAutos, TAMAUTO))
            {
                modificarVehiculos(listaAutos, TAMAUTO, listaMarcas, TAMMARCA, listaColores, TAMCOLORES);
            } else
                {
                    printf("\nSe debe dar de ALTA a un auto antes de realizar esta accion.\n");
                }
            break;
        case 'c':
            if(checkAuto(listaAutos, TAMAUTO))
            {
                bajaAuto(listaAutos, TAMAUTO, listaMarcas, TAMMARCA, listaColores, TAMCOLORES);
            } else
                {
                    printf("\nSe debe dar de ALTA a un auto antes de realizar esta accion.\n");
                }
            break;
        case 'd':
            if(checkAuto(listaAutos, TAMAUTO))
            {
                system("cls");
                preOrdenarVehiculos(listaAutos, TAMAUTO, listaMarcas, TAMMARCA, listaColores, TAMCOLORES);
                mostrarAutos(listaAutos, TAMAUTO, listaMarcas, TAMMARCA, listaColores, TAMCOLORES);
            } else
                {
                    printf("\nSe debe dar de ALTA a un auto antes de realizar esta accion.\n");
                }
            break;
        case 'e':
            system("cls");
            mostrarMarcas(listaMarcas, TAMMARCA);
            break;
        case 'f':
            system("cls");
            mostrarColores(listaColores, TAMCOLORES);
            break;
        case 'g':
            system("cls");
            mostrarServicios(listaServicios, TAMSERVICIO);
            break;
        case 'h':
            if(altaTrabajo(listaTrabajos, TAMTRABAJO, listaAutos, TAMAUTO, listaServicios, TAMSERVICIO, listaMarcas, TAMMARCA, listaColores, TAMCOLORES, idTrabajo))
            {
                idTrabajo++;
            }
            break;
        case 'i':
            system("cls");
            mostrarTrabajos(listaTrabajos, TAMTRABAJO, listaServicios, TAMSERVICIO);
            break;
        case 'z':
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
    return 0;
}
