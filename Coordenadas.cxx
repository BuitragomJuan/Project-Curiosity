#include "Coordenadas.h"
#include <iostream>
#include <string>
using namespace std;

Coordenadas::Coordenadas(){
    
}

void Coordenadas::setCoord_x(float coord_x){

    cout << "el numero a imprimir es: " << coord_x;
    //this -> coord_x = coord_x;
}

void Coordenadas::setCoord_y(float coord_y){

    this -> coord_y = coord_y;
}

float Coordenadas::getCoord_x(){

    return this -> coord_x;
}

float Coordenadas::getCoord_y(){

    return this -> coord_y;
}

