#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    int precio;

}eServicio;

#endif // SERVICIOS_H_INCLUDED

int harcodearServicios(eServicio servicios[], int tamS, int cantidad);
void mostrarServicio(eServicio servicio);
void mostrarServicios(eServicio servicios[], int tamS);
int buscarIDServicioEnArray(eServicio servicios[], int tamS, int idParametro);
int mostrarDescServicios(int id, eServicio servicio[], int tamS, char desc[]);
