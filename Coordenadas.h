#ifndef __COORDENADAS_H__
#define __COORDENADAS_H__
using namespace std;

class Coordenadas{

    private:
        float coord_x;
        float coord_y;

    public:
        Coordenadas();
        float getCoord_x();
        float getCoord_y();
        void setCoord_x(float coord_x);
        void setCoord_y(float coord_y);

};

#include "Coordenadas.cxx"
#endif 