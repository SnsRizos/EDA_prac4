/* Mijayl Mandzyak Melnyk 935521 Hector Manzano Miranda 926092*/
#include "colecInterdep.hpp"
#include "evento.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


void leerInstrucciones(colecInterdep<string,evento>colec){
	ifstream f;
	f.open("entrada.txt");

	if(f.is_open()){
		ofstream s;
			s.open("salida.txt");
			if(s.is_open()){
			evento v;
			string instruccion,salto;
			string ident;
			string info;
			int    prioridad;
			string dependencia;
			string super;
			int numDepends;
			bool depende;
				
			while(f >> instruccion){
			getline(f,salto);
			
			if(instruccion == "A"){//AÑADE UN NUEVO ID A LA MEMORIA

				getline(f,ident);
				getline(f,info);
				f >> prioridad; 
				getline(f,salto);
				f >> dependencia;
				getline(f,salto);
				getline(f,super);
				crearEvento(info,prioridad,v);
				int tam = tamanyo(colec);
				if(dependencia == "DEPendiente"){ 
					anyadirDependiente(colec,ident,v,super); 
				}else if(dependencia =="INDependiente"){
					anyadirIndependiente(colec,ident,v);
				}
				
				if(tam!=tamanyo(colec)){
					s <<"INTRODUCIDO: ";
				}else{
					s <<"NO INTRODUCIDO: ";
				}
				if(dependencia == "INDependiente"){
					s <<"[ "<<ident<<" ] --- "<<info<<" --- ( "<<prioridad<<" )"<<endl;
				}else if(dependencia =="DEPendiente"){
					s <<"[ "<<ident<<" -de-> "<<super<<" ] --- "<<info<<" --- ( "<<prioridad<<" )"<<endl;
				}
						
				
			}else if( instruccion == "C"){ // CAMBIA EL VALOR DEL ID QUE NOS DA 
				getline(f,ident);
				getline(f,info);
				f >> prioridad;
				getline(f,salto);
				crearEvento(info,prioridad,v);
				
					if(actualizarVal(colec,ident,v)){
						s <<"CAMBIADO: ";
						obtenerDatos(ident,colec,v,super,numDepends,depende);
						if(!depende){
							s <<"[ "<<ident<<" --- "<<numDepends<<" ] --- "<<info<<" --- ( "<<prioridad<<" )"<<endl;

						}else{
							s <<"[ "<<ident<<" -de-> "<<super<<" ;;; "<<	numDepends<<" ] --- "<<info<<" --- ( "<<prioridad<<" )"<<endl;

						}
					}else{
						s <<"NO CAMBIADO: "<< ident<<endl;
					}
			}else if( instruccion == "O"){//MUESTRA TODA LA INFORMACION  DE ESE ID
				getline(f,ident);
				
				if(obtenerDatos(ident,colec,v,super,numDepends,depende)){
					s <<"LOCALIZADO: ";
					info=descripcion(v);
					prioridad=suPrioridad(v);
					if(!depende){
						s <<"[ "<<ident<<" --- "<<numDepends<<" ] --- "<<info<<" --- ( "<<prioridad<<" )"<<endl;

					}else{
						s <<"[ "<<ident<<" -de-> "<<super<<" ;;; "<<numDepends<<" ] --- "<<info<<" --- ( "<<prioridad<<" )"<<endl;
					}
				}else{
					s <<"NO LOCALIZADO: "<<ident<<endl;

				}
			}else if(instruccion == "E"){//BUSCA SI EXISTE ESE IDENT
				getline(f,ident);

				if(existe(ident,colec)){
					if(existeIndependiente(ident,colec)){
						s <<"INDEPendiente: ";
					}else{
						s <<"DEPendiente: ";
					}
				}else{
					s <<"DESCONOCIDO: ";

				} 
				s <<ident<<endl;
			
			}else if(instruccion =="I"){//HACE INDEPENDIENTE A ESE IDENT
				getline(f,ident);
			
				if(existe(ident,colec)){
					if(existeIndependiente(ident,colec)){
						s <<"YA ERA INDepend.: ";
					}else{
						hacerIndependiente(colec,ident);
						s <<"INDEPENDIZADO: ";
					}
				}else{
						s <<"NO INDEPENDIZADO: ";

				} 
				s <<ident<<endl;
			}else if(instruccion == "D"){//HACE DEPENDIENTE AL IDENT DE SUPER
				getline(f,ident);
				getline(f,super);
				
				if(existe(ident,colec) && existe(super,colec)){
						
					hacerDependiente(colec,ident,super);
					s <<"INTENTANDO hacer depend.: ";
						
				}else{
					s <<"IMPOSIBLE hacer depend.: ";

				} 
				s <<ident<<" -de-> "<<super<<endl;
			}else if (instruccion == "B"){//BORRA DE LA COLECCION EL ID
				getline(f,ident);

					int tam=tamanyo(colec);
					borrar(ident,colec);
					if(tam != tamanyo(colec)){
						s <<"BORRADO: ";
					}
					else{
						s <<"NO BORRADO: ";
					} 
					s <<ident<<endl;	
			}else if ( instruccion == "LD"){//RECORRER TODA LA colec CON EL ITERADOR Y CUANDO UNO DEPENDA DEL SUPER QUE NOS DEN IMPRIMIR SUS DATOS
				getline(f,ident);
				s <<"****DEPENDIENTES: "<<ident<<endl;
				if(obtenerDatos(ident,colec,v,super,numDepends,depende)){
					info=descripcion(v);
					prioridad=suPrioridad(v);
					

					if(!depende){
						s <<"[ "<<ident<<" --- "<<numDepends<<" ] --- "<<info<<" --- ( "<<prioridad<<" ) ****"<<endl;
					}else{
						s <<"[ "<<ident<<" -de-> "<<super<<" ;;; "<<numDepends<<" ] --- "<<info<<" --- ( "<<prioridad<<" ) ****"<<endl;
					}
					iniciarIterador(colec);
					int puesto= 1;
					string iddep;

					while(existeSiguiente(colec)){ // Si eso modificar con puesto menor cuando vaya LD porque si no hay dependientes de ident recorre de todas maneras la colec
						
						if(siguienteSuperior(colec,super)){
							
								if(super == ident){
									siguienteIdent(colec,iddep);
									siguienteVal(colec,v);
									info=descripcion(v);
									prioridad=suPrioridad(v);
									numDepends=siguienteNumDependientes(colec);
									s <<"["<<puesto<<" -> "<<iddep<<" -de-> "<<ident<<" ;;; "<<numDepends<<" ] --- "<<info<<" --- ( "<<prioridad<<" ) ;;;;"<<endl;
									puesto++;
								}
								

						}
						avanza(colec);

					}
					s <<"****FINAL dependientes -de-> "<<ident<<endl;
				}else{
					s <<"****DESCONOCIDO"<<endl;
				}
				
			}else if( instruccion == "LT"){//RECORRER TODO LA colec MOSTRANDO TODOS LOS DATOS DE TODA LA colec
				s <<"-----LISTADO: "<<tamanyo(colec)<<endl;
				
				if(tamanyo(colec)>0){
					iniciarIterador(colec);
					
					while(existeSiguiente(colec)){ // Si eso modificar con puesto menor cuando vaya LD porque si no hay dependientes de ident recorre de todas maneras la colec
						siguienteIdent(colec,ident);
						siguienteVal(colec,v);
						info=descripcion(v);
						prioridad=suPrioridad(v);
						numDepends=siguienteNumDependientes(colec);

						if(siguienteSuperior(colec,super)){
									
							s <<"[ "<<ident<<" -de-> "<<super<<" ;;; "<<numDepends<<" ] --- "<<info<<" --- ( "<<prioridad<<" )"<<endl;

						}else{
							s <<"[ "<<ident<<" --- "<<numDepends<<" ] --- "<<info<<" --- ( "<<prioridad<<" )"<<endl;		
						}
						avanza(colec);

					}
				}
				s <<"-----"<<endl;
			}

		}
		s.close();
	}else{
			cerr << "No ha podido escribirse el fichero \"" << "salida.txt" << "\"." << endl;
		}
		f.close();
	}else{
			cerr << "No ha podido leer el fichero \"" << "entrada.txt" << "\"." <<endl;
	}

}



int main(){
	colecInterdep<string,evento> bolsa;
	crear(bolsa);
	leerInstrucciones(bolsa);
}
