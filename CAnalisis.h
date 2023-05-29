#ifndef __CANALISIS_H__
#define __CANALISIS_H__
#include <string>
using namespace std;

class CAnalisis{

    private:
        string tipo;
        string objeto;
        string comentario;
        
    public:
        CAnalisis();
        void setTipo(string tp);
        string getTipo();
        void setObjeto(string obj);
        string getObjeto();
        void setComentario(string cmn);
        string getComentario();

};

#include "CAnalisis.cxx"
#endif
