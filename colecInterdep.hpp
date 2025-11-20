/* Mijayl Mandzyak Melnyk 935521 Hector Manzano Miranda 926029*/
#ifndef COLECINTEDEP_HPP
#define COLECINTEDEP_HPP

#include "pila.hpp"
// PREDECLARACION DEL TAD GENERICO colecInterdep (inicio INTERFAZ)

/* El TAD GENERICO  colecInterdep es una colección ordenada de elementos cuyo dominio de valores seran de datos
 * booleanos(bool) y datos naturales(int).
 * Los valores del TAD representan colecciones de elementos formados como tuplas de la forma (I, V, -, numDepend) 
 * o bien (I, V, dep, numDepend). A los elementos con forma (I, V, -, NumDepend) los llamaremos  en general 
 * ‘elementos independientes’, mientras que a los elementos con forma (I, V, dep, numDepend), los llamaremos en
 * general ‘elementos dependientes’. En la colección no podrá haber dos elementos con el mismo I.
 * Todas las funciones de la colcección tienen coste lineal O(n) salvo crear, tamanyo y esVacia que tienen coste
 * constante. Todas las funciones del iterador tienen coste constante.
 * Igualmente, el coste en memoria de esta implementación será O(N).
 * 
 * Al parámetro formal I le exigimos estar dotado de los operadores habituales de: 
 * Comparación de igualdad == , y anterior <
 * bool operator==(const I& i1, const I& i2); Devuelve TRUE si i1 es igual i2;
 * bool operator<(const I& i1, const I& i2);  Devuelve TRUE si i1 es anterior a i2;
 */ 
template<typename I,typename V> struct colecInterdep;




/* Crea una colección c vacía, sin elementos.
*/
template<typename I,typename V> void crear(colecInterdep<I,V>& c);


/* Devuelve el número de elementos que hay en una colección c en forma de entero.
*/
template<typename I,typename V> int tamanyo(colecInterdep<I,V>& c);


/* Devuelve en forma de booleano si la colección c es vacía, es decir, no tiene ningún elemento.
 * Devuelve TRUE si y solo si esta es vacía y false si no lo es.
*/
template<typename I,typename V> bool esVacia(colecInterdep<I,V>& c);


/* Devuelve en forma de booleano TRUE si y solo si en la colección c hay un elemento con el identificador aportado.
 * Devuelve FALSE en caso contrario.
*/
template<typename I,typename V> bool existe(const I& id, colecInterdep<I,V>& c);



/*
 *
*/
template<typename I,typename V> bool existeDepOIndep(const I& id, colecInterdep<I,V>& c, bool& depende);


/* Si no se encuentra un elemento con el identificador id en la colección c devuelve el resultante de añadir el elemento 
 * independiente (id,v,-,0) a la colección c. En caso de que exista un elemento con tal identificador devuelve una
 * igual a c sin modificar.
*/
template<typename I,typename V> void anyadirIndependiente(colecInterdep<I,V>& c, const I& id, const V& v);


/* Si no se encuentra un elemento con identificador id en la colección y existe un elemento con identificador super 
 * devuelve el resultante de añadir el elemento dependiente (id,v,super,0) a la colección c e incrementar en 1 el 
 * número de elementos dependientes del elemento con identificador super. En caso de que exista un elemento con tal 
 * identificador o no exista un elemento con identificador super devuelve una colección igual a c sin modificar.
*/
template<typename I,typename V> void anyadirDependiente(colecInterdep<I,V>& c, const I& id, const V& v, const I& super);


/* Si existe un elemento con identificador id en la colección c y existe un elemento con identificador super incrementa
 * en 1 el el número de elementos dependientes del elemento con identificador super y hace dependiente al elemento
 * con identificador id del de super. En caso de que el elemento con identificador id dependiese de otro elemento previamente,
 * decrementa en 1 el numero de elementos dependientes de dicho elemento del que dependia. Si no existe un elemento 
 * con el identificador id en la colección o no existe un elemento con identificador super devuelve una colección igual
 * a c sin modificar.
*/
template<typename I,typename V> void hacerDependiente(colecInterdep<I,V>& c, const I& id, const I& super);


/* Si existe un elemento con identificador id en la colección c y este es dependiente de otro elemento decrementa 
 * en 1 el número de elementos dependientes del elemento del que dependía y hacer independiente el elemento con identificador 
 * id. Si no existe un elemento con el identificador id en la colección o este ya era un elemento con independiente
 * super devuelve una colección igual a c sin modificar.
*/
template<typename I,typename V> void hacerIndependiente(colecInterdep<I,V>& c, const I& id);


/* Si existe un elemento con el identificador id en la colección c actualiza su valor v por el valor nuevo y devuelve
 * en forma de booleano TRUE si y solo si se ha actualizado correctamente. Devuelve FALSE si no se ha podido actualizar 
 * por la inexistencia del elemento.
*/
template<typename I,typename V> bool actualizarVal(colecInterdep<I,V>& c, const I& id, const V& nuevo);


/* Si existe un elemento con identificador id en la colección c le proporciona a val el valor v del elemento y devuelve 
 * en forma de booleano TRUE si y solo si el valor val se ha actualizado correctamente. Devuelve FALSE si no se ha
 * podido actualizar por la inexistencia del elemento en la colección.
*/
template<typename I,typename V> bool obtenerVal(const I& id, colecInterdep<I,V>& c, V& val);


/* Si existe un elemento con identificador id en la colección le proporciona a sup el identificador del elemento del 
 * que depende el elemento con identidicador id y devuelve en forma de booleano TRUE si y solo si el identificador sup
 * se ha actualizado correctamente. Devuelve FALSE si no se ha podido actualizar por la inexistencia del elemento.
*/
template<typename I,typename V> bool obtenerSupervisor(const I& id, colecInterdep<I,V>& c, I& sup);


/* Si existe un elemento con identificador id en la colección c devuelve en forma de entero el numero de elementos que 
 * dependen del elemento. Devuelve -1 si existe tal elemento en la coleccion c.
*/
template<typename I,typename V> int obtenerNumDependientes(const I& id, colecInterdep<I,V>& c);


/* Si existe un elemento con identificador id en la colección le proporciona a val el valor v del elemento y a numDep el
 * número de elementos que dependen de este. Si el elemento es dependiente de otro le proporciona a sup el identificador 
 * del elemento del que depende y le asigna al booleano depende TRUE. Si este elemento es independiente sup no se modifica
 * y le asigna al booleano depende FALSE.
 * La función devuelve en forma de booleano TRUE si y solo si se ha encontrado el elemento y, por tanto, se ha podido obtener 
 * estos datos. Devuelve FALSE en caso contrario.
*/
template<typename I,typename V> bool obtenerDatos(const I& id, colecInterdep<I,V>& c, V& val, I& sup, int& numDep, bool& depende);


/* Si existe un elemento con el identificador id en la colección c y no tiene elementos dependientes (numDepend es 0) 
 * devuelve la colección resultante de eliminar el elemento de la colección c. Si este elemento es dependiente además 
 * decrementa en 1 el numero de elementos dependientes del que este dependía.
 * Si el elemento no existe devuelve la misma colección c sin modificar.
*/
template<typename I,typename V> void borrar(const I& id, colecInterdep<I,V>& c);


/* Inicia el iterador para que el siguiente elemento a visitar sea la raiz elemento de la colección c, si existe.
*/
template<typename I,typename V> void iniciarIterador(colecInterdep<I,V>& c);


/* Devuelve en forma de booleano TRUE si y solo si queda algún elemento por visitar en la colección c y FALSE en caso 
 * contrario.
*/
template<typename I,typename V> bool existeSiguiente(colecInterdep<I,V>& c);


/* Si queda algún elemento por visitar en la colección modifica id con el identificador del elemento visitado y devuelve
 * TRUE en forma de booleano. En caso contrario devuelve FALSE. 
*/
template<typename I,typename V> bool siguienteIdent(colecInterdep<I,V>& c, I& id);


/* Si queda algún elemento por visitar en la colección c modifica val con el valor del elemento visitado y devuelve 
 * TRUE en forma de booleano. En caso contrario devuelve FALSE. 
*/
template<typename I,typename V> bool siguienteVal(colecInterdep<I,V>& c, V& val);


/* Devuelve en forma de booleano TRUE si y solo si queda algún elemento por visitar en la colección c y dicho elemento
 * es dependiente de otro. Devuelve FALSE si no se cumplen ambas condiciones.
*/
template<typename I,typename V> bool siguienteDependiente(colecInterdep<I,V>& c);


/* Si queda algún elemento dependiente por visitar en la colección c modifica sup con el identificador del elemento del 
 * que depende el elemento visitado y devuelve TRUE en forma de booleano. En caso de que no queden elemetos por visitar
 * o que este sea independiente devuelve FALSE. 
*/
template<typename I,typename V> bool siguienteSuperior(colecInterdep<I,V>& c, I& sup);


/* Si queda algún elemento por visitar en la colección c devuelve el numero de elementos dependientes del elemento visitado
 * en forma de entero. Devuelve -1 si no se quedan elementos por visitar.
*/
template<typename I,typename V> int siguienteNumDependientes(colecInterdep<I,V>& c);


/* Devuelve en forma de booleano TRUE si existen elementos por visitar en la colección c y hace que el iterador avance para
 * visitar el siguiente elemento de la colección. Devuelve FALSE en caso contrario y no avanza.
*/
template<typename I,typename V> bool avanza(colecInterdep<I,V>& c);

////Apartir de aqui PRIVADO///////////////////////////////////////////////////


	template<typename I,typename V> typename colecInterdep<I,V>::Nodo*& buscar(typename colecInterdep<I,V>::Nodo*& buscado, const I& id);
	template<typename I,typename V> void anyadirIndependienteRec(typename colecInterdep<I,V>::Nodo* &c, const I& id, const V& v, bool &anyadido);
	template<typename I,typename V> void anyadirDependienteRec(typename colecInterdep<I,V>::Nodo* &c, const I& id, const V& v, typename colecInterdep<I,V>::Nodo* pSup, bool &anyadido);
	template<typename I,typename V> void desengancharMaximo(typename colecInterdep<I,V>::Nodo* &pBuscado, typename colecInterdep<I,V>::Nodo* &pMax);

// DECLARACION DEL TAD GENERICO colecInterdep

template<typename I,typename V>
struct colecInterdep{
	//COLEC
	friend void crear<I,V>(colecInterdep<I,V>& c);
	friend int tamanyo<I,V>(colecInterdep<I,V>& c);
	friend bool esVacia<I,V>(colecInterdep<I,V>& c);
	friend bool existe<I,V>(const I& id, colecInterdep<I,V>& c);
	friend bool existeDepOIndep<I,V>(const I& id, colecInterdep<I,V>& c, bool& depende);
	friend void anyadirIndependiente<I,V>(colecInterdep<I,V>& c, const I& id,const V& v);
	friend void anyadirDependiente<I,V>(colecInterdep<I,V>& c, const I& id, const V& v, const I& super);
	friend void hacerDependiente<I,V>(colecInterdep<I,V>& c,const I& id, const I& super);
	friend void hacerIndependiente<I,V>(colecInterdep<I,V>& c, const I& id);
	friend bool actualizarVal<I,V>(colecInterdep<I,V>& c, const I& id, const V& v);
	friend bool obtenerVal<I,V>(const I& id, colecInterdep<I,V>& c, V& val);
	friend bool obtenerSupervisor<I,V>(const I& id, colecInterdep<I,V>& c, I& sup);
	friend int obtenerNumDependientes<I,V>(const I& id, colecInterdep<I,V>& c);
	friend bool obtenerDatos<I,V>(const I& id, colecInterdep<I,V>& c, V& val, I& sup, int& numDep, bool& depende);
	friend void borrar<I,V>(const I& id, colecInterdep<I,V>& c);


	//ITR
	friend void iniciarIterador<I,V>(colecInterdep<I,V>& c);
	friend bool existeSiguiente<I,V>(colecInterdep<I,V>& c);
	friend bool siguienteIdent<I,V>(colecInterdep<I,V>& c, I& id);
	friend bool siguienteVal<I,V>(colecInterdep<I,V>& c, V& val);
	friend bool siguienteDependiente<I,V>(colecInterdep<I,V>& c);
	friend bool siguienteSuperior<I,V>(colecInterdep<I,V>& c, I& sup);
	friend int siguienteNumDependientes<I,V>(colecInterdep<I,V>& c);
	friend bool avanza<I,V>(colecInterdep<I,V>& c);

    

  private: /* En esta implementación la colección se representará en memoria dinámica como una lista enlazada de Nodos ordenada 
  			* por el identificdor de los elementos de menor a mayor con: 
	        * - el puntero.raiz: apuntando a la Nodo que contiene la raiz elemento de la colección, será nullptr si la colección
			* está vacía
		    * - el campo tam: mantendrá calculado el tamaño o número de elementos en la colección, será 0 si la pila está vacía 
		    * - el puntero itr: se utilizará para mantener el estado del iterador, y únicamente será utilizado por las operaciones 
			* iniciarIterador, existeSiguiente, siguienteIdent, siguienteVal, siguienteDependiente, siguienteSuperior, siguienteNumDependientes
			* y avanza.
			* Cada Nodo contendrá un identificador (en su campo ident), un valor (en su campo valor), apuntará con su puntero dep 
			* al elemento del que es dependiente o a nullptr si es independiente, un entero que almacenará el número de elementos 
			* que dependen de este y apuntará con su puntero sig a la próxima Nodo que contenga la raiz elemento con un identificador
			* mayor a este o a nullptr si este es el elemento con mayor identificador.
	   
    Todas las funciones de la colcección tienen coste lineal O(n) salvo crear, tamanyo y esVacia que tienen coste
	constante. Todas las funciones del iterador tienen coste constante.
	Igualmente, el coste en memoria de esta implementación será O(N).
	*/
	
	struct Nodo{
		I ident;
		V valor;
		Nodo* dep;
		int numDepend;
		Nodo* izq;
		Nodo* der;
	};


 Nodo* raiz;
	int tam;
    //CAMPOS ITERADOR
 Pila<Nodo*>itr;


	//AUX
	friend typename colecInterdep<I,V>::Nodo*& buscar<I,V>(typename colecInterdep<I,V>::Nodo*& buscado, const I& id);
	friend void anyadirIndependienteRec<I,V>(typename colecInterdep<I,V>::Nodo* &c, const I& id, const V& v, bool &anyadido);
	friend void anyadirDependienteRec<I,V>(typename colecInterdep<I,V>::Nodo* &c, const I& id, const V& v, typename colecInterdep<I,V>::Nodo* pSup, bool &anyadido);
	friend void desengancharMaximo<I,V>(typename colecInterdep<I,V>::Nodo* &pBuscado, typename colecInterdep<I,V>::Nodo* &pMax);
};


//OPERACIONES

/* Devuelve el número de elementos que hay en una colección c en forma de entero.
*/
template<typename I,typename V> 
void crear(colecInterdep<I,V>& c){
	c.tam=0;
	c.raiz=nullptr;
	crearVacia(c.itr);

}


/* Dada una colección "c", devuelve el número de elementos que hay en esta en forma de entero.
*/
template<typename I,typename V>
int tamanyo(colecInterdep<I,V>& c){
	return c.tam;

}


/* Devuelve en forma de booleano si la colección c es vacía, es decir, no tiene ningún elemento.
 * Devuelve TRUE si y solo si esta es vacía, es decir c.raiz apunta a nullptr y false si no lo es.
*/
template<typename I,typename V>
bool esVacia(colecInterdep<I,V>& c){
	return c.raiz == nullptr;
}





/* Devuelve en forma de booleano TRUE si y solo si en la colección c hay un elemento con el identificador aportado.
 * Devuelve FALSE en caso contrario.
*/
template<typename I,typename V> 
bool existe(const I& id, colecInterdep<I,V>& c){
	typename colecInterdep<I,V>:: Nodo* pAux = buscar<I,V>(c.raiz, id);
	return pAux != nullptr;
}





template<typename I,typename V>
bool existeDepOIndep(const I& id, colecInterdep<I,V>& c, bool& depende){
	typename colecInterdep<I,V>:: Nodo* pAux = buscar<I,V>(c.raiz, id);
	if(pAux!=nullptr){
		if(pAux->dep==nullptr){
			depende = false;
		}
		else{
			depende = true;
		}
		return true;
	}
	else{
		return false;
	}
}



template<typename I,typename V>
typename colecInterdep<I,V>::Nodo*& buscar(typename colecInterdep<I,V>::Nodo*& buscado, const I& id) {
    if(buscado == nullptr){
		return buscado;
	}
	else{
		if(id < buscado->ident){
			return buscar<I,V>(buscado->izq, id);
		}
		else if(buscado->ident == id){
			return buscado;
		}
		else{
			return buscar<I,V>(buscado->der, id);
		}
	} 
}

/*Dado un nodo pasado por referencia c,un identificador id pasado por entrada,un valor v pasado por entrada 
*y un booleano anyadido pasado por referencia.Procede a crear un nuevo nodo añadiendo como información el identificador id,
*el valor v y asignando al booleano anyadido el valor true si se ha creado el nodo,tras recorrer toda la colección 
*comprobando la inexistencia previa de un nodo con identificador id.
*/

template<typename I,typename V>
void anyadirIndependienteRec(typename colecInterdep<I,V>::Nodo* &c, const I& id, const V& v, bool &anyadido){
	if(c==nullptr){	//1er caso: es vacia
		c = new typename colecInterdep<I,V>:: Nodo;
		c -> ident = id;
		c -> valor = v;
		c -> dep = nullptr;
		c -> numDepend = 0;
		c -> izq = nullptr;
		c -> der = nullptr;
		anyadido=true;
	}
	else{
		if(id < c->ident){
			anyadirIndependienteRec<I,V>(c->izq, id, v, anyadido);
		}
		else if(c->ident < id){
			anyadirIndependienteRec<I,V>(c->der, id, v, anyadido);
		}
		else if(id == c->ident){
			//Nada
		}
	}
}



/*Dado dos nodos pasados por referencia c y pSup,un identificador id pasado por entrada,un valor v pasado por entrada 
*y un booleano anyadido pasado por referencia.Procede a crear un nuevo nodo añadiendo como información el identificador id,
*el valor v , el nodo pSup como su superior y asignando al booleano anyadido el valor true si se ha creado el nodo,tras 
*recorrer toda la colección comprobando la inexistencia previa de un nodo con identificador id.Previamente confirmada 
*la existencia de pSup.
*/
template<typename I,typename V>
void anyadirDependienteRec(typename colecInterdep<I,V>::Nodo* &c, const I& id, const V& v, typename colecInterdep<I,V>::Nodo* pSup, bool &anyadido){
	if(c==nullptr){	//1er caso: es vacia
		c = new typename colecInterdep<I,V>:: Nodo;
		c -> ident = id;
		c -> valor = v;
		c -> dep = pSup;
		c -> numDepend = 0;
		c -> izq = nullptr;
		c -> der = nullptr;
		anyadido=true;

		pSup -> numDepend = pSup -> numDepend+1;
	}
	else{
		if(id < c->ident){
			anyadirDependienteRec<I,V>(c->izq, id, v, pSup, anyadido);
		}
		else if(c->ident < id){
			anyadirDependienteRec<I,V>(c->der, id, v, pSup, anyadido);
		}
		else if(id == c->ident){
			//Nada
		}
	}
}


/* Si no se encuentra un elemento con el identificador id en la colección c devuelve el resultante de añadir el elemento 
 * independiente (id,v,-,0) a la colección c. En caso de que exista un elemento con tal identificador devuelve una
 * igual a c sin modificar.
*/
template<typename I,typename V>
void anyadirIndependiente(colecInterdep<I,V>& c, const I& id, const V& v){
	bool anyadido = false;
	anyadirIndependienteRec<I,V>(c.raiz, id, v, anyadido);
	if(anyadido){
		c.tam++;
	}
}



/* Si no se encuentra un elemento con identificador id en la colección y existe un elemento con identificador super 
 * devuelve el resultante de añadir el elemento dependiente (id,v,super,0) a la colección c e incrementar en 1 el 
 * número de elementos dependientes del elemento con identificador super. En caso de que exista un elemento con tal 
 * identificador o no exista un elemento con identificador super devuelve una colección igual a c sin modificar.
*/
template<typename I,typename V>
void anyadirDependiente(colecInterdep<I,V>& c, const I& id, const V& v, const I& super){
	if(!esVacia(c)){	//Como tiene que tener super la colección tiene que tener algún elemento
		typename colecInterdep<I,V>:: Nodo* pSup = buscar<I,V>(c.raiz,super);
		if(pSup!=nullptr){	//Si es nullptr es poque tiene punto de insercion, sino se debe a que ya existe
			bool anyadido = false;
			anyadirDependienteRec<I,V>(c.raiz, id, v, pSup,anyadido);
			if(anyadido){
				c.tam++;
			}
		}
	}	
}



/* Si existe un elemento con identificador id en la colección c y existe un elemento con identificador super incrementa
 * en 1 el el número de elementos dependientes del elemento con identificador super y hace dependiente al elemento
 * con identificador id del de super (apuntando con dep a super). En caso de que el elemento con identificador id dependiese 
 * de otro elemento previamente, decrementa en 1 el numero de elementos dependientes de dicho elemento del que dependia. Si no 
 * existe un elemento con el identificador id en la colección o no existe un elemento con identificador super devuelve una colección
 * igual a c sin modificar.
*/
template<typename I,typename V>
void hacerDependiente(colecInterdep<I,V>& c, const I& id, const I& super){
	if(!esVacia(c)){
		if( !(id==super)){
			typename colecInterdep<I,V>:: Nodo* pAux1 = buscar<I,V>(c.raiz,id);
			typename colecInterdep<I,V>:: Nodo* pAux2= buscar<I,V>(c.raiz,super);
			if(pAux1 != nullptr){	//que existe
				if(pAux2!=nullptr){	//que existe
					if(pAux1->dep!=nullptr){
						pAux1->dep->numDepend--;
					}
					pAux1->dep=pAux2;
					pAux2->numDepend++;
				}
			}
		}
	}
}



/* Si existe un elemento con identificador id en la colección c y este es dependiente de otro elemento decrementa 
 * en 1 el número de elementos dependientes del elemento del que dependía y hacer independiente el elemento con identificador 
 * id (haciendo que su puntero a dep sea igual a nullptr). Si no existe un elemento con el identificador id en la colección 
 * o este ya era un elemento con independiente super devuelve una colección igual a c sin modificar.
*/
template<typename I,typename V>
void hacerIndependiente(colecInterdep<I,V>& c, const I& id){
	if(!esVacia(c)){
		typename colecInterdep<I,V>:: Nodo* pAux1 = buscar<I,V>(c.raiz,id);
		if(pAux1!=nullptr){ //que existe
			if(pAux1->dep!=nullptr){
				pAux1->dep->numDepend--;
				pAux1->dep=nullptr;
			}
		}
	}
}





/* Si existe un elemento con el identificador id en la colección c actualiza el valor del puntero que apunta a valor valor
 * por el de nuevo y devuelve en forma de booleano TRUE si y solo si se ha actualizado correctamente. Devuelve FALSE si no 
 * se ha podido actualizar por la inexistencia del elemento.
*/
template<typename I,typename V>
bool actualizarVal(colecInterdep<I,V>& c, const I& id, const V& nuevo){
	typename colecInterdep<I,V>:: Nodo* pAux = buscar<I,V>(c.raiz, id);
	if(pAux!=nullptr){	//existe
		pAux -> valor = nuevo;
		return true;
	}
	else{
		return false;
	}
}


/* Si existe un elemento con identificador id en la colección c le proporciona a val el valor v del elemento y devuelve 
 * en forma de booleano TRUE si y solo si el valor val se ha actualizado correctamente con el valor del puntero del elemento
 * que apunta a valor. Devuelve FALSE si no se ha podido actualizar por la inexistencia del elemento en la colección.
*/
template<typename I,typename V>
bool obtenerVal(const I& id, colecInterdep<I,V>& c, V& val){	
	typename colecInterdep<I,V>:: Nodo* pAux = buscar<I,V>(c.raiz, id);
	if(pAux!=nullptr){	//existe
		val = pAux -> valor;
		return true;
	}
	else{
		return false;
	}
}


/* Si existe un elemento con identificador id en la colección le proporciona a sup el identificador del elemento del 
 * que depende el elemento con identidicador id, obtenido con el puntero que apunta a dep->ident y devuelve en forma de 
 * booleano TRUE si y solo si el identificador sup se ha actualizado correctamente. Devuelve FALSE si no se ha podido 
 * actualizar por la inexistencia del elemento.
*/
template<typename I,typename V>
bool obtenerSupervisor(const I& id, colecInterdep<I,V>& c, I& sup){
	typename colecInterdep<I,V>:: Nodo* pAux = buscar<I,V>(c.raiz, id);
	if(pAux!=nullptr){	//existe
		if(pAux -> dep != nullptr){
			sup = pAux -> dep -> ident;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}


/* Si existe un elemento con identificador id en la colección c devuelve en forma de entero el numero de elementos que 
 * dependen del elemento obtenido con el puntero que apunta a numDepend. Devuelve -1 si existe tal elemento en la coleccion c.
*/
template<typename I,typename V>
int obtenerNumDependientes(const I& id, colecInterdep<I,V>& c){
	typename colecInterdep<I,V>:: Nodo* pAux = buscar<I,V>(c.raiz, id);
	if(pAux!=nullptr){	//existe
		return pAux -> numDepend;
	}
	else{
		return -1;
	}	
}


/* Si existe un elemento con identificador id en la colección le proporciona a val el valor v del elemento (obtenido con 
 * el puntero que apunta a valor) y a numDep el número de elementos que dependen de este (obtenido con el puntero que 
 * apunta a numDepend). Si el elemento es dependiente de otro le proporciona a sup el identificador del elemento del que
 * depende (obtenido con el puntero que apunta a dep->ident) y le asigna al booleano depende TRUE. Si este elemento es 
 * independiente sup no se modifica y le asigna al booleano depende FALSE.
 * La función devuelve en forma de booleano TRUE si y solo si se ha encontrado el elemento y, por tanto, se ha podido obtener 
 * estos datos. Devuelve FALSE en caso contrario.
*/
template<typename I,typename V> 
bool obtenerDatos(const I& id, colecInterdep<I,V>& c, V& val, I& sup, int& numDep, bool& depende){
	typename colecInterdep<I,V>:: Nodo* pAux = buscar<I,V>(c.raiz, id);
	if(pAux!=nullptr){	//existe
		val = pAux -> valor;
		numDep = pAux -> numDepend;
		if(pAux -> dep != nullptr){
			sup = pAux->dep ->ident;
			depende = true;
		}
		else{
			depende = false;
		}
		return true;
	}
	else{
		return false;
	}
}




/*Dado dos nodos pasados por referencia pBuscado y pMax.Procede a llegar al último hijo derecho,copiando el nodo en pMax y 
 *modificando pBuscado como hijo izquierdo del nodo actual, y dejando al hijo izquierdo en nullptr.Devolviendo pMax como el 
 *máximo nodo. 
*/
template<typename I,typename V>
void desengancharMaximo(typename colecInterdep<I,V>::Nodo* &pBuscado, typename colecInterdep<I,V>::Nodo* &pMax){
	if(pBuscado->der==nullptr){//Es el último hijo derecho
		pMax=pBuscado; //Copia en pMax el nodo actual
		pBuscado=pBuscado->izq;//Pone a pBuscado como el hijo izquierdo
		pMax->izq=nullptr;
	}else{
		desengancharMaximo<I,V>(pBuscado->der,pMax);//Llamada recursiva para llegar al ultimo hijo
	}
}


/* Dado un identificador pasado por entrada id y una colección pasada por referencia c.Si existe un elemento con el identificador id en la colección c y no tiene elementos dependientes (numDepend es 0) 
 * devuelve la colección resultante de eliminar el elemento de la colección c. Si este elemento es dependiente además 
 * decrementa en 1 el numero de elementos dependientes del que este dependía. Si este elemento se elimina se libera su
 * información en memoria mediante tras haber reestructurado correctamente la colección.
 * Si el elemento no existe devuelve la misma colección c sin modificar.
*/
template<typename I ,typename V>
void borrar(const I& id, colecInterdep<I,V>& c){
	if(!esVacia(c)){
		typename colecInterdep<I,V>:: Nodo*& pBuscado = buscar<I,V>(c.raiz, id);
	if(pBuscado!=nullptr){	//existe
			if(pBuscado->numDepend == 0){//No depende nadie de él
				if(pBuscado->dep != nullptr){
					pBuscado->dep->numDepend--;
				}

				typename colecInterdep<I,V>::Nodo* pAux =pBuscado ;

				if(pBuscado->izq == nullptr && pBuscado -> der == nullptr){//Caso hoja o Nodo Raíz
					pBuscado = nullptr;
				}

				else if(pBuscado->izq == nullptr){//Caso no hay hijo izquierdo
					pBuscado = pBuscado->der;
				}

				else if(pBuscado->der == nullptr){//Caso no hay hijo derecho
					pBuscado = pBuscado->izq;
				}

				else{//Caso hay ambos hijos
					typename colecInterdep<I,V>::Nodo* pMax;

					
					desengancharMaximo<I,V>(pAux->izq,pMax);//Procedo a buscar el maximo de su hijo izquierdo

					pMax->izq=pAux->izq;
					pMax->der=pAux->der;
					pBuscado=pMax;
					
				}
				delete pAux;
				c.tam--;

			}

		}

	}

}



//ITERADOR
/* Las ocho operaciones siguientes conforman un iterador interno para la colección: 
 * Este iterador permitirá visitar los elementos almacenados en la colección empezando por la raiz elemento (el
 * de menor identificador) y acabando con el último elemento (el de mayor identificador).
 * Si el puntero itr de la colección tiene valor nullptr entonces no existe elemento pendiente por visitar (ya se 
 * han visitado todos los elementos), en caso contrario el puntero apunta a la Nodo cuyo dato es el siguiente 
 * elemento a visitar.
*/





/* Inicia el iterador para que el siguiente elemento a visitar sea la raiz elemento de la colección c, si existe.
*/
template<typename I,typename V>
void iniciarIterador(colecInterdep<I,V> &c){
	typename colecInterdep<I,V>::Nodo* pAux = c.raiz;
	liberar(c.itr);
	while(pAux!=nullptr){
		apilar(c.itr, pAux);
		pAux = pAux->izq;
	}
}

/* Devuelve en forma de booleano TRUE si y solo si queda algún elemento por visitar en la colección c y FALSE en caso 
 * contrario.
*/
template<typename I,typename V>
bool existeSiguiente(colecInterdep<I,V>& c){
	return !esVacia(c.itr);
}


/* Si queda algún elemento por visitar en la colección modifica id con el identificador del elemento visitado y devuelve
 * TRUE en forma de booleano. En caso contrario devuelve FALSE. 
*/
template<typename I,typename V>
bool siguienteIdent(colecInterdep<I,V>& c, I& id){
	if(existeSiguiente(c)){
		bool error;
		typename colecInterdep<I,V>::Nodo* pAux = nullptr;
		cima(c.itr, pAux, error);
		if(!error){
			id = pAux -> ident;
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}	
}


/* Si queda algún elemento por visitar en la colección c modifica val con el valor del elemento visitado y devuelve 
 * TRUE en forma de booleano. En caso contrario devuelve FALSE. 
*/
template<typename I,typename V>
bool siguienteVal(colecInterdep<I,V>& c, V& val){
	if(existeSiguiente(c)){
		bool error;
		typename colecInterdep<I,V>::Nodo* pAux = nullptr;
		cima(c.itr, pAux, error);
		if(!error){
			val = pAux -> valor;
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	} 
}


/* Devuelve en forma de booleano TRUE si y solo si queda algún elemento por visitar en la colección c y dicho elemento
 * es dependiente de otro. Devuelve FALSE si no se cumplen ambas condiciones.
*/
template<typename I,typename V>
bool siguienteDependiente(colecInterdep<I,V>& c){
	if(existeSiguiente(c)){
		bool error;
		typename colecInterdep<I,V>::Nodo* pAux = nullptr;
		cima(c.itr, pAux, error);
		if(!error){
			return pAux -> dep != nullptr;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}	
}


/* Si queda algún elemento dependiente por visitar en la colección c modifica sup con el identificador del elemento del 
 * que depende el elemento visitado y devuelve TRUE en forma de booleano. En caso de que no queden elemetos por visitar
 * o que este sea independiente devuelve FALSE. 
*/
template<typename I,typename V>
bool siguienteSuperior(colecInterdep<I,V>& c, I& sup){
	if(siguienteDependiente(c)){
		bool error;
		typename colecInterdep<I,V>::Nodo* pAux = nullptr;
		cima(c.itr, pAux, error);
		if(!error){
			sup = pAux->dep->ident;
			return true;
		}
		else{
			return false;
		}
	} 
	else{
		return false;
	}
}


/* Si queda algún elemento por visitar en la colección c devuelve el numero de elementos dependientes del elemento visitado
 * en forma de entero. Devuelve -1 si no se quedan elementos por visitar.
*/
template<typename I,typename V>
int siguienteNumDependientes(colecInterdep<I,V>& c){
	if(existeSiguiente(c)){
		bool error;
		typename colecInterdep<I,V>::Nodo* pAux = nullptr;
		cima(c.itr, pAux, error);
		if(!error){
			return pAux -> numDepend;
		}
		else{
			return -1;
		}
	}
	else{
		return -1;
	} 
}


/* Devuelve en forma de booleano TRUE si existen elementos por visitar en la colección c y hace que el iterador avance para
 * visitar el siguiente elemento de la colección. Devuelve FALSE en caso contrario y no avanza.
*/
template<typename I,typename V>
bool avanza(colecInterdep<I,V>& c){
	if(existeSiguiente(c)){
		bool error;
		typename colecInterdep<I,V>::Nodo* pAux = nullptr;
		cima(c.itr, pAux, error);
		desapilar(c.itr);
		if(pAux -> der != nullptr){
			pAux = pAux -> der;

			while(pAux!=nullptr){
				apilar(c.itr, pAux);
				pAux = pAux->izq;
			}
		}

		return true;
	}
	else{
		return false;
	}
}




#endif
