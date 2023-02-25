#include "Torre_de_control.h"
#include "CAnalisis.h"
#include "CMovimientos.h"
#include "Coordenadas.h"
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

Torre_de_control::Torre_de_control(){

    
}

void Torre_de_control::addCmdMovimiento(CMovimientos comando){
    
    this -> comnds_mov.push(comando);

}

bool Torre_de_control::addCmdAnalisis(CAnalisis comando, string tipo, string objeto, string comentario){
	if( tipo =="fotografiar" || tipo=="composicion" || tipo=="perforar"){
		comando.setTipo(tipo);
	}
	else 
		return false; 
	if (typeof(objeto) == string ){
		comando.setObjeto(objeto);
	}
	else 
		return false; 
	if(typof (comentario) == string){
		comando.setComentario(comentario); 
	} 
	else 
		return false; 
	
	std:: queue< CAnalisis> Analis;
	Analis.push(comando); 
	
	return true; 
}

void Torre_de_control::leerArchivoMovimiento(string filename){

  CMovimientos cm;
  string nombreArchivo = filename;
  string linea;
  ifstream archivo(nombreArchivo.c_str());
  
  if (!archivo.is_open()){
    cout <<"Error al abrir "<<filename;
    return;
  }

  if(sizeof(archivo)==0){
          	cout <<"Archivo"<<filename<<"vacio\n";
		  }
   
    while (getline(archivo, linea)) {

      char *dup = strdup(linea.c_str());

        CMovimientos cm;
        cm.setTipo(strtok(dup, " "));
        float mag = atof(strtok(NULL, " "));
        cm.setMagnitud(mag);
        cm.setUnidadM(strtok(NULL, " "));

        this ->addCmdMovimiento(cm);
    
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

void Torre_de_control::guardarArchivoMovimiento(string filename){
    
    string nombreArchivo = filename;
    string temp;
    ofstream archivo;
		archivo.open(nombreArchivo.c_str(), fstream::out);
		  
      if (!archivo.is_open()){
          
          cout <<filename<<"no se encuentra o no puede leerse";

      }

      /*
		 while(!name.empty()){
		 	    
          temp=name.front();
         	archivo <<temp<<endl;
         	name.pop();
		 }
     */
      while(!this ->comnds_mov.empty()){
        
        temp = this->comnds_mov.front().getTipo();
        archivo << temp <<" ";
        temp = this->comnds_mov.front().getMagnitud();
        archivo << temp <<" ";
        temp = this->comnds_mov.front().getUnidadM();
        archivo << temp <<endl;

        this->comnds_mov.pop();
        
      }

		archivo.close();

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

void Torre_de_control::simularComandosMov(string filename ){
    
    cout << "aaa" <<endl;
    
    
        
}

void Torre_de_control::simularComandosAnalisis(string filename){

}
