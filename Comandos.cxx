#include "Comandos.h"
#include <iostream>
#include <string.h>
#include <cstring>
#include <bits/stdc++.h>
#include "CAnalisis.h"

using namespace std;
 
Comandos::Comandos(){

	this -> nombre = "";
}

bool Comandos::encontrarC(){

	char *dup = strdup(this->getNombre().c_str());

	bool flag=true;
	char *apu;
	int c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13;
	apu = strtok(dup," ");
	//se dividio el string en varios con division por espacios
	c1=strcmp("cargar_comandos",(apu));
	c2=strcmp("cargar_elementos",(apu));
	c3=strcmp("agregar_movimiento",(apu));
	c12 =strcmp("agregar_analisis",(apu));
	c4=strcmp("agregar_elemento",(apu));
	c5=strcmp("guardar",(apu));
	c6=strcmp("simular_comandos",(apu));
	c7=strcmp("salir",(apu));
	c8=strcmp("ubicar_elementos",(apu));
	c9=strcmp("en_cuadrante",(apu));
	c10=strcmp("crear_mapa",(apu));
	c11=strcmp("ruta_mas_larga",(apu));
	c13=strcmp("ayuda",(apu));
	//se comparo con cada comando y se guardo en las variables enteras
	
	if(c1==0){
		
		apu = strtok(NULL," ");
		
		if(apu != NULL){

			this -> tc.leerArchivoComandos(apu);
			cout << endl << "comandos contenidos en el archivo cargados en la memoria" <<endl;

		}else{cout<<"no se encuentra o no puede leerse";}
			
		
	}
	else if(c2==0){
		apu=strtok(NULL," ");

		if(apu != NULL){

			this ->tc.leerArchivoElementos(apu);
			cout << endl <<"elementos del archivo cargados en la memoria "<<endl;

		}else{cout<<"el archivo no se encuentra o no puede leerse";}
			
		
	}	
	else if(c3==0){

		CMovimientos cm;

		apu=strtok(NULL," ");
		if(apu != NULL){
			cout<<endl<<"tipo movimiento : "<<apu;
			string tipo = apu;
			apu = strtok(NULL, " ");

			if(apu != NULL){
				cout<<endl<<"magnitud : "<<apu;
				float magn = atof(apu);
				apu=strtok(NULL," ");

				if(apu != NULL){
					cout<<endl<<"unidad medida : "<<apu;
					string um = apu;

					this->tc.addCmdMovimiento(tipo,magn,um);
					cout << endl << "comando de movimiento agregado correctamente a memoria" <<endl;

				}else{cout<<"la informacion del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad)."<<endl;}

			}else{cout<<"la informacion del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad)."<<endl;}
			
			
		}else{cout<<"la informacion del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad)."<<endl;}
	}
	else if(c4==0){
		apu=strtok(NULL," ");
		if(apu != NULL){
			string tipo = apu;
			apu = strtok(NULL," ");
			if(apu != NULL){
				cout<<endl<<"size: "<<apu;
				float sz = atof(apu);
				apu=strtok(NULL," ");
				if(apu != NULL){
					cout<<endl<<"unidad med: "<<apu;
					string um = apu;
					apu=strtok(NULL," ");
					if(apu != NULL){
						cout<<endl<<"coordenada x: "<<apu;
						float x = atof(apu);
						apu=strtok(NULL," ");
						if(apu != NULL){
							cout<<endl<<"coordenada y: "<<apu<<endl;
							float y= atof(apu);

							this->tc.addCmdElemento(tipo,sz,um,x,y);
							cout<<"elemento agregado a la memoria"<<endl;


						}else{cout<<"(Formato erroneo) La informacion del elemento no corresponde a los datos esperados (tipo, tamaño, unidad, x, y)."<<endl;}

					}else{cout<<"(Formato erroneo) La informacion del elemento no corresponde a los datos esperados (tipo, tamaño, unidad, x, y)."<<endl;}

				}else{cout<<"(Formato erroneo) La informacion del elemento no corresponde a los datos esperados (tipo, tamaño, unidad, x, y)."<<endl;}

			}else{cout<<"(Formato erroneo) La informacion del elemento no corresponde a los datos esperados (tipo, tamaño, unidad, x, y)."<<endl;}

		}else{cout<<"(Formato erroneo) La informacion del elemento no corresponde a los datos esperados (tipo, tamaño, unidad, x, y)."<<endl;}
		
	}
	else if(c5==0){
		apu=strtok(NULL," ");
		if(apu != NULL){

			if((strcmp("comandos",(apu)))==0){

				apu=strtok(NULL," ");
				if(apu != NULL){

					tc.guardarArchivoComandos(apu);
					cout <<endl<<"comandos guardados en el archivo exitosamente"<<endl;
				
				}else{cout<<"(No hay informacion) La informacion requerida no esta almacenada en memoria."<<endl;}

			}
			else if((strcmp("elementos",(apu)))==0){

				apu=strtok(NULL," ");
				if(apu != NULL){

					tc.guardarArchivoElementos(apu);
					cout<<endl<<"Elementos guardados en el archivo exitosamente"<<endl;

				}else{cout<<""<<endl;}

			
			}else{cout <<"el tipo de archivo ingresado no es valido " <<endl;}

		}else{cout<<"(No hay informacion) La informacion requerida no esta almacenada en memoria."<<endl;}
		
		
	}

	else if(c6==0){
		apu=strtok(NULL," ");
		if(apu != NULL){
			cout<<endl<<"coordenada x: "<<apu;
			float x = atof(apu);
			apu=strtok(NULL," ");
			float y = atof(apu);
			if(apu != NULL){
				cout<<endl<<"coordenada y: "<<apu<<endl;
				this->tc.simularComandosMov(x,y);
			}else{cout<<"(error de formato) las coordenadas ingresadas no son validas."<<endl;}

		}else{cout<<"(error de formato) las coordenadas ingresadas no son validas."<<endl;}
		
	}
	else if(c7==0){
		flag = false;
	}
	else if(c8==0){
		
		this->tc.ubicarElementos();
	}
	else if(c9==0){
		apu=strtok(NULL," ");
		if(apu != NULL){
			cout<<endl<<"coord x1 : "<<apu;
			apu=strtok(NULL," ");
			if(apu != NULL){
				cout<<endl<<"coord x2 : "<<apu;
				apu=strtok(NULL," ");
				if(apu != NULL){
					cout<<endl<<"coord y1 : "<<apu;
					apu=strtok(NULL," ");
					if(apu != NULL){
						cout<<endl<<"coord y2: "<<apu;
					}else{cout<<"(Formato erroneo) La informacion del cuadrante no corresponde a los datos esperados (x_min, x_max, y_min, y_max)."<<endl;}

				}else{cout<<"(Formato erroneo) La informacion del cuadrante no corresponde a los datos esperados (x_min, x_max, y_min, y_max)."<<endl;}

			} else{cout<<"(Formato erroneo) La informacion del cuadrante no corresponde a los datos esperados (x_min, x_max, y_min, y_max)."<<endl;}

		}
		
	}
	else if(c10==0){
		apu=strtok(NULL," ");
		if(apu != NULL){
			cout<<endl<<"coeficiente conectividad: "<<apu<<endl;
		}else{cout<<"formato de ingreso invalido."<<endl;}
		
	}
	else if(c11==0){
		cout<<"la ruta mas larga es: *aqui pondriamos la ruta mas larga*"<<endl;
	}
	else if(c12==0){

		apu=strtok(NULL," ");
		if(apu != NULL){
			cout<<endl<<"tipo analisis : "<<apu<<endl;
			string ta = apu;
			apu=strtok(NULL," ");
			if(apu != NULL){
				cout<<endl<<"objeto : "<<apu<<endl;
				string obj = apu;
				apu=strtok(NULL," ");
				string cm = apu;
				this ->tc.addCmdAnalisis(ta,obj,cm);
				cout << "comando de analisis agregado correctamente a memoria"<<endl;
				
			}else{cout<<"(Formato erroneo) La informacion del analisis no corresponde a los datos esperados (tipo, objeto, comentario)."<<endl;}

		}else{cout<<"(Formato erroneo) La informacion del analisis no corresponde a los datos esperados (tipo, objeto, comentario)."<<endl;}
		
	}
	else if(c13 == 0){

		cout<<endl;
		apu=strtok(NULL," ");
		if(apu != NULL){
			if(strcmp("cargar_comandos",(apu))==0){
				cout<<"Carga en memoria los comandos de desplazamiento contenidos en el archivo identificado por nombre_archivo"<<endl;

			}else if(strcmp("cargar_elementos",(apu))==0){
				cout<<"Carga en memoria los datos de puntos de interes o elementos contenidos en el archivo identificado por nombre_archivo"<<endl;

			}else if(strcmp("agregar_movimiento",(apu))==0){
				cout<<"Agrega el comando de movimiento descrito a la lista de comandos del robot 'Curiosity'. El movimiento puede ser de dos tipos: avanzar o girar."<<endl;

			}else if(strcmp("agregar_elemento",(apu))==0){
				cout<<"Agrega el componente o elemento descrito a la lista de puntos de interes del robot 'Curiosity'. El tipo de componente puede ser uno entre roca, crater, monticulo o duna. El tamanio es un valor real que da cuenta de que tan grande es el elemento"<<endl;

			}else if(strcmp("guardar",(apu))==0){
				cout<<"Guarda en el archivo nombre_archivo la informacion solicitada de acuerdo al tipo de archivo: comandos almacena en el archivo la informacion de comandos de movimiento y de analisis que debe ejecutar el robot, elementos almacena en el archivo la informacion de los componentes o puntos de interes conocidos en el suelo marciano. "<<endl;

			}else if(strcmp("simular_comandos",(apu))==0){
				cout<<"Permite simular el resultado de los comandos de movimiento que se enviaran al robot 'Curiosity' desde la Tierra, facilitando asi la validacion de la nueva posicion en la que podria ubicarse."<<endl;

			}else if(strcmp("salir",(apu))==0){
				cout<<"comando para salir del programa"<<endl;

			}else if(strcmp("ubicar_elementos",(apu))==0){
				cout<<"El comando debe utilizar la informacion de puntos de interes almacenada en memoria para ubicarlos en una estructura de datos jerarquica adecuada, que permita luego realizar consultas geograficas sobre estos elementos."<<endl;

			}else if(strcmp("en_cuadrante",(apu))==0){
				cout<<"Permite utilizar la estructura creada con el comando cargar_elementos para retornar una lista de los componentes o elementos que estan dentro del cuadrante geografico descrito por los limites de coordenadas en x y y."<<endl;

			}else if(strcmp("crear_mapa",(apu))==0){
				cout<<"El comando debe utilizar la informacion de puntos de interes almacenada en memoria para ubicarlos en una estructura no lineal y conectarlos entre si teniendo en cuenta el coeficiente de conectividad dado."<<endl;

			}else if(strcmp("ruta_mas_larga",(apu))==0){
				cout<<"Con el mapa ya creado, el comando permite identificar los dos componentes mas alejados entre si de acuerdo a las conexiones generadas. Es importante aclarar que el comando retorna los elementos mas alejados de acuerdo a las conexiones que se encuentran en el mapa, no los elementos que esten a mayor distancia euclidiana entre si."<<endl;

			}else if(strcmp("agregar_analisis",(apu))==0){
				cout<<"Agrega el comando de analisis descrito a la lista de comandos del robot “Curiosity”. El analisis puede ser de tres tipos: fotografiar, composicion o perforar. El objeto es el nombre del elemento que se quiere analizar (roca, arena, monticulo, ...)."<<endl;

			}else if (strcmp("ayuda",(apu))==0){
				cout<<"comando para obtener ayudar e informacion sobre los otros comandos del aplicativo"<<endl;

			}else{cout<<"el comando del que solicita ayuda no existe"<<endl;}


		}else{cout<<"no existe ningun comando que acompanie al comando ayuda"<<endl;}
		
		
	}
	else{
		cout << "comando no encontrado." <<endl; 
	}
	
	return flag;
}

void Comandos::setNombre(string nombre){
    this -> nombre = nombre;
}

string Comandos::getNombre(){
    return nombre;
}