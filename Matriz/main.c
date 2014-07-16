/*
4.
Dada una matriz de donde cada celda tienen la siguiente estructura:
clave: números enteros
info: una estructura de datos
Se pide: Desarrollar una o más funciones para Informar la suma de todas las claves de cada una de las diagonales.
*/

#include <stdio.h>

#define TAM 3

typedef struct
{
    int stock;
}t_info;

typedef struct
{
    int clave;
    t_info info;
}t_celda;

void hardcodearDatos(t_celda*);
int sumaDiagPpal(t_celda[TAM][TAM], int, int);
int sumaDiagSecu(t_celda[TAM][TAM], int, int);

int main()
{
    t_celda matriz[TAM][TAM];
    printf("Ejercicio 4\n");

    hardcodearDatos(matriz);
    printf("\n\nSuma de la diagonal principal: %d", sumaDiagPpal(matriz, TAM, TAM));
    printf("\n\nSuma de la diagonal secundaria: %d", sumaDiagSecu(matriz, TAM, TAM));
    return 0;
}

int sumaDiagPpal(t_celda m[TAM][TAM], int f, int c)
{
    int i, suma=0;
    if(f!=c)
        return 0;
    for(i=0;i<f;i++)
        suma += m[i][i].clave;
    return suma;
}

int sumaDiagSecu(t_celda m[TAM][TAM], int f, int c)
{
    int i, suma=0;
    if(f!=c)
        return 0;
    for(i=0;i<f;i++)
        suma += m[i][f-i-1].clave;
    return suma;
}



void hardcodearDatos(t_celda * m)
{
    t_celda reg;
    reg.clave = 24;
    reg.info.stock = 30;
    *m=reg;
    m++;
    reg.clave = 44;
    reg.info.stock = 50;
    *m=reg;
    m++;
    reg.clave = 52;
    reg.info.stock = 58;
    *m=reg;
    m++;
    reg.clave = 60;
    reg.info.stock = 66;
    *m=reg;
    m++;
    reg.clave = 67;
    reg.info.stock = 73;
    *m=reg;
    m++;
    reg.clave = 76;
    reg.info.stock = 82;
    *m=reg;
    m++;
    reg.clave = 90;
    reg.info.stock = 96;
    *m=reg;
    m++;
    reg.clave = 100;
    reg.info.stock = 106;
    *m=reg;
    m++;
    reg.clave = 130;
    reg.info.stock = 136;
    *m=reg;
}
