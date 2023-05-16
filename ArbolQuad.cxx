#include "ArbolQuad.h"

using namespace std;

ArbolQuad::ArbolQuad(){
	
}
//	ArbolQuad(punto val);
ArbolQuad::~ArbolQuad(){
	
}
	
punto ArbolQuad::datoRaiz(){
 	return this->root->obtenerDato();
	
}

NodoQuad* ArbolQuad::obtenerRaiz(){
	return this->root;
}

void ArbolQuad::fijarRaiz(NodoQuad* n_raiz){
	this->root= n_raiz;//revisar
}
bool ArbolQuad::esVacio(){
	if(this->root->obtenerHijoInfDer()== NULL && this->root->obtenerHijoInfIzq()==NULL && this->root->obtenerHijoSupDer()==NULL&& this->root->obtenerHijoSupIzq()== NULL   )
		return true;//si es vacio
	return false;//no es vacio
}
bool ArbolQuad::insertar(punto val,NodoQuad* nodo,NodoQuad* padre, int flag){
		
    if (nodo == NULL) {
        nodo = new NodoQuad(val);
		
		switch (flag)
		{
		case 1:
			padre->fijarHijoSupDer(nodo);
			break;
		case 2:
			padre->fijarHijoSupIzq(nodo);
			break;
		case 3:
			padre->fijarHijoInfIzq(nodo);
			break;
		case 4:
			padre->fijarHijoInfDer(nodo);
			break;
		}
        return true;}
	else if (nodo->obtenerDato() == val) {
        return false; // El punto ya existe en el arbol
    } 
	else {
        int nodo_x = nodo->obtenerDato().x;
        int nodo_y = nodo->obtenerDato().y;
        int val_x = val.x;
        int val_y = val.y;
        
        if (val_x > nodo_x && val_y > nodo_y) {
            return ArbolQuad::insertar(nodo->obtenerDato(), nodo->obtenerHijoSupDer(), padre,1);
        } 
		else if (val_x < nodo_x && val_y > nodo_y) {
            return ArbolQuad::insertar(nodo->obtenerDato(), nodo->obtenerHijoSupIzq(),padre,2);
        } 
		else if (val_x < nodo_x && val_y < nodo_y) {
            return ArbolQuad::insertar(nodo->obtenerDato(), nodo->obtenerHijoInfIzq(),padre,3);
        } 
		else if (val_x > nodo_x && val_y < nodo_y) {
            return ArbolQuad::insertar(nodo->obtenerDato(), nodo->obtenerHijoInfDer(),padre,4);
        } 
		else {
            return false;
        }
    }

}

void ArbolQuad::preOrden(NodoQuad* node){

	cout << node->obtenerDato()<<" ";

	if(node->obtenerHijoSupIzq() != NULL){
		return this->preOrden(node->obtenerHijoSupIzq());
		
	}if(node->obtenerHijoSupDer() != NULL){
		return this->preOrden(node->obtenerHijoSupDer());
		
	}if(node->obtenerHijoInfIzq() != NULL){
		return this->preOrden(node->obtenerHijoInfIzq());
		
	}if(node->obtenerHijoInfDer() != NULL){
		return this->preOrden(node->obtenerHijoInfDer());
		
	}
	
}