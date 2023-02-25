#include "Torre_de_control.h"
#include "CAnalisis.h"
#include "CMovimientos.h"
#include "Coordenadas.h"
#include "Elementos.h"
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

bool Torre_de_control::addCmdAnalisis(CAnalisis comando){

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

    queue<CMovimientos> aux;
    aux = this -> comnds_mov;
    cout << "COMANDOS DE MOVIMIENTO EN MEMORIA:" <<endl;

    while( !aux.empty( ) ) {
      
      CMovimientos n = aux.front( );

      aux.pop( );

      cout << "tipo: " << n.getTipo() << endl;
      cout <<"magnitud: "<<n.getMagnitud() <<endl;
      cout <<"unidad de medida: " <<n.getUnidadM()<<endl;
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

      char *dup = strdup(linea.c_str());
      Elementos elm;

      elm.setTipo(strtok(dup, " "));
      float sz = atof((strtok(NULL, " ")));
      elm.setSize(sz);
      elm.setUnidadm(strtok(NULL, " "));
      float x = atof((strtok(NULL, " ")));
      float y = atof((strtok(NULL, " ")));

      elm.addCoords(x,y);

      this ->elmnts.push_back(elm);

    }

    for(int i=0; i < this->elmnts.size(); i++){
      
      cout<< "tipo: " << this->elmnts[i].getTipo()<<endl;
      cout<<"size: " << this->elmnts[i].getSize()<<endl;
      cout <<"unidad de medida: "<<this->elmnts[i].getUnidadm()<<endl; 
      cout <<"coordenada en x: " << this->elmnts[i].getCoordx()<<endl;
      cout <<"coordenada en y: " << this->elmnts[i].getCoordy()<<endl;

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
		// Abrimos el archivoo
		archivo.open(nombreArchivo.c_str(), fstream::out);
		 if (!archivo.is_open()){
           cout <<"Error al abrir "<<filename;
           return false;
          }
         while(!name.empty()){
         	temp=name.front();
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
