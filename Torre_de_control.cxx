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

void Torre_de_control::addCmdAnalisis(CAnalisis comando){


}

void Torre_de_control::leerArchivoMovimiento(string filename){

  CMovimientos cm;
  string nombreArchivo = filename;
  string linea;
  ifstream archivo(nombreArchivo.c_str());
  
  if (!archivo.is_open()){
    cout <<"Error al abrir "<<filename;
  }else{

    if(sizeof(archivo)==0){
          	cout <<"Archivo"<<filename<<"vacio\n";
		  }else{

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

  }
    
}

void Torre_de_control::leerArchivoElementos(string filename){

  string nombreArchivo = filename;
    string linea;
    ifstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()){

    cout <<"Error al abrir "<<filename;
    return;
  }else{

    if(sizeof(archivo)==0){
      
      cout <<"Archivo"<<filename<<"vacio\n";
		}
    else{

      while (getline(archivo, linea)) {

        char *dup = strdup(linea.c_str());
        Elementos elm;

        elm.setTipo(strtok(dup," "));
        float sz = atof(strtok(NULL," "));
        elm.setSize(sz);
        elm.setUnidadm(strtok(NULL," "));
        float x = atof(strtok(NULL," "));
        float y = atof(strtok(NULL," "));

        elm.addCoords(x,y);

        this->elmnts.push_back(elm);
    }

    }
  }

  for(int i=0; i < this->elmnts.size(); i++){

    cout<<"tipo: "<<this->elmnts[i].getTipo();
    cout<<"size: "<<this->elmnts[i].getSize();
    cout<<"unidad de medida: "<<this->elmnts[i].getUnidadm();
    cout<<"coordenada en x: "<<this->elmnts[i].getCoordx();
    cout<<"coordenada en y: "<<this->elmnts[i].getCoordy();

  }

}

void Torre_de_control::guardarArchivoMovimiento(string filename){
    
    string nombreArchivo = filename;
    string temp;
    ofstream archivo;
		archivo.open(nombreArchivo.c_str(), fstream::out);
		  
      if (!archivo.is_open()){
          
          cout <<filename<<"no se encuentra o no puede leerse";

      }else{


        while(!this ->comnds_mov.empty()){
          
          temp = this->comnds_mov.front().getTipo();
          archivo << temp <<" ";
          temp = to_string(this->comnds_mov.front().getMagnitud());
          archivo << temp <<" ";
          temp = this->comnds_mov.front().getUnidadM();
          archivo << temp <<endl;

          this->comnds_mov.pop();
        
        }
      }

		archivo.close();

}

void Torre_de_control::guardarArchivoElementos(string filename){

   string nombreArchivo = filename;
    string temp;
    ofstream archivo;
		// Abrimos el archivo
		archivo.open(nombreArchivo.c_str(), fstream::out);
		 if (!archivo.is_open()){
           cout <<"Error al abrir "<<filename;
      }else{

      }
		archivo.close();

}

void Torre_de_control::simularComandosMov(string filename ){
    
    cout << "aaa" <<endl;
    
    
        
}

void Torre_de_control::simularComandosAnalisis(string filename){

}
