#include "Torre_de_control.h"
#include "CAnalisis.h"
#include "CMovimientos.h"
#include "Coordenadas.h"
#include <queue>
#include <iostream>

using namespace std;

Torre_de_control::Torre_de_control(){

    
}

bool Torre_de_control::addCmdMovimiento(CMovimientos comando, string tipo_mov , float mag , string unidad){
    if (tipo_mov == "avanzar" || tipo_mov =="girar" ) {
	    comando.setTipo(tipo_mov);
	    else
		    return false; 
	    }
	if (typeof(mag) == float) {
		comando.setMagnitud(mag); 
		else 
			return false; 
	}
        if (typeof(unidad) == string) {
		comando.setunidadM(unidad); 
		else 
			return false; 
			    std::queue< CMovimientos > Movs;
			    Movs.push
		    }}}
			    return true;

}

bool Torre_de_control::addCmdAnalisis(CAnalisis comando){

    return true;

}

void Torre_de_control::leerArchivoMovimiento(string filename){
  string nombreArchivo = filename;
    string linea;
    ifstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open())
  {
    cout <<"Error al abrir "<<filename;
    return;
  }
   if(sizeof(archivo)==0){
          	cout <<"Archivo"<<filename<<"vacio\n";
		  }
   
    while (getline(archivo, linea)) {
        cout << "Comando : "<< linea << endl;;
    }
    
}

void Torre_de_control::leerArchivoElementos(string filename){

  string nombreArchivo = filename;
    string linea;
    ifstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open())
  {
    cout <<"Error al abrir "<<filename;
    return;
  }
   if(sizeof(archivo)==0){
          	cout <<"Archivo"<<filename<<"vacio\n";
		  }
   
    while (getline(archivo, linea)) {
        cout << "Comando : "<< linea << endl;;
    }
    
    

}

bool Torre_de_control::guardarArchivoMovimiento(string filename,queue<string> name){
string nombreArchivo = filename;
    string temp;
    ofstream archivo;
		archivo.open(nombreArchivo.c_str(), fstream::out);
		 if (!archivo.is_open()){
             cout <<filename<<"no se encuentra o no puede leerse";
             return false;
         }
		 while(!name.empty()){
		 	temp=name.top();
         	archivo <<temp<<endl;
         	name.pop();
		 }
		archivo.close();
    return true;

}

bool Torre_de_control::guardarArchivoElementos(string filename,queue<string> name){

   string nombreArchivo = filename;
    string temp;
    ofstream archivo;
		// Abrimos el archivo
		archivo.open(nombreArchivo.c_str(), fstream::out);
		 if (!archivo.is_open()){
           cout <<"Error al abrir "<<filename;
           return false;
          }
         while(!name.empty()){
         	temp=name.top();
         	archivo <<temp <<endl;
         	name.pop();
		 }
		archivo.close();
  		  return true;

}

void Torre_de_control::simularComandosMov(float coord_x, float coord_y; std::queue< Coordenadas > aux;){
Coordenadas c; 
	c.setCoord_x(coord_x);
        c.setCoord_y(coord_y);
        
}

void Torre_de_control::simularComandosAnalisis(string filename){

}
