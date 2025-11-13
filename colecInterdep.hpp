/* Mijayl Mandzyak Melnyk 935521 Hector Manzano Miranda 926092*/
#ifndef COLECINTEDEP_HPP
#define COLECINTEDEP_HPP
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


/* Devuelve en forma de booleano TRUE si y solo si en la colección c hay un elemento con identificcador id que sea 
 * dependiente de otro elemento. Devuelve FALSE en caso de no encontrar dicho elemento o que este no sea dependiente.
*/
template<typename I,typename V> bool existeDependiente(const I& id, colecInterdep<I,V>& c);


/* Devuelve en forma de booleano TRUE si y solo si en la colección c hay un elemento con el identificador id que 
 * no sea dependiente de otro elemento. Devuelve FALSE en caso de no encontrar dicho elemento o que este sea dependiente.
*/
template<typename I,typename V> bool existeIndependiente(const I& id, colecInterdep<I,V>& c);


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


/* Inicia el iterador para que el siguiente elemento a visitar sea el.raizer elemento de la colección c, si existe.
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



// DECLARACION DEL TAD GENERICO colecInterdep

template<typename I,typename V>
struct colecInterdep{
	friend void crear<I,V>(colecInterdep<I,V>& c);
	friend int tamanyo<I,V>(colecInterdep<I,V>& c);
	friend bool esVacia<I,V>(colecInterdep<I,V>& c);
	friend bool existe<I,V>(const I& id, colecInterdep<I,V>& c);
	friend bool existeDependiente<I,V>(const I& id, colecInterdep<I,V>& c);
	friend bool existeIndependiente<I,V>(const I& id, colecInterdep<I,V>& c);
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

	friend void iniciarIterador<I,V>(colecInterdep<I,V>& c);
	friend bool existeSiguiente<I,V>(colecInterdep<I,V>& c);
	friend bool siguienteIdent<I,V>(colecInterdep<I,V>& c, I& id);
	friend bool siguienteVal<I,V>(colecInterdep<I,V>& c, V& val);
	friend bool siguienteDependiente<I,V>(colecInterdep<I,V>& c);
	friend bool siguienteSuperior<I,V>(colecInterdep<I,V>& c, I& sup);
	friend int siguienteNumDependientes<I,V>(colecInterdep<I,V>& c);
	friend bool avanza<I,V>(colecInterdep<I,V>& c);

    

  private: /* En esta implementación la colección se representará en memoria dinámica como una lista enlazada de Arbols ordenada 
  			* por el identificdor de los elementos de menor a mayor con: 
	        * - el puntero.raiz: apuntando a la Arbol que contiene el.raizer elemento de la colección, será nullptr si la colección
			* está vacía
		    * - el campo tam: mantendrá calculado el tamaño o número de elementos en la colección, será 0 si la pila está vacía 
		    * - el puntero itr: se utilizará para mantener el estado del iterador, y únicamente será utilizado por las operaciones 
			* iniciarIterador, existeSiguiente, siguienteIdent, siguienteVal, siguienteDependiente, siguienteSuperior, siguienteNumDependientes
			* y avanza.
			* Cada Arbol contendrá un identificador (en su campo ident), un valor (en su campo valor), apuntará con su puntero dep 
			* al elemento del que es dependiente o a nullptr si es independiente, un entero que almacenará el número de elementos 
			* que dependen de este y apuntará con su puntero sig a la próxima Arbol que contenga el.raizer elemento con un identificador
			* mayor a este o a nullptr si este es el elemento con mayor identificador.
	   
    Todas las funciones de la colcección tienen coste lineal O(n) salvo crear, tamanyo y esVacia que tienen coste
	constante. Todas las funciones del iterador tienen coste constante.
	Igualmente, el coste en memoria de esta implementación será O(N).
	*/
	struct Arbol{
	I ident;
	V valor;
	Arbol* dep;
	int numDepend;
	Arbol* izq;
	Arbol* der;

};


	Arbol* raiz;
	int tam;
    //CAMPOS ITERADOR
	Arbol* itr;
};
	


//OPERACIONES

/* Devuelve el número de elementos que hay en una colección c en forma de entero.
*/
template<typename I,typename V> 
void crear(colecInterdep<I,V>& c){
	c.tam=0;
	c.raiz=nullptr;
	c.itr=nullptr;

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
	return esta(id,c.raiz);
}


template<typename I,typename V>
bool esta(const I& id, Arbol*& c){
	if(c == nullptr){
		return false;
	}
	else{
		if(id < c->ident){
			return esta(id,c->izq);
		}
		else if(c->ident == id){
			return true;
		}
		else if(c->ident < id){
			return esta(id,c->der);
		}
	}
}



/* Devuelve en forma de booleano TRUE si y solo si en la colección c hay un elemento con identificcador id que sea 
 * dependiente de otro elemento, es decir que el puntero dep del elemento no apunte a nullptr. Devuelve FALSE en caso
 * de no encontrar dicho elemento o que este no sea dependiente.
*/
template<typename I,typename V>
bool existeDependiente(const I& id, colecInterdep<I,V>& c){
	return estaDependiente(id,c.raiz);
}

template<typename I,typename V>
bool estaDependiente(const I& id, Arbol* c){
	if(c == nullptr){
		return false;
	}
	else{
		if(id < c->ident){
			return estaDependiente(id,c->izq);
		}
		else if(c->ident == id){
			if(c->dep != nullptr){
				return true;
			}
			else{
				return false;
			}
		}
		else if(c->ident < id){
			return estaDependiente(id,c->der);
		}
	}
}




/* Devuelve en forma de booleano TRUE si y solo si en la colección c hay un elemento con el identificador id que no
 * sea dependiente de otro elemento, es decir que el puntero dep del elemento apunte a nullptr. Devuelve FALSE en caso 
 * de no encontrar dicho elemento o que este sea dependiente.
*/
template<typename I,typename V>
bool existeIndependiente(const I& id, colecInterdep<I,V>& c){
	return estaIndependiente(id,c.raiz);
}


template<typename I,typename V>
bool estaIndependiente(const I& id, Arbol* c){
	if(c == nullptr){
		return false;
	}
	else{
		if(id < c->ident){
			return estaIndependiente(id,c->izq);
		}
		else if(c->ident == id){
			if(c->dep == nullptr){
				return true;
			}
			else{
				return false;
			}
		}
		else if(c->ident < id){
			return estaIndependiente(id,c->der);
		}
	}
}


template<typename I,typename V>
bool encontrar(Arbol* c, const I& id, Arbol*& pBuscado){
	if(c == nullptr){
		return false;
	}
	else{
		if(id < c->ident){
			return encontrar(c->izq, id, pBuscado);
		}
		else if(c->ident == id){
			pBuscado = c;
			return true;
		}
		else if(c->ident < id){
			return encontrar(c->der, id, pBuscado);
		}
	}
}


template<typename I,typename V>
bool buscar(colecInterdep<I,V>& c, const I& id, Arbol*& pBuscado) {
    return encontrar(c.raiz, id, pBuscado); 
}








template<typename I,typename V>
void anyadirIndependiente(Arbol*& c, const I& id, const V& v, bool &anyadido){
	if(c==nullptr){	//1er caso: es vacia
		c = new typename colecInterdep<I,V>::Arbol;
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
			anyadirIndependiente(c->izq, id, v, anyadido);
		}
		else if(c->ident < id){
			anyadirIndependiente(c->der, id, v, anyadido);
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
	anyadirIndependiente(c.raiz, id, v, anyadido);
	if(anyadido){
		c.tam++;
	}
}





template<typename I,typename V>
void anyadirDependiente(Arbol*& c, const I& id, const V& v, Arbol* pSup, bool &anyadido){
	if(c==nullptr){	//1er caso: es vacia
		c = new typename colecInterdep<I,V>::Arbol;
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
			anyadirDependiente(c->izq, id, v, pSup, anyadido);
		}
		else if(c->ident < id){
			anyadirDependiente(c->der, id, v, pSup, anyadido);
		}
		else if(id == c->ident){
			//Nada
		}
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
		typename colecInterdep<I,V>::Arbol* pSup = c.raiz;
		if(buscar(c,super,pSup)){
			bool anyadido = false;
			anyadirDependiente(c.raiz, id, v, pSup,anyadido);
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

	if( id!=super){
		typename colecInterdep<I,V>::Arbol* pAux = c.raiz;
		typename colecInterdep<I,V>::Arbol* pSuper = nullptr;
		typename colecInterdep<I,V>::Arbol* pId = nullptr;
		bool encontradoS = false; //Indica si se encuentra super
		bool encontradoId = false; //Indica si se encuentra id
   		while ( (!encontradoS || !encontradoId) || (pAux != nullptr) ) { //Para cuando se hayan encontrado ambos o se llegue al final de la colección
			if(pAux->ident == id ){
				encontradoId=true;
				pId = pAux;
			}
			else if(pAux->ident == super){
				encontradoS=true;
				pSuper = pAux;
			}
			pAux = pAux->sig;
			
			
		}
	
		if(encontradoS && encontradoId){	//Si ambos se encuentran hace al elemento con id, dependiente de sup
			pSuper->numDepend++;
			if(pId->dep != nullptr){
				pId->dep->numDepend--;
			}
			pId->dep = pSuper;

		
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
	typename colecInterdep<I,V>::Arbol* pId = c.raiz;
	// Recorremos mientras no se acabe la colección y el identificador actual sea menor que el buscado
   	while (pId != nullptr && pId ->ident < id ){
 		pId = pId->sig;
	}
	if(pId != nullptr && pId->ident == id){ //Si encuentra el elemento
		if(pId->dep!=nullptr){	//Si el elemento dependia de otro, si no no hay que hacer nada
			pId->dep->numDepend--;
			pId->dep=nullptr;
		}
	}
}





/* Si existe un elemento con el identificador id en la colección c actualiza el valor del puntero que apunta a valor valor
 * por el de nuevo y devuelve en forma de booleano TRUE si y solo si se ha actualizado correctamente. Devuelve FALSE si no 
 * se ha podido actualizar por la inexistencia del elemento.
*/
template<typename I,typename V>
bool actualizarVal(colecInterdep<I,V>& c, const I& id, const V& nuevo){
	typename colecInterdep<I,V>::Arbol* pAux = c.raiz;
	// Recorremos mientras no se acabe la colección y el identificador actual sea menor que el buscado
	while(pAux!=nullptr && pAux -> ident < id){
		pAux = pAux -> sig;
	}
	if(pAux!=nullptr && pAux -> ident == id){ // Si lo encuentra cambia valor
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
	typename colecInterdep<I,V>::Arbol* pAux = c.raiz;
	// Recorremos mientras no se acabe la colección y el identificador actual sea menor que el buscado
	while(pAux!=nullptr && pAux -> ident < id){
		pAux = pAux -> sig;
	}
	if(pAux!=nullptr && pAux -> ident == id){ //Si lo encuentra obtiene valor
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
	typename colecInterdep<I,V>::Arbol* pAux = c.raiz;
	// Recorremos mientras no se acabe la colección y el identificador actual sea menor que el buscado
	while(pAux!=nullptr && pAux -> ident < id){
		pAux = pAux -> sig;
	}
	if(pAux!=nullptr && pAux -> ident == id){ //Si existe el elemento
		if(pAux ->dep != nullptr){	//Si es dependiente
			sup = pAux ->dep->ident;
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


/* Si existe un elemento con identificador id en la colección c devuelve en forma de entero el numero de elementos que 
 * dependen del elemento obtenido con el puntero que apunta a numDepend. Devuelve -1 si existe tal elemento en la coleccion c.
*/
template<typename I,typename V>
int obtenerNumDependientes(const I& id, colecInterdep<I,V>& c){
	typename colecInterdep<I,V>::Arbol* pAux = c.raiz;
	while(pAux!=nullptr && pAux -> ident < id){
		pAux = pAux -> sig;
	}	
	if(pAux!=nullptr && pAux -> ident == id){
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
template<typename I,typename V> bool obtenerDatos(const I& id, colecInterdep<I,V>& c, V& val, I& sup, int& numDep, bool& depende){
	typename colecInterdep<I,V>::Arbol* pAux = c.raiz;
	while(pAux!=nullptr && pAux -> ident < id){
		pAux = pAux -> sig;
	}
	if(pAux!=nullptr && pAux -> ident == id){
		val = pAux -> valor;
		numDep = pAux -> numDepend;

		if(pAux ->dep != nullptr){
			sup = pAux ->dep->ident;
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



template<typename I,typename V>
bool borrar2(Arbol* c, const I& id, Arbol*& pBuscado,Arbol*& pPadre){
	if(c == nullptr){
		return false;
	}
	else{
		if(id < c->ident){
			pPadre=c;
			return borrar2(c->izq, id, pBuscado,pPadre);
		}
		else if(c->ident == id){
			pBuscado = c;
			return true;
		}
		else if(c->ident < id){
			pPadre=c;
			return borrar2(c->der, id, pBuscado,pPadre);
		}
	}
}

template<typename I,typename V>
void desengancharMaximo(Arbol* pBuscado,Arbol* pMax,Arbol*pPadreMax){
	if(pBuscado->der==nullptr){
		pMax==pBuscado;
		pBuscado=pBuscado->izq;
		pMax->izq=nullptr;
	}else{
		pPadreMax=pBuscado->der->izq;
		desengancharMaximo(pBuscado->der,pMax,pPadreMax);
	}
}


/* Si existe un elemento con el identificador id en la colección c y no tiene elementos dependientes (numDepend es 0) 
 * devuelve la colección resultante de eliminar el elemento de la colección c. Si este elemento es dependiente además 
 * decrementa en 1 el numero de elementos dependientes del que este dependía. Si este elemento se elimina se libera su
 * información en memoria mediante tras haber reestructurado correctamente la colección.
 * Si el elemento no existe devuelve la misma colección c sin modificar.
*/
template<typename I ,typename V>
void borrar(const I& id, colecInterdep<I,V>& c){
	if(!esVacia){
		typename colecInterdep<I,V>::Arbol* pBuscado = c.raiz;
		typename colecInterdep<I,V>::Arbol* pPadre;
		if(borrar2(c,id,pBuscado,pPadre)){
			if(pBuscado->numDepend == 0){
				if(pBuscado->dep != nullptr){
					pBuscado->dep->numDepend--;
				}

				if(pBuscado->izq == nullptr && pBuscado -> der == nullptr){
					if(pPadre->der->ident == id ){
						pPadre->der = nullptr;
					}else if(pPadre->izq->ident == id){
						pPadre->izq = nullptr;
					}
					delete pBuscado;
					c.tam--;
				}

				else if(pBuscado->izq == nullptr){
					typename colecInterdep<I,V>::Arbol* pAux =pBuscado ;
					if(pPadre->der->ident == id ){
						pPadre->der = pBuscado->der;
					}else if(pPadre->izq->ident == id){
						pPadre->izq = pBuscado->der;
					}
					pBuscado=pBuscado->der;
					delete pAux;
					c.tam--;
				}

				else if(pBuscado->der == nullptr){
					typename colecInterdep<I,V>::Arbol* pAux =pBuscado ;
					if(pPadre->der->ident == id ){
						pPadre->der = pBuscado->izq;
					}else if(pPadre->izq->ident == id){
						pPadre->izq = pBuscado->izq;
					}
					pBuscado=pBuscado->izq;
					delete pAux;
					c.tam--;
				}

				else{
					typename colecInterdep<I,V>::Arbol* pMax;
					typename colecInterdep<I,V>::Arbol* pPadreMax;
					typename colecInterdep<I,V>::Arbol* pAux=pBuscado;
					desengancharMaximo(pBuscado->izq,pMax,pPadreMax);

					pMax->izq=pBuscado->izq;
					pMax->der=pBuscado->der;
					pBuscado=pMax;
					delete pAux;
					c.tam--;
				}

			}

		}

	}

}



//ITERADOR
/* Las ocho operaciones siguientes conforman un iterador interno para la colección: 
 * Este iterador permitirá visitar los elementos almacenados en la colección empezando por el.raizer elemento (el
 * de menor identificador) y acabando con el último elemento (el de mayor identificador).
 * Si el puntero itr de la colección tiene valor nullptr entonces no existe elemento pendiente por visitar (ya se 
 * han visitado todos los elementos), en caso contrario el puntero apunta a la Arbol cuyo dato es el siguiente 
 * elemento a visitar.
*/


/* Inicia el iterador para que el siguiente elemento a visitar sea el.raizer elemento de la colección c, si existe.
*/
template<typename I,typename V>
void iniciarIterador(colecInterdep<I,V>& c){
	c.itr = c.raiz;
}

/* Devuelve en forma de booleano TRUE si y solo si queda algún elemento por visitar en la colección c y FALSE en caso 
 * contrario.
*/
template<typename I,typename V>
bool existeSiguiente(colecInterdep<I,V>& c){
	return c.itr != nullptr;
}


/* Si queda algún elemento por visitar en la colección modifica id con el identificador del elemento visitado y devuelve
 * TRUE en forma de booleano. En caso contrario devuelve FALSE. 
*/
template<typename I,typename V>
bool siguienteIdent(colecInterdep<I,V>& c, I& id){
	if(existeSiguiente(c)){
		id = c.itr -> ident;
		return true;
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
		val = c.itr -> valor;
		return true;
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
		return c.itr -> dep != nullptr;
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
		sup = c.itr -> dep -> ident;
		return true;
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
		return c.itr -> numDepend;
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
		c.itr = c.itr -> sig;
		return true;
	}
	else{
		return false;
	}
}




#endif
