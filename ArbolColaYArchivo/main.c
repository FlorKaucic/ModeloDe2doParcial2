#include <stdio.h>

typedef struct
{
    int stock;
}t_info;

typedef struct
{
    int clave;
    t_info info;
}t_reg;

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
int armarCola(t_cola *, t_arbol *);
int cargarEnCola(t_cola *, int, t_info *);

int abrirArchivo(FILE **, const char *, const char *, const int);
void hardcodearDatosArchivo(FILE **);
void mostrarArchivo(FILE **);
void actualizarArchivo(FILE **, t_cola *);

int main()
{
    printf("Ejercicio 1 y 2\n");
    t_arbol arbol;
    t_cola cola;
    FILE * pf;

    crearArbol(&arbol);
    hardcodearDatosArbol(&arbol);
    crearCola(&cola);
    printf("\n\nSe recorrieron %d nodos.\n", armarCola(&cola, &arbol->der));


    //Para hardcodear los datos del archivo
    if(!abrirArchivo(&pf,"datos.dat","wb+",1))
        return 0;
    hardcodearDatosArchivo(&pf);
    fclose(pf);


    if(!abrirArchivo(&pf,"datos.dat","rb+",1))
        return 0;

    printf("\n\nArchivo pre proceso:");
    mostrarArchivo(&pf);

    actualizarArchivo(&pf, &cola);

    printf("\n\nArchivo post proceso:");
    mostrarArchivo(&pf);

    fclose(pf);
    return 1;
}


void crearArbol(t_arbol * p)
{
    *p = NULL;
}

void hardcodearDatosArbol(t_arbol * p)
{
    t_info info;
    info.stock = 500000;
    insertarEnArbol(p, 50, &info);
    info.stock = 300000;
    insertarEnArbol(p, 30, &info);
    info.stock = 420000;
    insertarEnArbol(p, 42, &info);
    info.stock = 240000;
    insertarEnArbol(p, 24, &info);
    info.stock = 430000;
    insertarEnArbol(p, 43, &info);
    info.stock = 390000;
    insertarEnArbol(p, 39, &info);
    info.stock = 700000;
    insertarEnArbol(p, 70, &info);
    info.stock = 600000;
    insertarEnArbol(p, 60, &info);
    info.stock = 800000;
    insertarEnArbol(p, 80, &info);
    info.stock = 740000;
    insertarEnArbol(p, 74, &info);
    info.stock = 760000;
    insertarEnArbol(p, 76, &info);
    info.stock = 550000;
    insertarEnArbol(p, 55, &info);
    info.stock = 650000;
    insertarEnArbol(p, 65, &info);
    info.stock = 670000;
    insertarEnArbol(p, 67, &info);
    info.stock = 640000;
    insertarEnArbol(p, 64, &info);
    info.stock = 590000;
    insertarEnArbol(p, 59, &info);
    info.stock = 520000;
    insertarEnArbol(p, 52, &info);
    info.stock = 900000;
    insertarEnArbol(p, 90, &info);
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

int armarCola(t_cola * pc, t_arbol * pa)
{
    if(*pa)
        if(!(*pa)->izq&&!(*pa)->der)
            return (((*pa)->clave%2)==0)?cargarEnCola(pc, (*pa)->clave, &(*pa)->info):1;
        else
            return 1+armarCola(pc, &(*pa)->izq)+armarCola(pc, &(*pa)->der);
    return 0;
}

int cargarEnCola(t_cola * p, int cla, t_info * dat)
{
    cola_t_nodo * nue = (cola_t_nodo *)malloc(sizeof(cola_t_nodo));
    if(!nue)
        return 0;
    nue->clave = cla;
    nue->info = *dat;
    if(*p)
    {
        nue->sig = (*p)->sig;
        (*p)->sig = nue;
    }
    else
        nue->sig = nue;
    *p = nue;
    return 1;
}

int sacarDeCola(t_cola * p)
{
    cola_t_nodo * aux;
    if(!*p)
        return 0;
    aux = (*p)->sig;
    if(aux==(*p))
        *p=NULL;
    else
        (*p)->sig = aux->sig;
    free(aux);
    return 1;
}

int abrirArchivo(FILE ** pf, const char * arch, const char * modo, const int msj)
{
    *pf = fopen(arch, modo);
    if(!*pf&&msj==1)
        printf("ERROR: No se pudo abrir %s en modo %s\n",arch,modo);
    return *pf;
}


void hardcodearDatosArchivo(FILE **pf)
{
    t_reg reg;
    reg.clave = 24;
    reg.info.stock = 30;
    fwrite(&reg,sizeof(reg),1,*pf);
    reg.clave = 44;
    reg.info.stock = 50;
    fwrite(&reg,sizeof(reg),1,*pf);
    reg.clave = 52;
    reg.info.stock = 58;
    fwrite(&reg,sizeof(reg),1,*pf);
    reg.clave = 60;
    reg.info.stock = 66;
    fwrite(&reg,sizeof(reg),1,*pf);
    reg.clave = 67;
    reg.info.stock = 73;
    fwrite(&reg,sizeof(reg),1,*pf);
    reg.clave = 76;
    reg.info.stock = 82;
    fwrite(&reg,sizeof(reg),1,*pf);
    reg.clave = 90;
    reg.info.stock = 96;
    fwrite(&reg,sizeof(reg),1,*pf);
    reg.clave = 100;
    reg.info.stock = 106;
    fwrite(&reg,sizeof(reg),1,*pf);
    reg.clave = 130;
    reg.info.stock = 136;
    fwrite(&reg,sizeof(reg),1,*pf);
}

void mostrarArchivo(FILE **pf)
{
    t_reg reg;
    rewind(*pf);
    fread(&reg, sizeof(reg), 1, *pf);
    while(!feof(*pf))
    {
        printf("\nReg: %d   %d", reg.clave, reg.info.stock);
        fread(&reg, sizeof(reg), 1, *pf);
    }
}

void actualizarArchivo(FILE **pf, t_cola * pc)
{
    int cmp;
    t_reg reg;
    if(!*pc)
        return;
    rewind(*pf);
    fread(&reg, sizeof(reg), 1, *pf);
    while(*pc&&!feof(*pf))
    {
        while(!feof(*pf)&&(cmp=compararClave(((*pc)->sig)->clave, reg.clave))>=0)
        {
            if(cmp==0)
            {
                reg.info = ((*pc)->sig)->info;
                fseek(*pf, -sizeof(reg), SEEK_CUR);
                fwrite(&reg, sizeof(reg), 1, *pf);
                fseek(*pf, 0L, SEEK_CUR);
            }
            fread(&reg, sizeof(reg), 1, *pf);
        }
        sacarDeCola(pc);
    }
}
