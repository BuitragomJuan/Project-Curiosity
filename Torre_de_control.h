#ifndef __TORRE_DE_CONTROL_H__
#define __TORRE_DE_CONTROL_H__
#include <queue>
#include <list>
#include <deque>
#include "CMovimientos.h"
#include "CAnalisis.h"
#include "Elementos.h"
#include "ArbolQuad.h"
#include "NodoQuad.h"

using namespace std;

class Torre_de_control{

    private:
        queue<CMovimientos> comnds_mov;
        queue<CAnalisis> comnds_an;
        deque<Elementos> elmnts;

    public:
        Torre_de_control();
        void leerArchivoComandos(string filename);
        void leerArchivoElementos(string filename);
        void guardarArchivoComandos(string filename);
        void guardarArchivoElementos(string filename);
        void simularComandosMov(float coordx, float coordy);
        void addCmdMovimiento(string tp, float mg, string um);
        void addCmdMovimiento(CMovimientos cm); //sobrecarga
        void addCmdAnalisis( string tp, string obj, string cm);
        void addCmdAnalisis(CAnalisis ca); //sobrecarga
        void addCmdElemento(string tp, float size, string um, float x, float y);
        void ubicarElementos();
        void enCuadrante(int co1, int co2, int co3, int co4); 

};

#include "Torre_de_control.cxx"
#endif
