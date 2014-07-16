#include <stdio.h>

/*
Dado una cadena de caracteres, cuyos elementos son dígitos numéricos y un número entero de 3 cifras ingresado por teclado. Validar el número ingresado.
Se pide desarrollar una función que retorne la cantidad de veces que el número entero esta contenido en la cadena de caracteres.
Ejemplo:
Cadena de caracteres: “1231245123451111”
Número entero	        123	111	452
Número de ocurrencias	2	1	0
*/

#define aMayus(x) ((x)>='a'&&(x)<='z')?(x)-32:(x);

int encontrarOcurrencias(char *, char *);
int esIgual(char **, char *);
int seguir();

int main()
{
    char cadena[] = "1231245123451111";
    char nro[20];
    int aux;
    printf("Ejercicio 5");
    do{
        printf("\n\n\nLa cadena es: %s", cadena);
        printf("\nIngrese el numero entero: ");
        scanf("%d", &aux);
        sprintf(nro, "%d", aux);
        printf("\nEl numero ingresado es: %s", nro);
        printf("\n\nNumero de ocurrencias: %d", encontrarOcurrencias(cadena, nro));
    }while(seguir());
    return 0;
}

int encontrarOcurrencias(char * c1, char * c2)
{
    int cont = 0;
    while(*c1)
    {
        if(*c1==*c2&&esIgual(&c1,c2))
            cont++;
        c1++;
    }
    return cont;
}


int seguir()
{
    char aux;
    printf("\n\nIngrese 'S' para Salir. Cualquier otro valor para seguir.\nSeguir? ");
    fflush(stdin);
    scanf("%c", &aux);
    aux = aMayus(aux);
    return aux!='S';
}

int esIgual(char ** c1, char * c2)
{
    while(**c1&&*c2&&**c1==*c2)
    {
        (*c1)++;
        c2++;
    }
    (*c1)--;
    if(!*c2)
        return 1;
    return 0;
}
