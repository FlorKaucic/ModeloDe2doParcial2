#include "Profesional.h"

#include <iostream>

using namespace std;

Profesional::Profesional(char * nombre, int matricula, float sueldo):nombre(duplicarCadena(nombre)), matricula(matricula), sueldo(sueldo)
{

}

Profesional::~Profesional()
{
    //dtor
    delete[] nombre;
}

Profesional& Profesional::operator=(const Profesional& obj)
{
    nombre = duplicarCadena(obj.nombre);
    matricula = obj.matricula;
    sueldo = obj.sueldo;
    return *this;
}

Profesional Profesional::operator+(const float aumento) const
{
    return Profesional(nombre, matricula, sueldo+aumento);
}

ostream& operator<<(ostream& os, const Profesional& obj)
{
    os<<endl;
    os<<endl<<"Profesional: "<<((obj.nombre)?obj.nombre:"");
    os<<endl<<"Matricula: "<<obj.matricula;
    os<<endl<<"Sueldo: "<<obj.sueldo;
    os<<endl;
    return os;
}

istream& operator>>(istream& is, Profesional& obj)
{
    char aux[100];
    cout<<endl<<endl<<"Ingresar nombre: ";
    is.getline(aux, 100, '\n');
    obj.nombre = duplicarCadena(aux);
    cout<<endl<<"Ingresar matricula: ";
    is>>obj.matricula;
    cout<<endl<<"Ingresar sueldo: ";
    is>>obj.sueldo;
    return is;
}

char * duplicarCadena(char * s)
{
    if(s&&*s)
    {
        try
        {
            return str_cpy(new char[str_len(s)+1], s);
        }
        catch(bad_alloc& e)
        {
            cerr<<e.what();
        }
    }
    return NULL;
}

char * str_cpy(char * c1, char * c2)
{
    char * inicio = c1;
    while(*c2)
    {
        *c1 = *c2;
        c1++;
        c2++;
    }
    *c1='\0';
    return inicio;
}

int str_len(char * c)
{
    int cont=0;
    while(*c)
    {
        cont++;
        c++;
    }
    return cont;
}
