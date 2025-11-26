/* Mijayl Mandzyak Melnyk 935521 Hector Manzano Miranda 926029
*/
#include <iostream>
#include "evento.hpp"

using namespace std;

/* Dada una cadena descripcion, un entero prioridad, 
devuelve un evento e con esos datos. 
*/
void crearEvento(string descrip,int prio, evento& e){
	e.descrip=descrip;
	e.prio=prio;

}

/* Dado un evento e, devuelve la cadena correspondiente a la descripción de e. 
*/
string descripcion(const evento& e){

	return e.descrip;

}

/* Dado un evento e y una cadena nueva, devuelve el evento e sustituyendo su antigua descripcion por nuevo. 
*/
void cambiarDescripcion( evento& e,string nuevo){

	e.descrip=nuevo;

}

/* Dado un evento e, devuelve el entero correspondiente a la prioridad del evento e 
*/
int suPrioridad(const evento& e){

	return e.prio;
}

/* Dado un evento e y una entero pri, devuelve el evento e sustituyendo su antigua prioridad por pri. 
*/
void cambiarPrioridad(evento& e, int newpri){

	e.prio=newpri;

}
