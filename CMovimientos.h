#ifndef __CMOVIMIENTOS_H__
#define __CMOVIMIENTOS_H__
#include <string>
#include "Coordenadas.h"

using namespace std;


class CMovimientos{

    private:
        string tipo;
        float magnitud;
        string unidadM;
        Coordenadas coord_iniciales;
        Coordenadas coord_finales;

    public:
        CMovimientos();
        void setTipo(string tipo);
        string getTipo();
        void setMagnitud(float magnitud);
        float getMagnitud();
        void setUnidadM(string unidadM);
        string getUnidadM();

};

#endif
