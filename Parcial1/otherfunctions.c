#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "otherfunctions.h"
#include "validaciones.h"

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
    printf("Z) SALIR\n\n");
    printf("Elija una opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = tolower(opcion);

    return opcion;
}

void menuDeInformesCases()
{
    char salir = 'n';

    do
    {
        switch(menuDeInformes())
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
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

    printf("------------------------------------------------------\n");
    printf("------------------ MENU DE INFORMES ------------------\n");
    printf("------------------------------------------------------\n\n");
    printf("1) \n");
    printf("2) \n");
    printf("3) \n");
    printf("4) \n");
    printf("5) \n");
    printf("6) \n");
    printf("7) \n");
    printf("8) \n");
    printf("9) \n");
    printf("10) \n");
    printf("11) SALIR\n");
    printf("Elija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
