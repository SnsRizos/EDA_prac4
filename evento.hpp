/* Mijayl Mandzyak Melnyk 935521 Hector Manzano Miranda 926029
*/

#ifndef EVENTO_HPP
#define EVENTO_HPP

#include<iostream>
using namespace std;

// PREDECLARACION DEL TAD evento (inicio INTERFAZ)

/* Los valores del TAD evento representarán tuplas formadas como:
 (descripción, prioridad) siendo la descripción una cadena y la prioridad un número natural.}
*/
struct evento;
/* Dada una cadena descripcion, un entero prioridad, 
devuelve un evento e con esos datos. 
*/
void crearEvento(string descrip,int prio, evento& e);

/* Dado un evento e, devuelve la cadena correspondiente a la descripción de e. 
*/
string descripcion(const evento& e);

/* Dado un evento e y una cadena nueva, devuelve el evento e sustituyendo su antigua descripcion por nuevo. 
*/
void cambiarDescripcion( evento& e,string nuevo);

/* Dado un evento e, devuelve el entero correspondiente a la prioridad del evento e 
*/
int suPrioridad(const evento& e);

/* Dado un evento e y una entero pri, devuelve el evento e sustituyendo su antigua prioridad por pri. 
*/
void cambiarPrioridad(evento& e, int pri); 


// FIN de la PREDECLARACION DEL TAD producto (fin INTERFAZ)

// DECLARACION DEL TAD producto
struct evento {
  	friend void crearEvento(string descrip,int prio, evento& e);
  	friend string descripcion(const evento& e);
  	friend void cambiarDescripcion( evento& e,string nuevo);
  	friend int suPrioridad(const evento& e);
	friend void cambiarPrioridad(evento& e, int pri); 
  private:  //La estructura se compone de descrip y prio:
			//-descrip:es una cadena que tendra la información entorno al evento
			//-prio: es un entero que tendra la prioridad del evento.
    string descrip;
    int prio;
};


#endif
