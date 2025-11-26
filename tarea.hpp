/* Mijayl Mandzyak Melnyk 935521 Hector Manzano Miranda 926029
*/

#ifndef TAREA_HPP
#define TAREA_HPP

#include<iostream>
using namespace std;

// PREDECLARACION DEL TAD tarea (inicio INTERFAZ)

/* Los valores del TAD tarea representarán tuplas formadas como:
 (descripción, prioridad) siendo la descripción una cadena y la prioridad un número natural.}
*/
struct tarea;

/* Dada una cadena nombre,una cadena descripcion,una cadena unidad,un real tempEst, 
y una tarea t devuelve un tarea e con esos datos. 
*/
void crearTarea(string nom,string descripc,string unidad,double tempEst,tarea& t);

/* Dado un tarea t, devuelve la cadena correspondiente al nombre de t. 
*/
string nombre(const tarea& t);

/* Dado un tarea t, devuelve la cadena correspondiente a la descripción de t. 
*/
string descripcion(const tarea& t);

/* Dado un tarea t, devuelve la cadena correspondiente a la unidad de t. 
*/
string unidad(const tarea& t);

/* Dado un tarea t, devuelve el real correspondiente al tiempoEstimación de t. 
*/
double estimacion(const tarea& t);

/* Dado un tarea t, devuelve el real correspondiente al tiempoEmpleado de t. 
*/
double invertido(const tarea& t);

/* Dado una tarea t y una cadena newname, devuelve la tarea t sustituyendo su antiguo nombre  por newname. 
*/
void cambiarNombre( tarea& t,string newname);

/* Dado una tarea t y una cadena newdescrip, devuelve la tarea t sustituyendo su antigua descripción por newdescrip. 
*/
void cambiarDescripcion(tarea& t,string newdescrip);

/* Dado una tarea t y una cadena newunit, devuelve la tarea t sustituyendo su antigua unidad  por newunit. 
*/
void cambiarUnidad(tarea& t,string newunit);

/* Dado una tarea t y una real newesti, devuelve la tarea t sustituyendo su antiguo tiempoEstimado  por newesti. 
*/
bool cambiarTiempoEstimado(tarea& t,double newesti);

/* Dado una tarea t y una real newempl, devuelve la tarea t sustituyendo su antiguo tiempoEstimado  por newesti. 
*/
bool cambiarTiempoEmpleado(tarea& t, double newempl);


// FIN de la PREDECLARACION DEL TAD tarea (fin INTERFAZ)

// DECLARACION DEL TAD tarea
struct tarea {
  	friend void crearTarea(string nom,string descripc,string unidad,double tempEst,tarea& t);
    friend string nombre(const tarea& t);
    friend string descripcion(const tarea& t);
    friend string unidad(const tarea& t);
    friend double estimacion(const tarea& t);
    friend double invertido(const tarea& t);
    friend void cambiarNombre( tarea& t,string newname);
    friend void cambiarDescripcion(tarea& t,string newdescrip);
    friend void cambiarUnidad(tarea& t,string newunit);
    friend bool cambiarTiempoEstimado(tarea& t,double newesti);
    friend bool cambiarTiempoEmpleado(tarea& t, double newempl);
  	
  private:  //La estructura se compone de descrip y prio:
			//-descrip:es una cadena que tendra la información entorno al tarea
			//-prio: es un entero que tendra la prioridad del tarea.
    string nombre;
    string descrip;
    string unidadTiempo;
    double tiempoEstimado;
    double tiempoEmpleado;
};

//nombre, descripción, unidadTiempo, tiempoEstimado, tiempoEmpleado)
#endif
