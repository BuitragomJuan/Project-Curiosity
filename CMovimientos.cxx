#include "CMovimientos.h"
#include <string>
using namespace std;

CMovimientos::CMovimientos(){

}

void CMovimientos::setTipo(string type){

    this -> tipo = type;
}

string CMovimientos::getTipo(){

    return this -> tipo;
}

void CMovimientos::setMagnitud(float mag){

    this -> magnitud = mag;
}

float CMovimientos::getMagnitud(){

    return this -> magnitud;
}

void CMovimientos::setUnidadM(string unidadm){

    this -> unidadM = unidadm;
}

string CMovimientos::getUnidadM(){

    return this -> unidadM;
}

void CMovimientos::setCoordenadasIniciales(float x, float y){

}

void CMovimientos::setCoordenadasFinales(float x, float y){


}
