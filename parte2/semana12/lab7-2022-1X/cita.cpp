/*

 Gerardo Miguel Tacay Terrazos
 * codigo : 20193503
 */

#include "cita.h"
#include "medico.h"

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

void cita::operator<=(medico *arrmed){
    int indice = -1;
    for (int i = 0 ; arrmed[i].GetCodigo();i ++){
        if(this->codigo == arrmed[i].GetCodigo())
            indice = i;
    }
    if(indice != -1){
        tarifa = arrmed[indice].GetTarifa();
    }

}

void cita::LlenaTarifa(medico *arrMedicos){
    for (int i = 0 ; arrMedicos[i].GetCodigo(); i++){
        if(codigo == arrMedicos[i].GetCodigo()){
            tarifa = arrMedicos[i].GetTarifa();
            break;
        } 
    }

}


ifstream & operator >>(ifstream &arch, cita&cita){
    int dni,codigo,fecha;
    int dd , mm ,aa;
    char c;
    arch >> dni;
    if(!arch.eof()){
        arch.get();
        arch >> codigo >> c;
        arch >> dd >> c >> mm >> c >> aa;
        fecha = aa * 10000 + mm * 100 + dd;

        cita.SetDni(dni);
        cita.SetCodigo(codigo);
        cita.SetFecha(fecha);

    }

    return arch;
}
