/*
 * Gerardo Miguel Tacay Terrazos
 * codigo: 20193503
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funcionesConTipo.h"

using namespace std;

void *leeentero(ifstream &arch){
    int cod;
    char car,*nombre;
    arch >> cod;
    if(arch.eof()) return nullptr;
    int *codigo = new int;
    *codigo = cod;
    arch >> car;
    leerCadena(arch,nombre);
    return codigo;
}

void leerCadena(ifstream &arch, char *&cad){
    char buff[200];
    arch.getline(buff,200);
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
}

int cmpentero(void *a , void*b){
    return 1;
}