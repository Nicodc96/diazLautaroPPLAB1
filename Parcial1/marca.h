#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

}eMarcas;

#endif // MARCA_H_INCLUDED

int harcodearMarcas(eMarcas marcas[], int tamM, int cantidad);
void mostrarMarca(eMarcas marca);
void mostrarMarcas(eMarcas marca[], int tamM);
int mostrarDescMarca(int id, eMarcas marca[], int tamM, char desc[]);
