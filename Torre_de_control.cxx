#include "Torre_de_control.h"
#include "CAnalisis.h"
#include "CMovimientos.h"
#include "Coordenadas.h"
#include <queue>
#include <iostream>

using namespace std;

Torre_de_control::Torre_de_control(){

    
}

bool Torre_de_control::addCmdMovimiento(CMovimientos comando){
    
    return true;

}

bool Torre_de_control::addCmdAnalisis(CAnalisis comando){

    return true;

}

void Torre_de_control::leerArchivoMovimiento(string filename){

}

void Torre_de_control::leerArchivoElementos(string filename){

    cout << filename;

}

bool Torre_de_control::guardarArchivoMovimiento(string filename){

    return true;

}

bool Torre_de_control::guardarArchivoElementos(string filename){

    return true;

}

void Torre_de_control::simularComandosMov(float coord_x, float coord_y){


}

void Torre_de_control::simularComandosAnalisis(string filename){

}
