#include "Comandos.h"
#include <iostream>
#include <string.h>
#include <cstring>
#include <bits/stdc++.h>

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
		
		if(apu != NULL)
			cout<<endl<<"nombre archivo : "<<apu;
		else
			cout<<"no se encuentra o no puede leerse";
		
	}
	else if(c2==0){
		apu=strtok(NULL," ");

		if(apu != NULL)
			cout<<endl<<"nombre archivo : "<<apu<<endl;
		else
			cout<<"el archivo no se encuentra o no puede leerse";
		
	}	
	else if(c3==0){

		apu=strtok(NULL," ");
		if(apu != NULL){
			cout<<endl<<"tipo movimiento : "<<apu;
			apu = strtok(NULL, " ");

			if(apu != NULL){
				cout<<endl<<"magnitud : "<<apu;
				apu=strtok(NULL," ");

				if(apu != NULL){
					cout<<endl<<"unidad medida : "<<apu;
				}else{cout<<"la informacion del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad)."<<endl;}

			}else{cout<<"la informacion del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad)."<<endl;}
			
			
		}else{cout<<"la informacion del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad)."<<endl;}
	}
	else if(c4==0){
		apu=strtok(NULL," ");
		if(apu != NULL){
			cout <<endl<<"tipo comp: "<<apu<<endl;
			apu = strtok(NULL," ");
			if(apu != NULL){
				cout<<endl<<"tamaño : "<<apu;
				apu=strtok(NULL," ");
				if(apu != NULL){
					cout<<endl<<"unidad med: "<<apu;
					apu=strtok(NULL," ");
					if(apu != NULL){
						cout<<endl<<"coordx : "<<apu;
						apu=strtok(NULL," ");
						if(apu != NULL){
							cout<<endl<<"corrdy : "<<apu;
						}else{cout<<"(Formato erroneo) La informacion del elemento no corresponde a los datos esperados (tipo, tamaño, unidad, x, y)."<<endl;}

					}else{cout<<"(Formato erroneo) La informacion del elemento no corresponde a los datos esperados (tipo, tamaño, unidad, x, y)."<<endl;}

				}else{cout<<"(Formato erroneo) La informacion del elemento no corresponde a los datos esperados (tipo, tamaño, unidad, x, y)."<<endl;}

			}else{cout<<"(Formato erroneo) La informacion del elemento no corresponde a los datos esperados (tipo, tamaño, unidad, x, y)."<<endl;}

		}else{cout<<"(Formato erroneo) La informacion del elemento no corresponde a los datos esperados (tipo, tamaño, unidad, x, y)."<<endl;}
		
	}
	else if(c5==0){
		apu=strtok(NULL," ");
		if(apu != NULL){
			cout<<endl<<"tipo archivo : "<<apu;
			apu=strtok(NULL," ");
			if(apu != NULL){
				cout<<endl<<"nombre archivo : "<<apu;
			}else{cout<<"(No hay informacion) La informacion requerida no esta almacenada en memoria."<<endl;}

		}else{cout<<"(No hay informacion) La informacion requerida no esta almacenada en memoria."<<endl;}
		
		
	}
	else if(c6==0){
		apu=strtok(NULL," ");
		if(apu != NULL){
			cout<<endl<<"coord x : "<<apu;
			apu=strtok(NULL," ");
			if(apu != NULL){
				cout<<endl<<"coordy : "<<apu;
			}else{cout<<"(error de formato) las coordenadas ingresadas no son validas."<<endl;}

		}else{cout<<"(error de formato) las coordenadas ingresadas no son validas."<<endl;}
		
	}
	else if(c7==0){
		flag = false;
	}
	else if(c8==0){
		cout<<"se ubican los elementos"<<endl;
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
			apu=strtok(NULL," ");
			if(apu != NULL){
				cout<<endl<<"objeto : "<<apu<<endl;
				apu=strtok(NULL," ");
				if(apu != NULL){
					cout<<endl<<"comentario : "<<apu<<endl;

				}else{cout<<"(Formato erroneo) La informacion del analisis no corresponde a los datos esperados (tipo, objeto, comentario)."<<endl;}
				
			}else{cout<<"(Formato erroneo) La informacion del analisis no corresponde a los datos esperados (tipo, objeto, comentario)."<<endl;}

		}else{cout<<"(Formato erroneo) La informacion del analisis no corresponde a los datos esperados (tipo, objeto, comentario)."<<endl;}
		
	}
	else if(c13 == 0){

		cout<<"--- COMANDOS DE AYUDA ---"<<endl;
		apu=strtok(NULL," ");
		if(apu != NULL){
			if(apu == "cargar_comandos"){
				cout<<"Carga en memoria los comandos de desplazamiento contenidos en el archivo identificado por nombre_archivo"<<endl;

			}else if(*apu == c2){
				cout<<"Carga en memoria los datos de puntos de interés o elementos contenidos en el archivo identificado por nombre_archivo"<<endl;

			}else if(*apu == c3){
				cout<<"Agrega el comando de movimiento descrito a la lista de comandos del robot “Curios-ity”. El movimiento puede ser de dos tipos: avanzar o girar."<<endl;

			}else if(*apu == c4){
				cout<<"Agrega el componente o elemento descrito a la lista de puntos de interés del robot “Curiosity”. El tipo de componente puede ser uno entre roca, crater, monticulo o duna. El tamaño es un valor real que da cuenta de qué tan grande es el elemento"<<endl;

			}else if(*apu == c5){
				cout<<"Guarda en el archivo nombre_archivo la información solicitada de acuerdo al tipo de archivo: comandos almacena en el archivo la información de comandos de movimiento y de análisis que debe ejecutar el robot, elementos almacena en el archivo la información de los componentes o puntos de interés conocidos en el suelo marciano. "<<endl;

			}else if(*apu == c6){
				cout<<"Permite simular el resultado de los comandos de movimiento que se enviarán al robot 'Curiosity' desde la Tierra, facilitando asi la validación de la nueva posición en la que podría ubicarse."<<endl;

			}else if(*apu == c7){
				cout<<"comando para salir del programa"<<endl;

			}else if(*apu == c8){
				cout<<"El comando debe utilizar la información de puntos de interés almacenada en memoria para ubicarlos en una estructura de datos jerárquica adecuada, que permita luego realizar consultas geográficas sobre estos elementos."<<endl;

			}else if(*apu == c9){
				cout<<"Permite utilizar la estructura creada con el comando cargar_elementos para retornar una lista de los componentes o elementos que están dentro del cuadrante geográfico descrito por los límites de coordenadas en x y y."<<endl;

			}else if(*apu == c10){
				cout<<"El comando debe utilizar la información de puntos de interés almacenada en memoria para ubicarlos en una estructura no lineal y conectarlos entre sí teniendo en cuenta el coeficiente de conectividad dado."<<endl;

			}else if(*apu == c11){
				cout<<"Con el mapa ya creado, el comando permite identificar los dos componentes más alejados entre sí de acuerdo a las conexiones generadas. Es importante aclarar que el comando retorna los elementos más alejados de acuerdo a las conexiones que se encuentran en el mapa, no los elementos que estén a mayor distancia euclidiana entre sí."<<endl;

			}else if(*apu == c12){
				cout<<"Agrega el comando de análisis descrito a la lista de comandos del robot “Curiosity”. El análisis puede ser de tres tipos: fotografiar, composicion o perforar. El objeto es el nombre del elemento que se quiere analizar (roca, arena, monticulo, ...)."<<endl;

			}else if (*apu == c13){
				cout<<"comando para obtener ayudar e informacion sobre los otros comandos del aplicativo"<<endl;

			}else{cout<<"el comando del que solicita ayouda no existe"<<endl;}


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