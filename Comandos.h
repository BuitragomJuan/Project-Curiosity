#ifndef COMANDOS_H
#define COMANDOS_H
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

#endif

