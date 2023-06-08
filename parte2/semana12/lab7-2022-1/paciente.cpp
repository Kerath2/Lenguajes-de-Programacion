/*
 * Gerardo Miguel Tacay Terrazos
 * codigo: 20193503
 */

#include "paciente.h"
#include <iostream>
#include <cstring>
paciente::paciente() {
}

paciente::paciente(const paciente& orig) {
}

paciente::~paciente() {
}

void paciente::SetTotalGastado(double totalGastado) {
    this->totalGastado = totalGastado;
}

double paciente::GetTotalGastado() const {
    return totalGastado;
}

void paciente::SetTelefono(int telefono) {
    this->telefono = telefono;
}

int paciente::GetTelefono() const {
    return telefono;
}

void paciente::SetNombre(char* cad) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
   
}

void paciente::GetNombre(char *cad) const {
    strcpy(cad,nombre);
}

void paciente::SetDni(int dni) {
    this->dni = dni;
}

int paciente::GetDni() const {
    return dni;
}

