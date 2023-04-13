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
# define M_PI           3.14159265358979323846  /* pi */

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


enum unidades{mm,cm,dc,m,dam,dm};
void Torre_de_control::simularComandosMov(float coordx, float coordy){

  //posiciones actuales del robot
	float posactx=coordx;
	float posacty=coordy;
	float posfinx;
	float posfiny;
	float grados=0;
	float magInter;
	CMovimientos comandoact;
	unidades uni;

	while(!(this->comnds_mov.empty())){
    
    comandoact = this->comnds_mov.front();
    
    if(strcmp("avanzar",comandoact.getTipo().c_str())==0){ 
      
      if(strcmp("mm",comandoact.getUnidadM().c_str())==0)
        uni=mm;
        
      if(strcmp("cm",comandoact.getUnidadM().c_str())==0)
        uni=cm;
      if(strcmp("m",comandoact.getUnidadM().c_str())==0)
		    uni=m;
	    if(strcmp("dam",comandoact.getUnidadM().c_str())==0)
		    uni=dam;

	    switch(uni){
			    
        case mm:
				  magInter=comandoact.getMagnitud()/1000;
				  break;
			  case cm:
					magInter=comandoact.getMagnitud()/100;
				  break;
			  case dm:
					magInter=comandoact.getMagnitud()/10;
				  break;
			  case m:
				  magInter=comandoact.getMagnitud();
				  break;
			  case dam:
					magInter=comandoact.getMagnitud()*10;
				  break;
		  }

	}
	else{

		if(strcmp("grados",comandoact.getUnidadM().c_str())==0)
		  grados=comandoact.getMagnitud()*M_PI/180;	
	}

	posfinx=(magInter*cos(grados)) + posactx;
	posfiny=(magInter*sin(grados)) + posacty;

  this->comnds_mov.pop();
	
  }

  cout<<"posicion en x final es "<<posfinx<<endl;
	cout<<"posicion en y final es "<<posfiny<<endl;  
        
}

void Torre_de_control::addCmdElemento(string tp, float sz, string um, float x, float y){

  Elementos lm;

  lm.setTipo(tp);
  lm.setSize(sz);
  lm.setUnidadm(um);
  lm.addCoords(x,y);

  this->elmnts.push_back(lm);

}

void Torre_de_control::ubicarElementos(){

  ArbolQuad* arbol = new ArbolQuad();
  punto coord;
  deque<Elementos> lm_aux = this->elmnts;
  NodoQuad* root = new NodoQuad();

  Elementos raiz = lm_aux.front();
  lm_aux.pop_front();
  

  coord.x = raiz.getCoordx();
  coord.y = raiz.getCoordy();

  root->fijarDato(coord);
  arbol->fijarRaiz(root);

  deque<Elementos>::iterator it_aux;

  for(it_aux = lm_aux.begin(); it_aux != lm_aux.end(); it_aux++){
  
    NodoQuad* node = new NodoQuad();
    Elementos lm = (*it_aux);
    punto info;

    info.x = lm.getCoordx();
    info.y = lm.getCoordy();
    
    node->fijarDato(info);
    arbol->insertar(arbol->obtenerRaiz()->obtenerDato(), node, arbol->obtenerRaiz(),0);

  } 

  this->setArbolElementos(arbol);

}

					// x 		  y
void Torre_de_control::enCuadrante(int co1,int co2,int co3,int co4,NodoQuad* nodo){
  
	if (co1>co2 ||co3 >co4){
		cout<<"formato incorrecto"<<endl;
	}
	else{
		
	 	if(nodo!=NULL){
			 int nodo_x = nodo->obtenerDato().x;
		        int nodo_y = nodo->obtenerDato().y;
        		cout<<nodo->obtenerDato()<<endl;
        
				if (co1 < nodo_x && co3 < nodo_y ) {
           				if(co2 > nodo_x && co4 > nodo_y){
						
						enCuadrante(co1,co2,co3,co4,nodo->obtenerHijoSupDer());
					}
       				 } 
				if (co1 < nodo_x && co3 < nodo_y ) {
           				if(co2 > nodo_x && co4 > nodo_y){
					  	
						enCuadrante(co1,co2,co3,co4,nodo->obtenerHijoSupIzq());
					}
        			} 
				if (co1 < nodo_x && co3 < nodo_y ) {
           				if(co2 > nodo_x && co4 > nodo_y){
						 
						enCuadrante(co1,co2,co3,co4, nodo->obtenerHijoInfIzq());
					}
        			} 
				if (co1 < nodo_x && co3 < nodo_y ) {
           				if(co2 > nodo_x && co4 > nodo_y){
						 
						enCuadrante(co1,co2,co3,co4,nodo->obtenerHijoInfDer());
					}
        			} 
		}
	}



}


void Torre_de_control::setArbolElementos(ArbolQuad* tree){
  this->arbolElementos = tree;

}

ArbolQuad* Torre_de_control::getArbolElementos(){
  return this->arbolElementos;
}
