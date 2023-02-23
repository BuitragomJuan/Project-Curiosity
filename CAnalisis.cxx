#include "CAnalisis.h"
#include <string>

using namespace std;

CAnalisis::CAnalisis(){

}

void CAnalisis::setTipo(string tp){

    this -> tipo = tp;
}

string CAnalisis::getTipo(){
    //return this ->tipo;
    return "pierce you're a bitch";
}

void CAnalisis::setObjeto(string obj){

    this -> objeto = obj;
}

string CAnalisis::getObjeto(){

    return this -> objeto;
}

void CAnalisis::setComentario(string cmnt){

    this -> comentario = cmnt; 
}

string CAnalisis::getComentario(){

    return this -> comentario;
}

