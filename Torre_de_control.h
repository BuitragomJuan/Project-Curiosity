#ifndef __TORRE_DE_CONTROL_H__
#define __TORRE_DE_CONTROL_H__
#include <queue>
#include <list>
#include <deque>
#include "CMovimientos.h"
#include "CAnalisis.h"
#include "Elementos.h"
using namespace std;

class Torre_de_control{

    private:
        queue<CMovimientos> comnds_mov;
        queue<CAnalisis> comnds_an;
        deque<Elementos> elmnts;

    public:
        Torre_de_control();
        void leerArchivoMovimiento(string filename);
        void leerArchivoElementos(string filename);
        void guardarArchivoMovimiento(string filename);
        void guardarArchivoElementos(string filename);
        void simularComandosMov(string filename);
        void simularComandosAnalisis(string filename);
        void addCmdMovimiento( CMovimientos comando);
        void addCmdAnalisis( CAnalisis comando);

};

#include "Torre_de_control.cxx"
#endif
