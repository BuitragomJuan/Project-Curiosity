#ifndef __ELEMENTOS_H__
#define __ELEMENTOS_H__
#include <string>
#include "Coordenadas.h"
using namespace std;
class Elementos {

    private:
        string tipo;
        float size;
        Coordenadas coords;

    protected:
        Elementos();
        void setTipo(string usrTP);
        string getTipo();
        void setSize(float usrSZ);
        float getSize();
        void addCoords(float x, float y);

};


#endif