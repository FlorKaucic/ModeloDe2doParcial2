#include "Profesional.h"

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


int main()
{
    Profesional pro1;
    Profesional pro2("Juan Perez", 45678, 12345.67);
    cout << "Ejercicio 3" << endl;
    cout << pro1 << pro2;
    pro1 = pro2;
    cout << pro1;
    cin >> pro1;
    pro2 = pro2 + 9999.5;
    cout << pro1 << pro2;
    return 0;
}
