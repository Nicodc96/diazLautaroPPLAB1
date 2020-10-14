#ifndef COLORAUTO_H_INCLUDED
#define COLORAUTO_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];

}eColor;

#endif // COLORAUTO_H_INCLUDED

int harcodearColores(eColor colores[], int tamC, int cantidad);
void mostrarColor(eColor col);
void mostrarColores(eColor colores[], int tamC);
int mostrarDescColor(int id, eColor color[], int tamC, char desc[]);

