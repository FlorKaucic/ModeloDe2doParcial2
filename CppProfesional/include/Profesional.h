#ifndef PROFESIONAL_H
#define PROFESIONAL_H

#include <iostream>

using namespace std;

/*
3. Declare y desarrolle una clase Profesional con los siguientes atributos y funciones miembro:
nombre (con asignación dinámica de memoria)
matricula(int)
sueldo (float)
Un constructor parametrizado por defecto.
Destructor
Sobrecarga de operadores: =, + (que permita hacer Profesional + flota, para incrementar el sueldo), >>.
Confeccione un main que utilice las funciones creadas.
Agregue, todas las funciones miembro que necesite para el buen funcionamiento de los operadores pedidos
Las variables miembros de todas las clases deben ser privadas. Los métodos de cada clase deben ser públicos y desarrollados fuera de la clase.
*/

class Profesional
{
    private:
        char * nombre;
        int matricula;
        float sueldo;
    public:
        Profesional(char * = NULL, int = 0, float = 0);
        virtual ~Profesional();
        Profesional& operator=(const Profesional&);
        Profesional operator+(const float) const;
        friend ostream& operator<<(ostream&, const Profesional&);
        friend istream& operator>>(istream&, Profesional&);
};

char * duplicarCadena(char *);
char * str_cpy(char *, char *);
int str_len(char *);

#endif // PROFESIONAL_H
