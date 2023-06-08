/*

 Gerardo Miguel Tacay Terrazos
 * codigo : 20193503
 */

#include "cita.h"

cita::cita() {
    dni = 0;
    codigo = 0;
    fecha= 0;
    tarifa = 0;
}

cita::cita(const cita& orig) {
}

cita::~cita() {
}

void cita::SetTarifa(double tarifa) {
    this->tarifa = tarifa;
}

double cita::GetTarifa() const {
    return tarifa;
}

void cita::SetFecha(int fecha) {
    this->fecha = fecha;
}

int cita::GetFecha() const {
    return fecha;
}

void cita::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int cita::GetCodigo() const {
    return codigo;
}

void cita::SetDni(int dni) {
    this->dni = dni;
}

int cita::GetDni() const {
    return dni;
}

