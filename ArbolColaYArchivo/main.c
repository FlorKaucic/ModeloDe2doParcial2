#include <stdio.h>

typedef struct
{
    int stock;
}t_info;

typedef struct arbol_s_nodo
{
    int clave;
    t_info info;
    struct arbol_s_nodo * izq;
    struct arbol_s_nodo * der;
}arbol_t_nodo;

typedef struct cola_s_nodo
{
    int clave;
    t_info info;
    struct cola_s_nodo * sig;
}cola_t_nodo;

typedef arbol_t_nodo * t_arbol;

typedef cola_t_nodo * t_cola;

void crearArbol(t_arbol *);
void hardcodearDatosArbol(t_arbol *);
int insertarEnArbol(t_arbol *, const int, const t_info *);

int compararClave(int, int);

void crearCola(t_cola *);



int main()
{
    printf("Ejercicio 1 y 2\n");
    t_arbol arbol;
    t_cola cola;


    crearArbol(&arbol);
    hardcodearDatosArbol(&arbol);

    return 0;
}


void crearArbol(t_arbol * p)
{
    *p = NULL;
}

void hardcodearDatosArbol(t_arbol * p)
{
    t_info info;
    info.stock = 50;
    insertarEnArbol(p, 50, &info);
    info.stock = 30;
    insertarEnArbol(p, 30, &info);
    info.stock = 42;
    insertarEnArbol(p, 42, &info);
    info.stock = 24;
    insertarEnArbol(p, 24, &info);
    info.stock = 43;
    insertarEnArbol(p, 43, &info);
    info.stock = 39;
    insertarEnArbol(p, 39, &info);
    info.stock = 70;
    insertarEnArbol(p, 70, &info);
    info.stock = 60;
    insertarEnArbol(p, 60, &info);
    info.stock = 80;
    insertarEnArbol(p, 80, &info);
    info.stock = 90;
    insertarEnArbol(p, 90, &info);
    info.stock = 75;
    insertarEnArbol(p, 75, &info);
    info.stock = 76;
    insertarEnArbol(p, 76, &info);
    info.stock = 55;
    insertarEnArbol(p, 55, &info);
    info.stock = 65;
    insertarEnArbol(p, 65, &info);
    info.stock = 67;
    insertarEnArbol(p, 67, &info);
    info.stock = 64;
    insertarEnArbol(p, 64, &info);
    info.stock = 59;
    insertarEnArbol(p, 59, &info);
    info.stock = 52;
    insertarEnArbol(p, 52, &info);
}

int insertarEnArbol(t_arbol * p, const int cla, const  t_info * d)
{
    int cmp;
    if(*p)
    {
        if((cmp=compararClave(cla, (*p)->clave))==0)
            return 0;
        if(cmp>0)
            return insertarEnArbol(&(*p)->der, cla, d);
        else
            return insertarEnArbol(&(*p)->izq, cla, d);
    }

    (*p) = (arbol_t_nodo *)malloc(sizeof(arbol_t_nodo));
    if(!*p)
        return 0;
    (*p)->clave = cla;
    (*p)->info = *d;
    (*p)->der = NULL;
    (*p)->izq = NULL;
    return 1;
}

int compararClave(int c1, int c2)
{
    return c1-c2;
}

void crearCola(t_cola * p)
{
    *p = NULL;
}
