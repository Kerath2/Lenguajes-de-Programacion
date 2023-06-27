/*

 */

#include "Cliente.h"
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
Cliente::Cliente() {
    dni = 0;
    categoria = 0;
    nombre = nullptr; 
}

Cliente::Cliente(const Cliente& orig) {
}

Cliente::~Cliente() {
}

void Cliente::SetNombre(char* cad) {
    if(nombre!=nullptr)delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Cliente::GetNombre(char* cad) const {
    strcpy(cad,nombre);
}

void Cliente::SetCategoria(char categoria) {
    this->categoria = categoria;
}

char Cliente::GetCategoria() const {
    return categoria;
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

void Cliente::leeCliente(ifstream &arch){
    int dni;
    char nombre[100],categoria ,c;
    arch >> dni;
    if(arch.eof()) return;
    arch.get();
    arch.getline(nombre,100,',');
    arch >> categoria;
    
    this->dni = dni;
    SetNombre(nombre);
    this->categoria = categoria;
    
}
