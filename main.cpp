#include<iostream>
#include "Comandos.h"
#include "Coordenadas.h"
#include "CMovimientos.h"
#include "CAnalisis.h"
#include "Torre_de_control.h"
#include<string.h>
#include <string>

using namespace std;

int main(int argc, char *argv[]){

    string ingresa;
    string comandos;
    string archivo;
    Comandos comi;
    bool seguir = false;

    do{
        cout <<endl;
        cout << "$" ;
        getline(cin.ignore(0), ingresa, '\n');

        comi.setNombre(ingresa);

        seguir = comi.encontrarC();
    
    }while(seguir);
    
    return 0;
}