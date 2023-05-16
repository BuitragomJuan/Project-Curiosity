#ifndef _ARBOLQUAD_H__
#define _ARBOLQUAD_H__
#include "NodoQuad.h"


class ArbolQuad{
	private :
		NodoQuad* root;
	public:
		ArbolQuad();
		ArbolQuad(punto val);
		~ArbolQuad();
		punto datoRaiz();
		NodoQuad* obtenerRaiz();
		void fijarRaiz(NodoQuad* n_raiz);
		bool esVacio();
		bool insertar(punto val,NodoQuad* nodo, NodoQuad* padre,int flag);
	/*	void preOrden();
		void inOrden();
		void posOrden();
		void nivelOrden();	*/	
		void preOrden(NodoQuad* node);
};

#include "ArbolQuad.cxx"
#endif
