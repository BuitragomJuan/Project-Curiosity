#ifndef _NODOQUAD_H__
#define _NODOQUAD_H__
#include <iostream>

struct punto {
	int x;
	int y;
	punto& operator = (const punto &p) {
	x = p.x;
	y = p.y;
	return *this;
	}
	bool operator == (const punto &p) const {
	return (x == p.x && y == p.y);
	}
	friend std::ostream& operator << (std::ostream &o, const punto &p)
	{ o << "(" << p.x << "," << p.y << ")";
	return o;
	}
};
class NodoQuad {
	private:
		punto dato;
		NodoQuad* hijoSupIzq;
		NodoQuad* hijoSupDer;
		NodoQuad* hijoInfIzq;
		NodoQuad* hijoInfDer;
	public:
		NodoQuad();
		NodoQuad(punto val);
		~NodoQuad();
		punto obtenerDato();
		void fijarDato(punto val);
		NodoQuad* obtenerHijoSupIzq();
		NodoQuad* obtenerHijoSupDer();
		NodoQuad* obtenerHijoInfIzq();
		NodoQuad* obtenerHijoInfDer();
		void fijarHijoSupIzq(NodoQuad* sizq);
		void fijarHijoSupDer(NodoQuad* sder);
		void fijarHijoInfIzq(NodoQuad* iizq);
		void fijarHijoInfDer(NodoQuad* ider);
		bool esHoja();
};

#include "NodoQuad.cxx"
#endif

