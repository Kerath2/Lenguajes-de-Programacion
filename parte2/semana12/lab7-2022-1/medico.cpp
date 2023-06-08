/*
 
 Gerardo Miguel Tacay Terrazos
 * codigo : 20193503
 
 */
#include <iostream>
#include <cstring>
#include "medico.h"

medico::medico() {
    codigo = 0;
    nombre = nullptr;
    tarifa = 0;
}

medico::medico(const medico& orig) {
}

medico::~medico() {
    delete nombre;
}

void medico::SetTarifa(double tarifa) {
    this->tarifa = tarifa;
}

double medico::GetTarifa() const {
    return tarifa;
}

void medico::SetNombre(char* cad) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void medico::GetNombre(char *cad) const {
    strcpy(cad,nombre);
}

void medico::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medico::GetCodigo() const {
    return codigo;
}


ifstream & operator >>(ifstream &arch, medico med){
    int codigo;
    char nombre[100];
    double tarifa;

    arch >> codigo;
    if(!arch.eof()){
        arch.get();
        arch.getline(nombre,100,',');
        arch >> tarifa;

        med.SetCodigo(codigo);
        med.SetNombre(nombre);
        med.SetTarifa(tarifa);
    }

    return arch;
}
