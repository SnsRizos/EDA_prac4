/* Mijayl Mandzyak Melnyk 935521 Hector Manzano Miranda 926029
*/
#include <iostream>
#include "tarea.hpp"

using namespace std;

/* Dada una cadena nombre,una cadena descripcion,una cadena unidad,un real tempEst, 
y una tarea t devuelve un tarea e con esos datos. 
*/
void crearTarea(string nom,string descripc,string unidad,double tempEst,tarea& t){
	t.nombre=nom;
	t.descrip=descripc;
	t.unidadTiempo=unidad;
	t.tiempoEstimado=tempEst;
	t.tiempoEmpleado=0.0;

}

/* Dado un tarea t, devuelve la cadena correspondiente al nombre de t. 
*/
string nombre(const tarea& t){

	return t.nombre;

}

/* Dado un tarea t, devuelve la cadena correspondiente a la descripción de t. 
*/
string descripcion(const tarea& t){

	return t.descrip;

}

/* Dado un tarea t, devuelve la cadena correspondiente a la unidad de t. 
*/
string unidad(const tarea& t){

	return t.unidadTiempo;

}

/* Dado un tarea t, devuelve el real correspondiente al tiempoEstimación de t. 
*/
double estimacion(const tarea& t){

	return t.tiempoEstimado;

}

/* Dado un tarea t, devuelve el real correspondiente al tiempoEmpleado de t. 
*/
double invertido(const tarea& t){

	return t.tiempoEmpleado;

}

/* Dado una tarea t y una cadena newname, devuelve la tarea t sustituyendo su antiguo nombre  por newname. 
*/
void cambiarNombre( tarea& t,string newname){

	t.nombre=newname;

}

/* Dado una tarea t y una cadena newdescrip, devuelve la tarea t sustituyendo su antigua descripción por newdescrip. 
*/
void cambiarDescripcion( tarea& t,string newdescrip){

	t.descrip=newdescrip;

}

/* Dado una tarea t y una cadena newunit, devuelve la tarea t sustituyendo su antigua unidad  por newunit. 
*/
void cambiarUnidad( tarea& t,string newunit){

	t.descrip=newunit;

}

/* Dado una tarea t y una real newesti, devuelve la tarea t sustituyendo su antiguo tiempoEstimado  por newesti. 
*/
bool cambiarTiempoEstimado( tarea& t,double newesti){
	if(newesti>0.0){
		t.tiempoEstimado=newesti;
		return true;
	}else{
		return false;
	}
}

/* Dado una tarea t y una real newempl, devuelve la tarea t sustituyendo su antiguo tiempoEstimado  por newesti. 
*/
bool cambiarTiempoEmpleado(tarea& t, double newempl){
	if(newempl>0.0){
		t.tiempoEmpleado=newempl;
		return true;
	}else{
		return false;
	}
}
