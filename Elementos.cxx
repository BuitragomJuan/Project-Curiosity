#include "Elementos.h"

Elementos::Elementos(){


}

void Elementos::setTipo(string usrTP){

    this -> tipo = usrTP;
}

string Elementos::getTipo(){
    return this -> tipo;    
}

void Elementos::setSize(float usrSZ){

    this -> size = usrSZ;
}

float Elementos::getSize(){
    return this -> size;
}

void Elementos::addCoords(float x, float y){

    this -> coords.setCoord_x(x);
    this -> coords.setCoord_y(y);

}

