/* Mijayl Mandzyak Melnyk 935521 Hector Manzano Miranda 926029*/
#include "colecInterdep.hpp"
#include "tarea.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/*
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
				cambiarDescripcion(v,info);
				cambiarPrioridad(v,prioridad);
				
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
				bool esDep;
				if(existeDepOIndep(ident,colec,esDep)){
					if(esDep){
						s <<"DEPendiente: ";
					}else{
						s <<"INDEPendiente: ";
					}
				}else{
					s <<"DESCONOCIDO: ";

				} 
				s <<ident<<endl;
			
			}else if(instruccion =="I"){//HACE INDEPENDIENTE A ESE IDENT
				getline(f,ident);
				bool esDep;
			
				if(existeDepOIndep(ident,colec,esDep)){
					if(!esDep){
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

}*/


void instruccion(const string inst, colecInterdep<string,tarea>colec){
	string ident, name, desc, uni;
	double esti, emple;
	int tam;
	tarea t;
	while(inst!="FIN")
		if(inst=="A"){	//anyadir t
			cout << "Identificador de la tarea: ";
			cin >> ident;
			cout << "Nombre de la tarea: ";
			cin >> name;
			cout << "Descripción de la tarea: ";
			cin >> desc;
			cout << "Unidad de tiempo de la tarea: ";
			cin >> uni;
			cout << "Tiempo estimado de la tarea";
			cin >>esti;
			crearTarea(name, desc, uni,esti,t);
			tam = tamanyo(colec);
			anyadirIndependiente(colec,ident,t);
			if(tam==tamanyo(colec)){
				cout << "NO INTRODUCIDA, YA EXISTE UNA TAREA CON ESE IDENTIFICADOR";
			}
			cout << "INTRODUCIDA\n";
		}
		else if(inst=="D"){	//hacer dep
			string ident2;
			cout << "Identificador de la tarea 1: ";
			cin >> ident;
			cout << "Identificador de la tarea 2: ";
			cin >> ident2;
			if(existe(ident,colec) && existe(ident2,colec)){	
				hacerDependiente(colec,ident,ident2);
				cout <<"INTENTANDO hacer depend.\n";	
			}else{
				cout <<"IMPOSIBLE hacer depend.\n";
			}

		}
		else if(inst=="I"){	//hacer ind
			cout << "Identificador de la tarea: ";
			cin >> ident;
			bool esDep;
			if(existeDepOIndep(ident,colec,esDep)){
				if(!esDep){
					cout <<"YA ERA INDepend.: ";
				}else{
					hacerIndependiente(colec,ident);
					cout <<"INDEPENDIZADO: ";
				}
			}else{
					cout <<"NO INDEPENDIZADO: ";
			} 
		}
		else if(inst=="C"){	//cambiar info t
			cout << "Identificador de la tarea: ";
			cin >> ident;
			char cambio;
			if(existe(ident,colec)){
				cout << "Nuevo tiempo estimado: ";
				cin >> esti;
				cout << "Nuevo tiempo empleado: ";
				cin >> emple;
				if(cambiarTiempoEstimado(t, esti) && cambiarTiempoEmpleado(t,emple)){
					actualizarVal(colec, ident, t);
				}
				else{
					cout << "NO SE HAN PODIDO MODIFICAR LOS TIEMPOS";
				}
				cout << "SI QUIERE CAMBIAR EL NOMBRE TECLEE 'Y' (pulsar cualquier otra tecla si no)";
				cin>>cambio;
				if(cambio=='Y'){
					cout << "Escriba el nuevo nombre: ";
					cin >> name;
					
				}
				cout << "SI QUIERE CAMBIAR LA DESCRIPCIÓN TECLEE 'Y' (pulsar cualquier otra tecla si no)";
				cin>>cambio;
				if(cambio=='Y'){
					cout << "Escriba la nueva descripción: ";
					cin >> desc;
					
				}
				cout << "SI QUIERE CAMBIAR LA UNIDAD DE TIEMPO TECLEE 'Y' (pulsar cualquier otra tecla si no)";
				cin>>cambio;
				if(cambio=='Y'){
					cout << "Escriba la nueva unidad de tiempo: ";
					cin >> uni;
					
				}
				
			}
			else{
				cout << "NO EXISTE TAREA CON ESE IDENTIFICADOR\n";
			}
		}
		else if(inst=="LD"){//info tarea
			cout <<"Identificador de la tarea: ";
			cin >> ident;
			int numDepends;
			bool depende;
			string super;
			if(obtenerDatos(ident,colec,t,super,numDepends,depende)){
				name=nombre(t);
				desc=descripcion(t);
				uni=unidad(t);
				esti=estimacion(t);
				emple=invertido(t);

				if(depende==true){				
					cout <<"[ "<<ident<<" -de-> "<<super<<" ;;; "<<numDepends<<" ] --- "<<name<<" --- ( "<<desc<<" )"<<" --- ( "<<uni<<" )"<<" --- ( "<<emple<<" )"<<endl;
				}else{
					cout <<"[ "<<ident<<" --- "<<numDepends<<" ]--- "<<name<<" --- ( "<<desc<<" )"<<" --- ( "<<uni<<" )"<<" --- ( "<<emple<<" )"<<endl;		
				}
				iniciarIterador(colec);
				int puesto= 1;
				string iddep;

				while(existeSiguiente(colec)){ // Si eso modificar con puesto menor cuando vaya LD porque si no hay dependientes de ident recorre de todas maneras la colec
					
					if(siguienteSuperior(colec,super)){
							
							if(super == ident){
								siguienteIdent(colec,iddep);
								siguienteVal(colec,t);
								name=nombre(t);
								desc=descripcion(t);
								uni=unidad(t);
								esti=estimacion(t);
								emple=invertido(t);
								numDepends=siguienteNumDependientes(colec);
								cout <<"["<<puesto<<" -> "<<iddep<<" -de-> "<<ident<<" ;;; "<<numDepends<<" ]--- "<<name<<" --- ( "<<desc<<" )"<<" --- ( "<<uni<<" )"<<" --- ( "<<emple<<" )"<<endl;
								puesto++;
							}
							

					}
					avanza(colec);

				}
				cout <<"****FINAL dependientes -de-> "<<ident<<endl;
			}else{
				cout <<"****DESCONOCIDO"<<endl;
			}
		}
		else if(inst=="B"){	//borrar
			cout<<"Identificador de la tarea: \n";
			cin>>ident;
			
			int tam=tamanyo(colec);
			borrar(ident,colec);
			if(tam != tamanyo(colec)){
				cout <<"BORRADO: ";
			}
			else{
				cout <<"NO BORRADO: ";
			} 
			cout <<ident<<endl;
		}
		else if(inst=="LT"){//listar colección
			cout <<"-----LISTADO: "<<tamanyo(colec)<<endl;
				
				if(tamanyo(colec)>0){
					iniciarIterador(colec);
					
					while(existeSiguiente(colec)){ // Si eso modificar con puesto menor cuando vaya LD porque si no hay dependientes de ident recorre de todas maneras la colec
						
						int numDepends;
						bool depende;
						string super;
						if(obtenerDatos(ident,colec,t,super,numDepends,depende)){
							name= nombre(t);
							desc=descripcion(t);
							uni=unidad(t);
							esti=estimacion(t);
							emple=invertido(t);

						if(depende==true){
									
							cout <<"[ "<<ident<<" -de-> "<<super<<" ;;; "<<numDepends<<" ] --- "<<name<<" --- ( "<<desc<<" )"<<" --- ( "<<uni<<" )"<<" --- ( "<<emple<<" )"<<endl;

						}else{
							cout <<"[ "<<ident<<" --- "<<numDepends<<" ]--- "<<name<<" --- ( "<<desc<<" )"<<" --- ( "<<uni<<" )"<<" --- ( "<<emple<<" )"<<endl;		
						}
						avanza(colec);

					}
				}
				cout <<"-----"<<endl;
			}
		}
		else{
			cout << "Instrucción no reconocida\n";
			cout << "A: añadir nueva tarea\nD: Hacer que tarea1 pasa a ser prerrequisito directo de tarea2\n"
				<< "I: Hacer que tarea no sea prerrequisito de nadie\nC: Cambiar informacion de una tarea\n"
				<< "LD: Mostrar información de una tarea y de todas las que son prerrequisito de esta\n"
				<< "B: Borrar tarea\n LT: Mostrar colección\n";
		}
		cin >> inst;
}


int main(){
	colecInterdep<string,tarea> bolsa;
	crear(bolsa);
	string instruccion;
	cout << "A: añadir nueva tarea\nD: Hacer que tarea1 pasa a ser prerrequisito directo de tarea2\n"
				<< "I: Hacer que tarea no sea prerrequisito de nadie\nC: Cambiar informacion de una tarea\n"
				<< "LD: Mostrar información de una tarea y de todas las que son prerrequisito de esta\n"
				<< "B: Borrar tarea\n LT: Mostrar colección\n";
	cin >> instruccion;
}
