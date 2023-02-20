#ifndef COMANDOS_H
#define COMANDOS_H
#include <iostream>
using namespace std;

class Comandos{
	private:
		string nombre;
	public:
		Comandos();
		bool encontrarC();
		string getNombre();
		void setNombre(string nombre);

};

//#include "Comandos.cxx"
#endif

