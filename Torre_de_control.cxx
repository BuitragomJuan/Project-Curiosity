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

void Torre_de_control::addCmdMovimiento(string tp, float mg, string um){
    
    CMovimientos cm;
    cm.setTipo(tp);
    cm.setMagnitud(mg);
    cm.setUnidadM(um);

    this->comnds_mov.push(cm);

}

void Torre_de_control::addCmdMovimiento(CMovimientos comando){
  this->comnds_mov.push(comando);
}

void Torre_de_control::addCmdAnalisis(string tp, string obj, string cm){

  CAnalisis ca;
  ca.setTipo(tp);
  ca.setObjeto(obj);
  ca.setComentario(cm);

  this->comnds_an.push(ca);

}

void Torre_de_control::addCmdAnalisis(CAnalisis ca){
  this->comnds_an.push(ca);
}

void Torre_de_control::leerArchivoComandos(string filename){

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
          char *tipo = strtok(dup, " ");

          if((strcmp("avanzar",(tipo))==0)||(strcmp("girar",(tipo))==0)){

            CMovimientos cm;

            cm.setTipo(tipo);
            float mag = atof(strtok(NULL, " "));
            cm.setMagnitud(mag);
            cm.setUnidadM(strtok(NULL, " "));

            this ->addCmdMovimiento(cm);

          }else if((strcmp("fotografiar",(tipo))==0)||(strcmp("composicion",(tipo))==0)||(strcmp("perforar",(tipo))==0)){

            CAnalisis ca;

            ca.setTipo(tipo);
            ca.setObjeto(strtok(NULL," "));
            ca.setComentario(strtok(NULL," "));

            this->addCmdAnalisis(ca);

          }else{cout<<"comando invalido en linea: "<<linea<<endl;}
        
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

void Torre_de_control::guardarArchivoComandos(string filename){
    
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

        while(!this->elmnts.empty()){

          temp = this->elmnts.front().getTipo();
          archivo << temp << " ";
          temp = to_string(this->elmnts.front().getSize());
          archivo << temp<<" ";
          temp = this->elmnts.front().getUnidadm();
          archivo << temp <<" ";
          temp = to_string(this->elmnts.front().getCoordx());
          archivo << temp << " ";
          temp = to_string(this->elmnts.front().getCoordy());
          archivo << temp<<endl; 

          elmnts.pop_front();
        }

      }
		archivo.close();

}

void Torre_de_control::simularComandosMov(string filename ){
    
    cout << "aaa" <<endl;
        
}

void Torre_de_control::addCmdElemento(string tp, float sz, string um, float x, float y){

  Elementos lm;

  lm.setTipo(tp);
  lm.setSize(sz);
  lm.setUnidadm(um);
  lm.addCoords(x,y);

  this->elmnts.push_back(lm);

}