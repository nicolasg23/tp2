#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define MAX 10

struct agend{
    char apellido [50];
    char nombre[50];
    int edad,documento;

    int estado;

};

typedef struct agend agend;

void inicio(agend agenda[MAX]);
void carga(agend agenda[MAX]);
void baja(agend agenda[MAX]);
int buscar(agend agenda[MAX]);
void busqueda(agend agenda[MAX]);
void ordenarNombre(agend agenda[MAX]);
void imprimirGrafico(agend agenda[MAX]);



#endif // FUNCIONES_H_INCLUDED
