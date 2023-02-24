#ifndef __TORRE_DE_CONTROL_H__
#define __TORRE_DE_CONTROL_H__
#include <queue>
#include "CMovimientos.h"
#include "CAnalisis.h"
using namespace std;

class Torre_de_control{

    private:
        queue<CMovimientos> comnds_mov;
        queue<CAnalisis> comnds_an;

    public:
        Torre_de_control();
        void leerArchivoMovimiento(string filename);
        void leerArchivoElementos(string filename);
        bool guardarArchivoMovimiento(string filename,queue<string> name);
        bool guardarArchivoElementos(string filename,queue<string> name);
        void simularComandosMov(string filename);
        void simularComandosAnalisis(string filename);
        bool addCmdMovimiento( CMovimientos comando);
        bool addCmdAnalisis( CAnalisis comando);

};

#include "Torre_de_control.cxx"
#endif
