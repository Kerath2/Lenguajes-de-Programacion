/*
 * Gerardo Miguel Tacay Terrazos
 * codigo: 20193503
 */

#include "paciente.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
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

int paciente::ultimaCita() const{
    int cont = 0;
    for (int i = 0; lcitas[i].GetDni();i++) {
        cont++;
    }
    return cont;
}

void paciente::operator +=(cita &cit){
    lcitas[ultimaCita()].SetTarifa(cit.GetTarifa());
    lcitas[ultimaCita()].SetDni(cit.GetDni());
    lcitas[ultimaCita()].SetFecha(cit.GetFecha());
    lcitas[ultimaCita()].SetCodigo(cit.GetCodigo()); //codigo del medico
}

void paciente::operator ++(int a){
    int numCitas = ultimaCita();
    for (int i = 0 ; i < numCitas ;i++){
        totalGastado+= lcitas[i].GetTarifa();
    }
}
void paciente::imprimeCitas(ofstream &arch ){
    arch << "No" << " " << "FECHA" << " "<<"CODIGO DEL MEDICO" << " " << "TARIFA" << endl; 
    for (int i = 0 ; lcitas[i].GetDni() ; i++){
        arch << i+1 << ')' << " " << lcitas[i].GetFecha() << " " << lcitas[i].GetCodigo() << " "
            << lcitas[i].GetTarifa() << endl;
    }
}




ifstream & operator >>(ifstream &arch, paciente &pac){
    int dni;
    char nombre[100];
    int telefono;
    arch >> dni;
    if(!arch.eof()){
        arch.get();
        arch.getline(nombre,100,',');
        arch >> telefono;

        pac.SetDni(dni);
        pac.SetNombre(nombre);
        pac.SetTelefono(telefono);
    }

    return arch;
}

ofstream & operator <<(ofstream &arch, paciente &pac){
    arch << "DNI" << " " << " " << "TELEFONO" << endl; 
    char nombre[100];
    pac.GetNombre(nombre);
    arch  << pac.GetDni()<< " " << nombre << " " << pac.GetTelefono() << endl;
    arch << "RELACION DE CITAS" << endl;
    pac.imprimeCitas(arch);

    arch << "MONTO TOTAL GASTADO: " << pac.GetTotalGastado() << endl;

    for(int i = 0 ; i<100; i++) arch << "=";

    return arch;
}
