#ifndef _COMANDOS_H_
#define _COMANDOS_H_
#include <iostream>
#include "Torre_de_control.h"
using namespace std;

class Comandos{
	private:
		string nombre;
		Torre_de_control tc;

	public:
		Comandos();
		bool encontrarC();
		string getNombre();
		void setNombre(string nombre);

};

#include "Comandos.cxx"
#endif

