#include "NodoQuad.h"

using namespace std;

NodoQuad::NodoQuad(){

	hijoSupIzq = NULL;
	hijoSupDer = NULL;
	hijoInfIzq = NULL;
	hijoInfDer = NULL;
	
}

NodoQuad::NodoQuad(punto val){
	dato = val;
    hijoSupIzq = NULL;
    hijoSupDer =  NULL;
    hijoInfIzq =  NULL;
    hijoInfDer =  NULL;
}

NodoQuad::~NodoQuad(){

	
}
		
punto NodoQuad::obtenerDato(){
	return this->dato;
}


void  NodoQuad::fijarDato(punto val){
	this->dato=val;
}
		
		
NodoQuad*  NodoQuad::obtenerHijoSupIzq(){
	return this->hijoSupIzq;
}

NodoQuad* NodoQuad::obtenerHijoSupDer(){
	return this->hijoSupDer;
}
		
NodoQuad* NodoQuad::obtenerHijoInfIzq(){
	return this->hijoInfIzq;
}
	
NodoQuad* NodoQuad::obtenerHijoInfDer(){
	return this->hijoInfDer;
}
		
void NodoQuad::fijarHijoSupIzq(NodoQuad* sizq){
	this->hijoSupIzq=sizq;
}
		
void NodoQuad::fijarHijoSupDer(NodoQuad* sder){
	this->hijoSupDer=sder;
}
		
void NodoQuad::fijarHijoInfIzq(NodoQuad* iizq){
	this->hijoInfIzq=iizq;
}
		
void NodoQuad::fijarHijoInfDer(NodoQuad* ider){
	this->hijoInfDer=ider;
}
		
bool NodoQuad::esHoja(){
	if(this->hijoSupIzq==NULL && this->hijoSupDer==NULL && this->hijoInfIzq==NULL&& this->hijoInfDer==NULL)
		return true;
	return false;
}
