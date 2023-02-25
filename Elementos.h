#ifndef __ELEMENTOS_H__
#define __ELEMENTOS_H__
#include <string>
#include "Coordenadas.h"
using namespace std;
class Elementos {

    private:
        string tipo;
        float size;
        string unidadM;
        Coordenadas coords;

    public:
        Elementos();
        void setTipo(string usrTP);
        string getTipo();
        void setSize(float usrSZ);
        float getSize();
        void addCoords(float x, float y);
        float getCoordx();
        float getCoordy();
        void setUnidadm(string unim);
        string getUnidadm();

};

#include "Elementos.cxx"
#endif